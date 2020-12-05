#ifndef MESSAGEPROTOCOL_H
#define MESSAGEPROTOCOL_H

#include <iostream>
#include <ctime>
#include <QString>
#include <QTime>
#include <QDebug>

#define MAX_NICKNAME_LENGTH 255
#define MAX_USER_LENGTH 255
#define COUNT_FIELDS 4

class MessageProtocol {
public:
    MessageProtocol(const size_t &dialogId, const QString &senderUser, const QString &receiverUser, const QString &message, int SenderId, int receiverId);
    MessageProtocol(QString &protocolMessage);

    // Геттеры
    [[nodiscard]] size_t getDialogId() const;
    [[nodiscard]] QString getSenderUser() const;
    [[nodiscard]] QString getMessage() const;
    [[nodiscard]] QString getReceiverUser() const;
    [[nodiscard]] QTime getTime() const;
    [[nodiscard]] int getSenderId() const;
    [[nodiscard]] int getReceiverId() const;

    bool isValid();
    void convert(QString &result);
private:
    size_t dialogId;
    size_t lengthSenderUser;
    size_t lengthReceiverUser;

    QString senderUser;
    QString receiverUser;

    QString message;

    QTime currentTime;

    qint8 senderId;
    qint8 receiverId;
};

#endif // MESSAGEPROTOCOL_H
