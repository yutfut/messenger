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
    MessageProtocol(const size_t &dialogId, const QString &nickname,
                    const QString &user, const QString &message);
    MessageProtocol(QString &protocolMessage);

//    Геттеры
    [[nodiscard]] size_t GetDialogId() const;
    [[nodiscard]] QString getNickname() const;
    [[nodiscard]] QString getUser() const;
    [[nodiscard]] QString getMessage() const;
    [[nodiscard]] QTime getTime() const;

    bool isValid();
    void convert(QString &result);
private:
    size_t dialogId;
    size_t lengthNickname;
    size_t lengthUser;

    QString nickname;
    QString user;
    QString message;

    QTime currentTime;
};

#endif // MESSAGEPROTOCOL_H
