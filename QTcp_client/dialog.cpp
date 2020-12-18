#include "dialog.h"
#include "ui_dialog.h"
#include "../lib/headers/message_protocol.h"

#include <QtGui>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog) {
    ui->setupUi(this);

    disableButtons(true);

    socket = new QTcpSocket(this);
    stateRecord = false;

    //  В дальнейшем надо эти данные хранить в спец-файле (JSON)
    userId = 1;
    dialogId = 1;

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

QTcpSocket *Dialog::getSocket() {
    return socket;
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
                    QString textMessage = message.getMessage();
                    if (textMessage.contains("/reading")) {
                        // Здесь надо реализовать фичу получения юзера
                        addToLog("Прочитано", message.getTime(), Qt::gray);
                        ui->userStatus->setText("В сети");
                    } else if (textMessage.contains("/bye")) {
                        ui->userStatus->setText("Не в сети");
                    } else if (!textMessage.contains("/hello")) {
                        addToLog(message.getSenderUser() + ": " + message.getMessage(), message.getTime(), Qt::blue);
                    }

                    if (message.isFilesInMessage()) {
                        filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
                        saveFiles(message, filePath);
                        message.removeFiles();
                        filePath = "";
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
//            MessageProtocol message(dialogId, "Andrey", "@und_dayk", textFromInput, 3);
            MessageProtocol message(dialogId, "Sergey", "@yut_fut", textFromInput, 2);
//            MessageProtocol message(dialogId, "Artem", "@bus_artem", textFromInput, 1);

            if (message.isValid()) {
                if (filePath.size()) {
                    addFile(message, filePath);
                    filePath = "";
                }

                QString messageTosent;
                messageTosent = message.convert();

                socketStream << messageTosent;
                addToLog(message.getSenderUser() + ": " + message.getMessage(), message.getTime(), Qt::blue);
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

void Dialog::on_attachmentBtn_clicked() {
    filePath = QFileDialog::getOpenFileName(this, ("Выберите файл"), QStandardPaths::writableLocation(QStandardPaths::AppDataLocation),
                                            ("FILE (*.*)"));
}

void Dialog::onSokConnected() {
    QString message = "/hello";
    sendServiceMessage(message);

    disableButtons(true, false);
    ui->lwLog->clear();
    addToLog("Connected to"+socket->peerAddress().toString()+":"+QString::number(socket->peerPort()),
             QTime::currentTime().toString(), Qt::green);
}

void Dialog::onSokDisconnected() {
    ui->pbConnect->setEnabled(true);
    ui->pbDisconnect->setEnabled(false);
    addToLog("Disconnected from"+socket->peerAddress().toString()+":"+QString::number(socket->peerPort()),
             QTime::currentTime().toString(), Qt::green);

    disableButtons(true);
}

void Dialog::on_pbConnect_clicked() {
    socket->connectToHost(QHostAddress::LocalHost, 8000);
}

void Dialog::on_pbDisconnect_clicked() {
    QString message = "/bye";
    sendServiceMessage(message);

    socket->disconnectFromHost();
}

void Dialog::displayError(const QString &error) {
    addToLog(error, QTime::currentTime().toString(), Qt::red);
    QMessageBox::critical(this, "Client error!", error);
}

void Dialog::disableButtons(const bool state, const bool state_2) {
    ui->pbt_Send->setDisabled(state);
    ui->message_Edit->setDisabled(state_2);
}

void Dialog::addFile(MessageProtocol &protocol, QString &filePath) {
    ui->labelFiles->setText(filePath);
    QByteArray data;

    QFile file(filePath);
    QList<QPair<QString, QByteArray>> info;

    if (file.open(QIODevice::ReadOnly)) {
        data = file.readAll();
        int size = filePath.split('/').size();
        if (size) {
            info.push_back(qMakePair(filePath.split('/')[size - 1], data));
        } else {
            info.push_back(qMakePair(filePath, data));
        }
        protocol.setFile(info);
    }
}

void Dialog::saveFiles(MessageProtocol &protocol, QString &filePath) {
    auto files = protocol.getFiles();

    for(int i = 0; i < files.size(); ++i) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(files[i].second);
        }
        file.close();
    }
}

void Dialog::sendServiceMessage(QString &textMessage) {
    // Издержки тестирования
//    MessageProtocol message(dialogId, "Andrey", "@und_dayk", textMessage, 3);
    MessageProtocol message(dialogId, "Sergey", "@yut_fut", textMessage, 2);
//  MessageProtocol message(dialogId, "Artem", "@bus_artem", textMessage, 1);

    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_15);
    QString convertMessage = message.convert();
    stream << convertMessage;

    ui->pbConnect->setEnabled(false);
    ui->pbDisconnect->setEnabled(true);
}

void Dialog::addToLog(QString text, QString time, QColor color) {
    QString message = QString(time + " " + text);

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


void Dialog::on_voiceButton_clicked() {
    if (!stateRecord) {
        qDebug() << "Запись пошла";
        stateRecord = !stateRecord;
    } else {
        qDebug() << "Запись остановлена";
        stateRecord = !stateRecord;
    }
}
