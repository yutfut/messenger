#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <string>

// Types and structures

typedef int idType;
typedef std::string timeType;
typedef std::string strType;

/*struct Message_content { std::string text; };*/

struct User {
    idType id;
    std::string name;
    std::string login;
    strType salt;
    strType passwordHash;
    bool approved;
    int approve_code;
};

struct Message {
    idType id;
    idType sender_id;
    idType dialog_id;
    std::string text; // Message_content content;
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
