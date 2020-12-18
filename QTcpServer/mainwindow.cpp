#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../lib/headers/message_protocol.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    _sok = new QTcpSocket(this);
    tcp_Server = new QTcpServer();

}

MainWindow::~MainWindow() {
    delete ui;
    server_status=0;
    clientSocket->close();

    delete clientSocket;
}

//<<<<<<< HEAD
/*void MainWindow::on_starting_clicked()
{
    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newuser()));
    if (!tcpServer->listen(QHostAddress("192.168.1.64"), 6000) && server_status==0) {
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer->errorString());
        ui->textinfo->append(tcpServer->errorString());

*/
void MainWindow::on_starting_clicked() {
    connect(tcp_Server, SIGNAL(newConnection()), this, SLOT(newuser()));
    connect(this, &MainWindow::sendMessage,this, &MainWindow::sendTouser);

    if (!tcp_Server->listen(QHostAddress::Any, 8000) && server_status==0) {
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcp_Server->errorString());
        ui->textinfo->append(tcp_Server->errorString());
    } else {
        server_status=1;
        qDebug() << tcp_Server->isListening() << "TCPSocket listen on port";
        ui->textinfo->append(QString::fromUtf8("Сервер запущен!"));
        qDebug() << QString::fromUtf8("Сервер запущен!");
    }
}

void MainWindow::on_stoping_clicked() {
    if(server_status==1){
        for(int i = 0; i < SClients.size(); ++i){
            QTextStream os(SClients[i].clientSocket);
            os.setAutoDetectUnicode(true);
            os << QDateTime::currentDateTime().toString() << "\n";
            SClients[i].clientSocket->close();
            SClients.removeAt(i);
        }
        tcp_Server->close();
        ui->textinfo->append(QString::fromUtf8("Сервер остановлен!"));
        qDebug() << QString::fromUtf8("Сервер остановлен!");
        server_status=0;
    }
}

void MainWindow::newuser() {
    if(server_status==1){
        qDebug() << QString::fromUtf8("У нас новое соединение!");
        ui->textinfo->append(QString::fromUtf8("У нас новое соединение!"));
        clientSocket=tcp_Server->nextPendingConnection();

        //  Сигнал
        connect(clientSocket,SIGNAL(readyRead()),this, SLOT(slotReadClient()));
    }
}

void MainWindow::slotReadClient()
{
    clientSocket = reinterpret_cast<QTcpSocket*>(sender());

    //  Данная переменная осуществляет получение сообщения от текущего клиента
    QString messageFromclient;

    // Открываем поток
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_15);

    // Бесконечным циклом прогоняем до тех пор, пока есть сообщения на сокете
    for(;;) {
        in.startTransaction();
        in >> messageFromclient;

        if (in.commitTransaction()) {
            MessageProtocol message(messageFromclient);

            if (message.isValid()) {
                ui->textinfo->append("ReadClient:"+QDateTime::currentDateTime().toString()+"\t"+messageFromclient+"\n\r");

                // Добавление пользователей в БД
                int userId = addUsertodatabase(message);
                message.setUserId(userId);

                // Добавляем сообщение в общий диалог
                int dialogId = message.getDialogId();
                if (dialogId == -1) {
                    // Если такого dialogID не существует, то проектируем его
                    std::vector<int> members = {userId};
                    dialogId = dialogManager.create_dlg(userId, members);
                    message.setDialogId(dialogId);
                } else {
                    //  Получаем список юзеров, которые состоят в одном диалоге
                    state = dialogManager.get_users_in_dlg(dialogId);

                    // Убираем значения, которые уже попадались в вектор
                    std::sort(state.begin(), state.end());
                    state.erase(std::unique(state.begin(), state.end()), state.end());
                    qDebug() << userId << dialogId << state;

                    // Если список юзеров пустой, то диалога нет и его надо создать
                    if (!state.size()) {
                        std::vector<int> members = {userId};

                        dialogId = dialogManager.create_dlg(userId, members);
                        message.setDialogId(dialogId);

                    // Иначе смотрим и добавляем нового юзера, если его нет в списке
                    } else {
                        // Есть ли юзер уже в конкретном диалоге
                        bool isUserInData = false;
                        for(size_t i = 0; i < state.size(); ++i) {
                            if (state[i] == userId) {
                                // Если есть, то тогда мы его не включаем
                                isUserInData = true;
                                break;
                            }
                        }
                        qDebug() << "0 here";
                        if (!isUserInData) {
                            // Иначе включаем, если его нет в списке
                            std::vector<int> member = {userId};
                            dialogManager.add_members(dialogId, member);
                        }
                    }
                }

                // Метод, осуществляющий добавление сообщения в базу
                addMessagetodatabase(message, userId, dialogId);

                // Специальный код, позволяющий завершить диалог и отключиться от сокета
                if (!QString::compare(message.getMessage(), "/exit", Qt::CaseInsensitive)) {
                    clientSocket->close();
                    qDebug() << QString::fromUtf8("Клиент отключился!");
                    ui->textinfo->append(QString::fromUtf8("Клиент отключился!"));

                // Если к нам пришло простое hello-сообщение (оно придёт при вызове), то добавляем юзера в списое доступных юзеров
                } else if (!QString::compare(message.getMessage(), "/hello", Qt::CaseInsensitive)) {
                    // Формируем новую структуру
                    int sockDescr = clientSocket->socketDescriptor();
                    userAtserver newUser = {message.getSenderId(), sockDescr, clientSocket};
                    SClients.push_back(newUser);

                    // Новые изменения
                    auto textsMessages = messageManager.get_messages(dialogId,messageManager.getMessageId(), 10);
                    sendMessageNewUser(message, textsMessages, clientSocket);

                    qDebug() << "New user:"<<message.getSenderId();
                } else if (!QString::compare(message.getMessage(), "/bye", Qt::CaseInsensitive)) {
                      // Удаляем юзера из списка активных пользователей
                    size_t i = 0;
                    for(i = 0; i < state.size(); ++i) {
                        // Поиском сравниваем список
                        if (SClients[i].userId == message.getSenderId()) {
                            break;
                        }
                    }

                    // Убираем его
                    SClients.removeAt(i);

                    emit sendMessage(message);
                } else {
                    emit sendMessage(message);
                }

                ui->textinfo->append("ReadClient:"+QDateTime::currentDateTime().toString()+"\t"+messageFromclient+"\n");
            } else {
                ui->textinfo->append(QString::fromUtf8("Сообщение не получено!"));
            }
        } else {
            break;
        }
    }
}

