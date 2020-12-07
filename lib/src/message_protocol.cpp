#include "../headers/message_protocol.h"

// Когда вся информация о пользователе есть и ничего добавлять в БД не нужно
MessageProtocol::MessageProtocol(const int &dialogId, const QString &senderUser, const QString &nickName, const QString &message,
        int senderId): dialogId(dialogId), senderUser(senderUser), nickName(nickName),
        message(message), currentTime(QTime::currentTime()), senderId(senderId) {
    lengthSenderUser = senderUser.size();
    lengthNickname = nickName.size();
}

// Распарсинг сообщений
MessageProtocol::MessageProtocol(QString &protocolMessage) {
    QStringList split_data = protocolMessage.split(',');
//    qDebug() << split_data;

    dialogId = split_data[0].toInt();
    senderId = split_data[1].toInt();
    nickName = split_data[2];
    senderUser = split_data[3];

    for(int j = 4; j < split_data.size(); ++j) {
        message+=split_data[j];
    }

    lengthSenderUser = senderUser.size();
}

// Данный конструктор нужен когда пользователь вообще ничего не знает о своих ID и DialogID
MessageProtocol::MessageProtocol(const QString &senderUser, const QString &nickName, const QString &message):
    senderUser(senderUser), nickName(nickName), message(message) {
    lengthNickname = nickName.size();
    lengthSenderUser = senderUser.size();

    // Ставим пока временные значения
    dialogId = -1;
    senderId = -1;
}

int MessageProtocol::getDialogId() const {
    return dialogId;
}


QString MessageProtocol::getSenderUser() const {
    return senderUser;
}

QString MessageProtocol::getNickname() const {
    return nickName;
}

QString MessageProtocol::getMessage() const {
    return message;
}

bool MessageProtocol::isValid() {
    if (lengthSenderUser > MAX_USER_LENGTH) {
        return false;
    } else if (senderUser.contains(',')) {
        return false;
    }
    return true;
}

QTime MessageProtocol::getTime() const {
    return currentTime;
}

int MessageProtocol::getSenderId() const {
    return senderId;
}

void MessageProtocol::setMessage(QString &message) {
    this->message = message;
}

QString MessageProtocol::convert() {
    return QString("%1,%2,%3,%4,%5").arg(QString::number(dialogId), QString::number(senderId), nickName, senderUser, message);
}

void MessageProtocol::setUserId(int id) {
    senderId = id;
}

void MessageProtocol::setDialogId(int id) {
    dialogId = id;
}
