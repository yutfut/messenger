#include "dialog.h"
#include "ui_dialog.h"

#include <QtGui>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :QDialog(parent),ui(new Ui::Dialog) {
    ui->setupUi(this);

    _name = "";
    _sok = new QTcpSocket(this);
    connect(_sok, SIGNAL(readyRead()), this, SLOT(onSokReadyRead()));
    connect(_sok, SIGNAL(connected()), this, SLOT(onSokConnected()));
    connect(_sok, SIGNAL(disconnected()), this, SLOT(onSokDisconnected()));
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
        QString error = "The host was not found";
        ui->lwLog->insertItem(0, error);
        QMessageBox::critical(this, "Error", error);
        break;
    }
    case QAbstractSocket::ConnectionRefusedError: {
        QString error = "The connection was refused by the peer.";
        ui->lwLog->insertItem(0, error);
        QMessageBox::critical(this, "Error", error);
        break;
    }
    default:
        QMessageBox::critical(this, "Error", "The following error occurred: "+_sok->errorString());
    }
}

void Dialog::onSokReadyRead() {
    QDataStream in(_sok);
    if (_blockSize == 0) {
        if (_sok->bytesAvailable() < (int)sizeof(quint16)) {
            return;
        }

        in >> _blockSize;
        qDebug() << "_blockSize now " << _blockSize;
    }

    if (_sok->bytesAvailable() < _blockSize) {
        return;
    } else {
        _blockSize = 0;
    }

    quint8 command;
    in >> command;
    qDebug() << "Received command " << command;
}

void Dialog::onSokConnected() {
    ui->pbConnect->setEnabled(false);
    ui->pbDisconnect->setEnabled(true);
    _blockSize = 0;
    AddToLog("Connected to"+_sok->peerAddress().toString()+":"+QString::number(_sok->peerPort()),Qt::green);
}

void Dialog::onSokDisconnected() {
    ui->pbConnect->setEnabled(true);
    ui->pbDisconnect->setEnabled(false);
    AddToLog("Disconnected from"+_sok->peerAddress().toString()+":"+QString::number(_sok->peerPort()), Qt::green);
}

void Dialog::on_pbConnect_clicked() {
    _sok->connectToHost(ui->leHost->text(), ui->sbPort->value());
}

void Dialog::on_pbDisconnect_clicked() {
    _sok->disconnectFromHost();
}

void Dialog::AddToLog(QString text, QColor color)
{
    ui->lwLog->insertItem(0, QTime::currentTime().toString()+" "+text);
    ui->lwLog->item(0)->setForeground(color);
}
