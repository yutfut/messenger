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
    QJsonObject object = QJsonDocument::fromJson(protocolMessage.toUtf8()).object();

    // Заполняем наши поля
    dialogId = object["dialogId"].toInt();
    senderId = object["senderId"].toInt();

    senderUser = object["senderUser"].toString();
    nickName = object["nickName"].toString();
    message = object["message"].toString();

    lengthSenderUser = senderUser.size();
    lengthNickname = nickName.size();

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
    QJsonObject finalObject( {
                                 qMakePair(QString("dialogId"), QJsonValue(dialogId)),
                                 qMakePair(QString("senderId"), QJsonValue(senderId)),
                                 qMakePair(QString("nickName"), QJsonValue(nickName)),
                                 qMakePair(QString("senderUser"), QJsonValue(senderUser)),
                                 qMakePair(QString("message"), QJsonValue(message)),
                             });
    QJsonDocument document(finalObject);
    return document.toJson(QJsonDocument::Compact);
}

void MessageProtocol::setUserId(int id) {
    senderId = id;
}

void MessageProtocol::setDialogId(int id) {
    dialogId = id;
}
