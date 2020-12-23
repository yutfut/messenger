#ifndef PROJECT_STRUCTURES_H
#define PROJECT_STRUCTURES_H
#include <string>

// Types and structures

typedef int idType;
typedef std::string timeType;
typedef std::string dataType;

struct User {
    idType id;
    std::string name;
    std::string login;
    std::string password_hash;
    bool approved;
    int approve_code;
    int recovery_code;
    int flag_delete_ser;
};

struct Message {
    idType id;
    idType sender_id;
    idType dialog_id;
    std::string text;
    dataType data;
    timeType time;
};

struct Dialogues {
    idType id;
};

struct Dialogue_members {
    idType id;
    idType  dialog_id;
    idType member_id;
};

struct Safety {
    std::string login;
    std::string salt;
};

#endif //PROJECT_STRUCTURES_H
