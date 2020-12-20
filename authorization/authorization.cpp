#include "authorization.h"

authorization::authorization(){}

int authorization::login(QString mail, QString password) {
    if (mail == nullptr || password == nullptr) {
        return INCORRECT_INPUT;
    }

//    UserManagerSQL um;
    User user = um.get_user(mail.toStdString());
    if (user.login == "") {
        return NOT_REGISTRATED;
    }

    if (compare_password(user, password) == false) {
        return INCORRECT_PASSWORD;
    }

    return user.id;
}

bool authorization::compare_password(const User user, QString password) {
    QByteArray salted_password (password.toStdString().c_str());
//    salted_password.append(user.salt.c_str());
    QByteArray hashed_salted_password = QCryptographicHash::hash(
                QCryptographicHash::hash(salted_password, QCryptographicHash::Sha256).toHex().append(user.salt.c_str()),
                QCryptographicHash::Sha256).toHex();
    return hashed_salted_password.toStdString() == password.toStdString();
}

//bool authorization::compare_password(const User user, QString password) {
//    QByteArray salted_password (password.toStdString().c_str());
//    salted_password.append(user.salt.c_str());
//    QByteArray hashed_salted_password = QCryptographicHash::hash(salted_password, QCryptographicHash::Sha256).toHex();
//    return hashed_salted_password.toStdString() == password.toStdString();
//}

int authorization::approve_user(QString mail, int code) {
    if (mail == nullptr) {
        return INCORRECT_INPUT;
    }

//    UserManagerSQL um;
    User user = um.get_user(mail.toStdString());

    if (user.login == "") {
        return NOT_REGISTRATED;
    }

    if (user.approve_code != code) {
        return INCORRECT_CODE;
    }

    um.set_user_approved(mail.toStdString(), 1);

    return user.id;
}

int authorization::sign_up(QString mail, QString password, QString name) {
    if (mail == nullptr || password == nullptr) {
        return INCORRECT_INPUT;
    }

//    UserManagerSQL um;
    User user = um.get_user(mail.toStdString());

    if (user.login != "") {
        return NOT_REGISTRATED;
    }
    
    if (!user.approved) {
        return NOT_APPROVED;
    }

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("messenger.ru.park.mail@gmail.com");
    smtp.setPassword("proshmandovkiplusov");

    MimeMessage message;
    message.setSender(new EmailAddress("messenger.ru.park.mail@gmail.com", "MESSENGER"));
    message.addRecipient(new EmailAddress(mail, "To recipient"));
    message.setSubject("Registration code");

    int registration_code = (qrand() % 1000000);
    if (registration_code < 100000) {
        registration_code += 100000;
    }

    MimeText text;
    text.setText(QString("Your registration code is: ") + registration_code);
    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();

    QString salt = QUuid::createUuid().toString();
    salt.remove(QRegularExpression("{|}|-")); // only hex numbers

    QByteArray salted_password (password.toStdString().c_str());
    QByteArray hashed_salted_password = QCryptographicHash::hash(
                QCryptographicHash::hash(salted_password, QCryptographicHash::Sha256).toHex().append(salt.toStdString().c_str()),
                QCryptographicHash::Sha256).toHex();
    
    um.create_user(name.toStdString(), mail.toStdString(), salt.toStdString(), hashed_salted_password.toStdString());

    return um.get_user(mail.toStdString()).id;
}

void authorization::delete_user(QString login) {
    um.delete_user(login.toStdString());
}

int authorization::recovery_user(QString login) {
    if (login == nullptr) {
        return INCORRECT_INPUT;
    }

//    UserManagerSQL um;
    User user = um.get_user(login.toStdString());

    if (user.login != "") {
        return NOT_REGISTRATED;
    }

    if (!user.approved) {
        return NOT_APPROVED;
    }

    if (user.flag_delete_ser == 0) {
        return USER_IS_NOT_DELETED;
    }

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("messenger.ru.park.mail@gmail.com");
    smtp.setPassword("proshmandovkiplusov");

    MimeMessage message;
    message.setSender(new EmailAddress("messenger.ru.park.mail@gmail.com", "MESSENGER"));
    message.addRecipient(new EmailAddress(login, "To recipient"));
    message.setSubject("recovery code");

    int recovery_code = (qrand() % 1000000);
    if (recovery_code < 100000) {
        recovery_code += 100000;
    }

    MimeText text;
    text.setText(QString("Your recovery code is: ") + recovery_code);
    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
    return user.id;
}

int authorization::approve_recovery(QString login, int code, QString new_password) {
    if (login == nullptr) {
        return INCORRECT_INPUT;
    }

//    UserManagerSQL um;
    User user = um.get_user(login.toStdString());

    if (user.login != "") {
        return NOT_REGISTRATED;
    }

    if (!user.approved) {
        return NOT_APPROVED;
    }

    if (user.flag_delete_ser == 0) {
        return USER_IS_NOT_DELETED;
    }

    if (user.recovery_code == code) {
        QByteArray salted_password (new_password.toStdString().c_str());
        QByteArray hashed_salted_password = QCryptographicHash::hash(
                    QCryptographicHash::hash(salted_password, QCryptographicHash::Sha256).toHex().append(user.salt.c_str()),
                    QCryptographicHash::Sha256).toHex();
        um.recovery_user(login);
    }
}
