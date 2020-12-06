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
    if (isButtonClicked) {
        isButtonClicked = false;
        QString buffer;

        QDataStream sock_stream(socket);
        sock_stream.setVersion(QDataStream::Qt_5_15);

        for(;;) {

            sock_stream.startTransaction();
            sock_stream >> buffer;

            if (!sock_stream.commitTransaction()) {
                break;
            } else {
                MessageProtocol message(buffer);
                if (message.isValid()) {
                    if (!message.getMessage().contains("/hello")) {
                        addToLog(message.getReceiverUser() + ": " + message.getMessage(), Qt::blue);
                    }
                } else {
                    displayError("Incorrect Data!!!");
                }
            }
        }
    }
    return;
}

void Dialog::on_pbt_Send_clicked() {
    if (socket) {
        if (socket->isOpen()) {

            isButtonClicked = true;

            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QString textFromInput = ui->message_Edit->text();

            // Это всего лишь пример, пока авторизация не сделана
            MessageProtocol message(1, "Sergey", "Artem", textFromInput, 2, 1);
//            MessageProtocol message(1, "Artem", "Sergey", textFromInput, 1, 2);
            qDebug() << socket->socketDescriptor();

            if (message.isValid()) {
                QString messageTosent;

                message.convert(messageTosent);
                socketStream << messageTosent;

                socket->flush();
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
