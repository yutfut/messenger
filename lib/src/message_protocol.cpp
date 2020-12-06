#include "../headers/message_protocol.h"

MessageProtocol::MessageProtocol(const size_t &dialogId, const QString &senderUser, const QString &receiverUser, const QString &message,
                                 int senderId, int receiverId): dialogId(dialogId), senderUser(senderUser), receiverUser(receiverUser),
                                message(message), currentTime(QTime::currentTime()), senderId(senderId), receiverId(receiverId) {
    lengthSenderUser = senderUser.size();
    lengthReceiverUser = receiverUser.size();
}

MessageProtocol::MessageProtocol(QString &protocolMessage) {
    QStringList split_data = protocolMessage.split(',');

    dialogId = split_data[0].toInt();
    receiverId = split_data[1].toInt();
    receiverUser = split_data[2];

    senderId = split_data[3].toInt();
    senderUser = split_data[4];

    for(int j = 5; j < split_data.length(); ++j) {
        message+=split_data[j];
    }

    lengthSenderUser = senderUser.size();

    lengthReceiverUser = receiverUser.size();
}

size_t MessageProtocol::getDialogId() const {
    return dialogId;
}


QString MessageProtocol::getSenderUser() const {
    return senderUser;
}

QString MessageProtocol::getMessage() const {
    return message;
}

QString MessageProtocol::getReceiverUser() const {
    return receiverUser;
}

bool MessageProtocol::isValid() {
    if (lengthSenderUser > MAX_USER_LENGTH || lengthReceiverUser > MAX_USER_LENGTH) {
        return false;
    } else if (senderUser.contains(',') || receiverUser.contains(',')) {
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

int MessageProtocol::getReceiverId() const {
    return receiverId;
}

void MessageProtocol::setMessage(QString &message) {
    this->message = message;
}

void MessageProtocol::convert(QString &result) {
    result = QString("%1,%2,%3,%4,%5,%6").arg(QString::number(dialogId), QString::number(senderId), senderUser,
                                              QString::number(receiverId), receiverUser,message);
}
