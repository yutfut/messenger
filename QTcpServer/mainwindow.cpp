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
    if (!tcp_Server->listen(QHostAddress::Any, 1234) && server_status==0) {
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
        foreach(int i,SClients.keys()){
            QTextStream os(SClients[i]);
            os.setAutoDetectUnicode(true);
            os << QDateTime::currentDateTime().toString() << "\n";
            SClients[i]->close();
            SClients.remove(i);
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
        SClients[idusersocs]=clientSocket;
        connect(SClients[idusersocs],SIGNAL(readyRead()),this, SLOT(slotReadClient()));
    }
}

void MainWindow::slotReadClient()
{
    clientSocket = (QTcpSocket*)sender();

    QString name;

    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_15);

    in >> name;

    MessageProtocol message(name);
    if (message.isValid()) {

        ui->textinfo->append("ReadClient:"+QDateTime::currentDateTime().toString()+"\t"+name+"\n\r");

        if (!QString::compare(message.getMessage(), "/exit", Qt::CaseInsensitive)) {// Если нужно закрыть сокет
            clientSocket->close();
            qDebug() << QString::fromUtf8("Клиент отключился!");
            ui->textinfo->append(QString::fromUtf8("Клиент отключился!"));
        } else {
            QDataStream out(clientSocket);
            out << name;
        }

        QTextStream os(_sok);
        os.setAutoDetectUnicode(true);
        os << "HTTP/1.0 200 Ok\t" << QDateTime::currentDateTime().toString()+"\t"+name+"\n";
        ui->textinfo->append("ReadClient:"+QDateTime::currentDateTime().toString()+"\t"+name+"\n");
    } else {
        ui->textinfo->append(QString::fromUtf8("Сообщение не получено!"));
    }
}
