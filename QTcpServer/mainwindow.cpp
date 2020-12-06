#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../lib/headers/message_protocol.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _sok = new QTcpSocket(this);
    tcp_Server = new QTcpServer();

}

MainWindow::~MainWindow()
{
    delete ui;
    server_status=0;
    clientSocket->close();

    delete clientSocket;
}

void MainWindow::on_starting_clicked()
{
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

void MainWindow::on_stoping_clicked()
{
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


void MainWindow::newuser()
{
    if(server_status==1){
        qDebug() << QString::fromUtf8("У нас новое соединение!");
        ui->textinfo->append(QString::fromUtf8("У нас новое соединение!"));
        QTcpSocket* clientSocket=tcp_Server->nextPendingConnection();
        int idusersocs=clientSocket->socketDescriptor();

        userAtserver newUser = {idusersocs, clientSocket, 0};

        SClients.push_back(newUser);

        connect(clientSocket,SIGNAL(readyRead()),this, SLOT(slotReadClient()));

    }
}

void MainWindow::slotReadClient()
{
    clientSocket = reinterpret_cast<QTcpSocket*>(sender());

    QString messageFromclient;

    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_15);

    for(;;) {
        in.startTransaction();
        if (clientSocket->bytesAvailable() < static_cast<int>(quint16())) {
            break;
        }
        in >> messageFromclient;

        if (in.commitTransaction()) {
            MessageProtocol message(messageFromclient);
            if (message.isValid()) {

                ui->textinfo->append("ReadClient:"+QDateTime::currentDateTime().toString()+"\t"+messageFromclient+"\n\r");

                if (!QString::compare(message.getMessage(), "/exit", Qt::CaseInsensitive)) {// Если нужно закрыть сокет
                    clientSocket->close();
                    qDebug() << QString::fromUtf8("Клиент отключился!");
                    ui->textinfo->append(QString::fromUtf8("Клиент отключился!"));
                } else {
                    emit sendMessage(message, messageFromclient);
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

void MainWindow::sendTouser(MessageProtocol &message, QString &messageFromclient) {
    int receiverId = message.getSenderId() - 1;
    if (receiverId >=0 && receiverId < SClients.size()) {
        QDataStream out(SClients[receiverId].clientSocket);
        out.setVersion(QDataStream::Qt_5_15);
        out << messageFromclient;
    }
}