//Метод отправляет сообщение конкретному юзеру (юзерам)
void MainWindow::sendTouser(MessageProtocol &message) {
    // Отправитель
    bool isFound = false;
    int senderId = message.getSenderId();

    for(size_t i = 0; i < state.size(); ++i) {
        if (state[i] != -1 && state[i] != senderId) {
            // Отправка конкретному юзеру
            QString m = message.convert();

            int j = 0;
            for(j = 0; j < SClients.size(); ++j) {
                if (SClients[j].userId == state[i]) {
                    isFound = true;
                    break;
                }
            }

            if (!isFound) {
                continue;
            }

            QDataStream out(SClients[j].clientSocket);
            out.setVersion(QDataStream::Qt_5_15);
            out << m;
        } else if (state[i] == senderId) {
            continue;
        } else {
            qDebug() << "Невозможно отправить сообщение!!!";
        }
    }

    // Если пользователь в сети, то ему отправилось сообщение, мы же отправляем сендеру его сообщение
    if (isFound) {
        // Формируем специальное серверное сообщение
        MessageProtocol readingMessage(message.getDialogId(), "server", "@server", "/reading");

        // Отправляем специальный месседж, что сообщение было доставлено получателю
        QDataStream out(clientSocket);
        QString readingMess = readingMessage.convert();
        out << readingMess;
    }
}

// Если у нас новый юзер, то отгружаем ему последние 10 сообщений
void MainWindow::sendMessageNewUser(MessageProtocol &protocol, std::vector<Message> messages, QTcpSocket *userSocket) {
    for(size_t i = 0; i < messages.size(); ++i) {
        QString message = QString::fromStdString(messages[i].text);
        QString senderUser = QString::fromStdString(userManager.get_user(messages[i].sender_id).name);
        QString time = QString::fromStdString(messages[i].time);

        protocol.setMessage(message);
        protocol.setUserId(messages[i].sender_id);
        protocol.setSenderUser(senderUser);
        protocol.setDialogId(messages[i].dialog_id);
        protocol.setTime(time);

        QDataStream out(userSocket);
        message = protocol.convert();
        out << message;
    }
}

// Метод обавляет пользователя в БД
int MainWindow::addUsertodatabase(MessageProtocol &messageProtocol) {
    // Никнейм + имя
    std::string login = messageProtocol.getNickname().toStdString();
    std::string name = messageProtocol.getSenderUser().toStdString();

    // Формируем юзера
    User user = userManager.get_user(login);
    if (user.login.compare(login)) {
        // Добавляем юзера в БД
        userManager.create_user(name, login);

        // Возвращаем его ID
        return userManager.get_user(login).id;
    }

    // Если юзер уже есть в БД, то нам ничего делать не нужно, просто возвращаем его ID
    return user.id;
}

// Метод добавляет сообщение в БД
int MainWindow::addMessagetodatabase(MessageProtocol &messageProtocol, int userID, int &dialogID) {
    int messageId = messageManager.getMessageId();
    auto textMessage = messageProtocol.getMessage();
    if (textMessage.compare("/hello") || textMessage.compare("/bye")) {
        Message message = {messageId, userID, dialogID, messageProtocol.getMessage().toStdString(),
                          QTime::currentTime().toString().toStdString()};
        messageManager.post_message(message);
    }
    return 0;
}
