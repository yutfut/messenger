#include "../headers/message_protocol.h"

// Когда вся информация о пользователе есть и ничего добавлять в БД не нужно
MessageProtocol::MessageProtocol(const int &dialogId, const QString &senderUser, const QString &nickName, const QString &message,  int senderId) {
    finalObject.insert(QString("dialogId"), QJsonValue(dialogId));
    finalObject.insert(QString("senderId"), QJsonValue(senderId));

    fillData(senderUser, nickName, message);

    lengthSenderUser = finalObject["senderUser"].toString().size();
    lengthNickname = finalObject["nickName"].toString().size();
}

// Распарсинг сообщений
MessageProtocol::MessageProtocol(QString &protocolMessage) {
    // Представляем сообщения в виде JSON-а
    finalObject = QJsonDocument::fromJson(protocolMessage.toUtf8()).object();

    lengthSenderUser = finalObject["senderUser"].toString().size();
    lengthNickname = finalObject["nickName"].toString().size();
}

// Данный конструктор нужен когда пользователь вообще ничего не знает о своих ID и DialogID
MessageProtocol::MessageProtocol(const QString &senderUser, const QString &nickName, const QString &message) {

    // Загнать в оотдельный метод
    fillData(senderUser, nickName, message);

    lengthNickname = nickName.size();
    lengthSenderUser = senderUser.size();

    // Ставим пока временные значения
    finalObject["dialogId"] = -1;
    finalObject["senderId"] = -1;
}

int MessageProtocol::getDialogId() const {
    return finalObject["dialogId"].toInt();
}

QString MessageProtocol::getSenderUser() const {
    return finalObject["senderUser"].toString();
}

QString MessageProtocol::getNickname() const {
    return finalObject["nickName"].toString();
}

QString MessageProtocol::getMessage() const {
    return finalObject["message"].toString();
}

bool MessageProtocol::isValid() {
    return (!(lengthSenderUser > MAX_USER_LENGTH || lengthNickname > MAX_NICKNAME_LENGTH));
}

bool MessageProtocol::isFilesInMessage() {
    return finalObject["files"].toArray().size() > 0;
}

int MessageProtocol::getSenderId() const {
    return finalObject["senderId"].toInt();
}

void MessageProtocol::setMessage(QString &message) {
    finalObject["message"] = message;
}

QString MessageProtocol::convert() {
    QJsonDocument document(finalObject);
    return document.toJson(QJsonDocument::Compact);
}

//  Осторожно: метод не проходил тщательную проверку
QList<QPair<QString, QByteArray>> MessageProtocol::getFiles() {
    QList<QPair<QString, QByteArray>> toReturn;
    QJsonArray array = finalObject["files"].toArray();
    QJsonObject currentValue;

    foreach(const QJsonValue &value, array) {
        currentValue = value.toObject();

        QString fileName = currentValue["filename"].toString();
        QByteArray content = currentValue["content"].toString().toUtf8();

        toReturn.push_back(qMakePair(fileName, content));
    }

    return toReturn;
}

void MessageProtocol::fillData(const QString &senderUser, const QString &nickName, const QString &message) {
    finalObject.insert(QString("nickName"), QJsonValue(nickName));
    finalObject.insert(QString("senderUser"), QJsonValue(senderUser));
    finalObject.insert(QString("message"), QJsonValue(message));
}

void MessageProtocol::setUserId(int id) {
    finalObject["senderId"] = id;
}

void MessageProtocol::setDialogId(int id) {
    finalObject["dialogId"] = id;
}

void MessageProtocol::setFile(QList<QPair<QString, QByteArray>> files) {
    QJsonArray plotArray;

    QJsonObject currentObject;
    for(int i = 0; i < files.size(); ++i) {
        currentObject.insert("filename", QString(files[i].first));
        currentObject.insert("content", QString(files[i].second));
        plotArray.push_back(QJsonValue(currentObject));

        // Удаляем ключи
        currentObject.remove(files[i].first);
        currentObject.remove(files[i].second);
    }

    finalObject.insert("files", QJsonValue(plotArray));
}

void MessageProtocol::removeFiles() {
    finalObject.remove("files");
}
