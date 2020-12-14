#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QRegularExpression>
#include <QString>
#include <QUuid>

#include "map.h"
#include "mimeattachment.h"
#include "mimefile.h"
#include "mimehtml.h"
#include "mimeinlinefile.h"
#include "mimemessage.h"
#include "mimepart.h"
#include "mimetext.h"
#include "smtpclient.h"

#define INCORRECT_INPUT -1
#define INCORRECT_PASSWORD -2
#define NOT_AUTHORIZED -3
#define AUTHORIZED_ALREADY -4
#define NOT_REGISTRATED -5
#define NOT_APPROVED -6
#define INCORRECT_CODE -7


class authorization
{
public:
    authorization();
    int login(QString mail, QString password);
    int sign_up(QString mail, QString password);
    bool compare_password(const User user, QString password);
    int approve_user(QString login, int code);
};

#endif // AUTHORIZATION_H
