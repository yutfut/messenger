#include "../headers/message_protocol.h"

MessageProtocol::MessageProtocol(const size_t &dialogId, const QString &nickname, const QString &user,
     const QString &message):dialogId(dialogId), nickname(nickname), user(user), message(message),
    currentTime(QTime::currentTime()) {

    lengthNickname = nickname.size();
    lengthUser = user.size();
    currentTime = QTime::currentTime();
}

MessageProtocol::MessageProtocol(QString &protocolMessage) {
    QStringList split_data = protocolMessage.split(',');

    dialogId = split_data[0].toInt();
    nickname = split_data[1];
    user = split_data[2];
    for(int j = 3; j < split_data.length(); ++j) {
        message+=split_data[j];
    }

    lengthNickname = nickname.size();
    lengthUser = user.size();
}

size_t MessageProtocol::getDialogId() const {
    return dialogId;
}

QString MessageProtocol::getNickname() const {
    return nickname;
}

QString MessageProtocol::getUser() const {
    return user;
}

QString MessageProtocol::getMessage() const {
    return message;
}

bool MessageProtocol::isValid() {
    if (lengthUser > MAX_USER_LENGTH || lengthNickname > MAX_NICKNAME_LENGTH) {
        return false;
    } else if (nickname.contains(',') || user.contains(',')) {
        return false;
    }
    return true;
}

QTime MessageProtocol::getTime() const {
    return currentTime;
}

void MessageProtocol::convert(QString &result) {
    result = QString("%1,%2,%3,%4").arg(QString::number(dialogId), nickname,user,message);
}
