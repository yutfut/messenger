#ifndef MESSAGEPROTOCOL_H
#define MESSAGEPROTOCOL_H

#include <iostream>
#include <ctime>
#include <QString>
#include <QTime>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

#define MAX_NICKNAME_LENGTH 255
#define MAX_USER_LENGTH 255
#define COUNT_FIELDS 4

class MessageProtocol {
public:
    MessageProtocol(const int &dialogId, const QString &senderUser,
                    const QString &nickName, const QString &message, int SenderId = -1);
    MessageProtocol(QString &protocolMessage);
    MessageProtocol(const QString &senderUser, const QString &nickName, const QString &message);

    // Геттеры
    [[nodiscard]] int getDialogId() const;
    [[nodiscard]] QString getSenderUser() const;
    [[nodiscard]] QString getNickname() const;
    [[nodiscard]] QString getMessage() const;
    [[nodiscard]] QTime getTime() const;
    [[nodiscard]] int getSenderId() const;

    void setMessage(QString &message);
    void setUserId(int id);
    void setDialogId(int id);

    bool isValid();
    QString convert();
private:

    int dialogId;
    size_t lengthSenderUser;
    size_t lengthNickname;

    QString senderUser;
    QString nickName;

    QString message;

    QTime currentTime;

    int senderId;
};

#endif // MESSAGEPROTOCOL_H
