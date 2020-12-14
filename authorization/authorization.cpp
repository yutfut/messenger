#include "authorization.h"

authorization::authorization(){}

int authorization::login(QString mail, QString password) {
    if (mail == nullptr || password == nullptr) {
        return INCORRECT_INPUT;
    }

    UserManagerMap umm;
    User user = umm.get_user(mail.toStdString());
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
    salted_password.append(user.salt.c_str());
    QByteArray hashed_salted_password = QCryptographicHash::hash(salted_password, QCryptographicHash::Sha256).toHex();
    return hashed_salted_password.toStdString() == password.toStdString();
}

int authorization::approve_user(QString mail, int code) {
    if (mail == nullptr) {
        return INCORRECT_INPUT;
    }

    UserManagerMap umm;
    User user = umm.get_user(mail.toStdString());

    if (user.login == "") {
        return NOT_REGISTRATED;
    }

    if (user.approve_code != code) {
        return INCORRECT_CODE;
    }

    /*
    Set appproved
    */

    return user.id;
}

int authorization::sign_up(QString mail, QString password) {
    if (mail == nullptr || password == nullptr) {
        return INCORRECT_INPUT;
    }

    UserManagerMap umm;
    User user = umm.get_user(mail.toStdString());

    if (user.login != "") {
        return NOT_REGISTRATED;
    }
    
    if (!user.approved) {
        return NOT_APPROVED;
    }

    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
    smtp.setUser("alievz2019@gmail.com");
    smtp.setPassword("************");

    MimeMessage message;
    message.setSender(new EmailAddress("alievz2019@gmail.com", "MESSENGER"));
    message.addRecipient(new EmailAddress(mail, "Recipient"));
    message.setSubject("Registration code..........");

    int registration_code = 123456;
    /*
    Generate registration code
    */

    MimeText text;
    text.setText("Your registration code is: " + registration_code);
    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();

    QString salt = QUuid::createUuid().toString();
    salt.remove(QRegularExpression("{|}|-")); // only hex numbers
    user.salt = salt.toStdString();

    QByteArray salted_password (password.toStdString().c_str());
    salted_password.append(salt.toStdString().c_str());
    QByteArray hashed_salted_password = QCryptographicHash::hash(salted_password, QCryptographicHash::Sha256).toHex();
    user.passwordHash = salted_password.toStdString();
    
    /*
    Add user into DB
    */

    return user.id;
}
