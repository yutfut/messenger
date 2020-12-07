#ifndef PROJECT_STRUCTURES_H
#define PROJECT_STRUCTURES_H
#include <string>

// Types and structures

typedef int idType;
typedef std::string timeType;

/*struct Message_content { std::string text; };*/

struct User {
    idType id;
    std::string name;
    std::string login;
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

struct dialogue_members {
    idType id;
    idType  dialog_id;
    idType member_id;
};

#endif //PROJECT_STRUCTURES_H
