#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>

// Types and structures

typedef int idType;
typedef std::string timeType;

struct User {
    idType id;
    std::string name;
    std::string login;
    std::string salt;
    std::string password_hash;
    bool approved;
    int approve_code;
};

struct Message {
    idType id;
    idType sender_id;
    idType dialog_id;
    std::string text;
    timeType time;
};

struct Dialog {
    idType id;
};

struct Dialogue_members {
    idType id;
    idType  dialog_id;
    idType member_id;
};

#endif //STRUCTURES_H
