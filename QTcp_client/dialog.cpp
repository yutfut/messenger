#include "dialog.h"
#include "ui_dialog.h"
#include "../lib/headers/message_protocol.h"

#include <QtGui>
#include <QDebug>


Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog) {
    ui->setupUi(this);

    disableButtons(true);

    socket = new QTcpSocket(this);
    isButtonClicked = false;

    //  В дальнейшем надо эти данные хранить в спец-файле (JSON)
    userId = -1;
    dialogId = -1;

    connect(socket, &QTcpSocket::readyRead, this, &Dialog::onSokReadyRead);
    connect(socket, &QTcpSocket::connected, this, &Dialog::onSokConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Dialog::onSokDisconnected);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

Dialog::~Dialog() {
    socket->close();

    delete socket;
    delete ui;
}

void Dialog::onSokDisplayError(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError: {
        displayError("The host was not found");
        break;
    }
    case QAbstractSocket::ConnectionRefusedError: {
        displayError("The connection was refused by the peer");
        break;
    }
    default:
        displayError("The following error occured: " + socket->errorString());
    }
}

void Dialog::onSokReadyRead() {
        QString buffer;

        QDataStream sock_stream(socket);
        sock_stream.setVersion(QDataStream::Qt_5_15);

        for(;;) {
            sock_stream.startTransaction();
            sock_stream >> buffer;
            qDebug() << buffer;

            if (!sock_stream.commitTransaction()) {
                break;
            } else {
                MessageProtocol message(buffer);
                if (userId == -1) {
                    userId = message.getSenderId();
                }

                if (dialogId == -1) {
                    dialogId = message.getDialogId();
                }

                if (message.isValid()) {
                    if (!message.getMessage().contains("/hello")) {
                        addToLog(message.getSenderUser() + ": " + message.getMessage(), Qt::blue);
                    }
                } else {
                    displayError("Incorrect Data!!!");
                }
            }
        }
    return;
}

void Dialog::on_pbt_Send_clicked() {
    if (socket) {
        if (socket->isOpen()) {
            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QString textFromInput = ui->message_Edit->text();

            // Это всего лишь пример, пока авторизация не сделана
//            MessageProtocol message(0, "Sergey", "@yut_fut", textFromInput, 1);
            MessageProtocol message(dialogId, "Artem", "@bus_artem", textFromInput, userId);

            if (message.isValid()) {
                addFile(message);
                QString messageTosent;

                messageTosent = message.convert();
                socketStream << messageTosent;
                qDebug() << socket->socketDescriptor();

                addToLog(message.getSenderUser() + ": " + message.getMessage(), Qt::yellow);
            } else {
                displayError("Incorrect Data!!!");
            }

            ui->message_Edit->clear();
            disableButtons(true, false);

        } else {
            displayError("Socket can't send message");
        }
    } else {
        displayError("Socket can't connect to server");
    }
}

void Dialog::onSokConnected() {
    ui->pbConnect->setEnabled(false);
    ui->pbDisconnect->setEnabled(true);
    addToLog("Connected to"+socket->peerAddress().toString()+":"+QString::number(socket->peerPort()),Qt::green);

    disableButtons(true, false);
}

void Dialog::onSokDisconnected() {
    ui->pbConnect->setEnabled(true);
    ui->pbDisconnect->setEnabled(false);
    addToLog("Disconnected from"+socket->peerAddress().toString()+":"+QString::number(socket->peerPort()), Qt::green);

    disableButtons(true);
}

void Dialog::on_pbConnect_clicked() {
    socket->connectToHost(QHostAddress::LocalHost, 8000);
}

void Dialog::on_pbDisconnect_clicked() {
    socket->disconnectFromHost();
}

void Dialog::displayError(const QString &error) {
    addToLog(error, Qt::red);
    QMessageBox::critical(this, "Client error!", error);
}

void Dialog::disableButtons(const bool state, const bool state_2) {
    ui->pbt_Send->setDisabled(state);
    ui->message_Edit->setDisabled(state_2);
}

void Dialog::addFile(MessageProtocol &protocol) {
    QString path = "../test.txt";
    QByteArray data;

    QFile file(path);
    QList<QPair<QString, QByteArray>> info;

    qDebug() << "I am here\n";

    if (file.open(QIODevice::ReadOnly)) {
        data = file.readAll();
        info.push_back(qMakePair(path, data));
        protocol.setFile(info);
    }
}

void Dialog::addToLog(QString text, QColor color) {
    QString message = QString(QTime::currentTime().toString() + " " + text);

    ui->lwLog->setTextColor(color);
    ui->lwLog->append(message);
}

void Dialog::on_message_Edit_textEdited(const QString &arg1) {
    if (arg1.length()) {
        disableButtons(false, false);
    } else {
        ui->pbt_Send->setDisabled(true);
    }
}
