#include "dialog.h"
#include "ui_dialog.h"

#include <QtGui>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog) {
    ui->setupUi(this);

    Disable_buttons(true);

    _sok = new QTcpSocket(this);
    is_button_clicked = false;

    connect(this, &Dialog::newMessage, this, &Dialog::display_message);
    connect(_sok, &QTcpSocket::readyRead, this, &Dialog::onSokReadyRead);
    connect(_sok, &QTcpSocket::connected, this, &Dialog::onSokConnected);
    connect(_sok, &QTcpSocket::disconnected, this, &Dialog::onSokDisconnected);
    connect(_sok, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSokDisplayError(QAbstractSocket::SocketError)));
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::onSokDisplayError(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError: {
        Display_error("The host was not found");
        break;
    }
    case QAbstractSocket::ConnectionRefusedError: {
        Display_error("The connection was refused by the peer");
        break;
    }
    default:
        Display_error("The following error occured: " + _sok->errorString());
    }
}

void Dialog::onSokReadyRead() {
    if (is_button_clicked) {
        is_button_clicked = false;
        QByteArray buffer;

        QDataStream sock_stream(_sok);
        sock_stream.setVersion(QDataStream::Qt_5_15);

        sock_stream.startTransaction();
        sock_stream >> buffer;

        if (!sock_stream.commitTransaction()) {
            QString message = QString("%1 : No messages in server").arg(_sok->socketDescriptor());
            emit newMessage(message);
            return;
        }

        QString message = QString("%1 ").arg(QString::fromStdString(buffer.toStdString()));
        emit newMessage(message);
    }
    return;
    //  Скоро здесь будет расписывание процесса получение письма (исходя из протокола)
}

void Dialog::on_pbt_Send_clicked() {
    if (_sok) {
        if (_sok->isOpen()) {
            is_button_clicked = true;
            qDebug() << "Message: " << ui->message_Edit->text();

            QDataStream socket_stream(_sok);
            socket_stream.setVersion(QDataStream::Qt_5_15);

            socket_stream << ui->message_Edit->text();

            ui->message_Edit->clear();
            Disable_buttons(true, false);

        } else {
            Display_error("Socket can't send message");
        }
    } else {
        Display_error("Socket can't connect to server");
    }
}

void Dialog::onSokConnected() {
    ui->pbConnect->setEnabled(false);
    ui->pbDisconnect->setEnabled(true);
    AddToLog("Connected to"+_sok->peerAddress().toString()+":"+QString::number(_sok->peerPort()),Qt::green);

    Disable_buttons(true, false);
}

void Dialog::onSokDisconnected() {
    ui->pbConnect->setEnabled(true);
    ui->pbDisconnect->setEnabled(false);
    AddToLog("Disconnected from"+_sok->peerAddress().toString()+":"+QString::number(_sok->peerPort()), Qt::green);

    Disable_buttons(true);
}

void Dialog::on_pbConnect_clicked() {
    _sok->connectToHost(ui->leHost->text(), ui->sbPort->value());
}

void Dialog::on_pbDisconnect_clicked() {
    _sok->disconnectFromHost();
}

void Dialog::display_message(const QString &str) {
    qDebug() << str;
    AddToLog("Message!!! " + _sok->peerAddress().toString() + ":" + QString::number(_sok->peerPort()), Qt::blue);
    AddToLog(str, Qt::blue);
}

void Dialog::Display_error(const QString &error) {
    AddToLog(error, Qt::red);
    QMessageBox::critical(this, "Client error!", error);
}

void Dialog::Disable_buttons(const bool state, const bool state_2) {
    ui->pbt_Send->setDisabled(state);
    ui->message_Edit->setDisabled(state_2);
}

void Dialog::AddToLog(QString text, QColor color) {
    QString message = QString(QTime::currentTime().toString() + " " + text);

    ui->lwLog->setTextColor(color);
    ui->lwLog->append(message);
}

void Dialog::on_message_Edit_textEdited(const QString &arg1) {
    if (arg1.length()) {
        Disable_buttons(false, false);
    } else {
        ui->pbt_Send->setDisabled(true);
    }
}
