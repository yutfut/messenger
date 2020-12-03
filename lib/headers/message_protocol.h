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
    MessageProtocol(const size_t &dialogId, const QString &senderNickname, const QString &senderUser,
                    const QString &receiverNickname, const QString &receiverUser, const QString &message);
    MessageProtocol(QString &protocolMessage);

    // Геттеры
    [[nodiscard]] size_t getDialogId() const;
    [[nodiscard]] QString getSenderNickname() const;
    [[nodiscard]] QString getSenderUser() const;
    [[nodiscard]] QString getMessage() const;
    [[nodiscard]] QString getReceiverNickame() const;
    [[nodiscard]] QString getReceiverUser() const;
    [[nodiscard]] QTime getTime() const;

    bool isValid();
    void convert(QString &result);
private:
    size_t dialogId;
    size_t lengthSenderNickname;
    size_t lengthSenderUser;
    size_t lengthReceiverNickname;
    size_t lengthReceiverUser;

    QString senderNickname;
    QString senderUser;
    QString receiverNickname;
    QString receiverUser;

    QString message;

    QTime currentTime;
};

#endif // MESSAGEPROTOCOL_H
