#include "../headers/message_protocol.h"

MessageProtocol::MessageProtocol(const size_t &dialogId, const QString &senderNickname, const QString &senderUser,
                const QString &receiverNickname, const QString &receiverUser, const QString &message):
                dialogId(dialogId), senderNickname(senderNickname), senderUser(senderUser), receiverNickname(receiverNickname),
                receiverUser(receiverUser), message(message), currentTime(QTime::currentTime()) {
    lengthSenderNickname = senderNickname.size();
    lengthSenderUser = senderUser.size();

    lengthReceiverNickname = receiverNickname.size();
    lengthReceiverUser = receiverUser.size();
}

MessageProtocol::MessageProtocol(QString &protocolMessage) {
    QStringList split_data = protocolMessage.split(',');

    dialogId = split_data[0].toInt();
    senderNickname = split_data[1];
    senderUser = split_data[2];

    receiverNickname = split_data[3];
    receiverUser = split_data[4];

    for(int j = 5; j < split_data.length(); ++j) {
        message+=split_data[j];
    }

    lengthSenderNickname = senderNickname.size();
    lengthSenderUser = senderUser.size();

    lengthReceiverNickname = receiverNickname.size();
    lengthReceiverUser = receiverUser.size();
}

size_t MessageProtocol::getDialogId() const {
    return dialogId;
}

QString MessageProtocol::getSenderNickname() const {
    return senderNickname;
}

QString MessageProtocol::getSenderUser() const {
    return senderUser;
}

QString MessageProtocol::getMessage() const {
    return message;
}

QString MessageProtocol::getReceiverNickame() const {
    return receiverNickname;
}

QString MessageProtocol::getReceiverUser() const {
    return receiverUser;
}

bool MessageProtocol::isValid() {
    if (lengthSenderUser > MAX_USER_LENGTH || lengthSenderNickname > MAX_NICKNAME_LENGTH ||
            lengthReceiverNickname > MAX_NICKNAME_LENGTH || lengthReceiverUser > MAX_USER_LENGTH) {
        return false;
    } else if (senderNickname.contains(',') || senderUser.contains(',') ||
               (receiverNickname.contains(',')) || receiverUser.contains(',')) {
        return false;
    }
    return true;
}

QTime MessageProtocol::getTime() const {
    return currentTime;
}

void MessageProtocol::convert(QString &result) {
    result = QString("%1,%2,%3,%4,%5,%6").arg(QString::number(dialogId), senderNickname,senderUser,
                                              receiverNickname, receiverUser,message);
}
