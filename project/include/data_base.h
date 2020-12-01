#ifndef PROJECT_DATA_BASE_H
#define PROJECT_DATA_BASE_H
#include <vector>
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

// Interface

class IMessageManager {
public:
    virtual std::vector<Message> get_messages (idType dialog_id, idType last_msg_id, size_t limit) = 0;
    // virtual Message Post_message (const Message& message1) = 0;
    virtual Message create_message(idType dialog_id, idType sender_id, std::string text, timeType time) = 0;
};

class IUserManager {
public:
    virtual User get_user (const std::string& login) = 0;
    virtual idType get_user_id (const std::string& login) = 0;
    virtual User create_user (const std::string& name, const std::string& login) = 0;
};

class IDialogManager {
public:
    virtual std::vector<Dialog> get_dialog(idType user_id, idType address_id, idType last_dlg_id, size_t limit) = 0;
    virtual idType check_dialog_creation(idType user_id, idType address_id) = 0;
};

// DIALOGUES

class DialogManagerMap : public IDialogManager {
public:
    idType check_dialog_creation(idType user_id, idType address_id) override;
    std::vector<Dialog> get_dialog (idType user_id, idType address_id, idType last_dlg_id, size_t limit) override;
private:
    std::vector<std::pair<idType, idType>> members_dlg_id; // vector Dialog members id
    std::vector<Dialog> massive_dlg;
    idType dialog_id = 1;
};

// USERS

class UserManagerMap : public IUserManager {
public:
    User get_user (const std::string& login) override;
    User create_user (const std::string& name,const std::string& login) override;
    idType get_user_id (const std::string& login) override;
private:
    std::vector<User> massive_users;
    idType id = 1;
};

// MESSAGES

class MessageManagerMap : public IMessageManager {
public:
    Message create_message(idType dialog_id, idType sender_id, std::string text, timeType time) override;
    std::vector<Message> get_messages (idType dialog_id, idType last_msg_id, size_t limit) override;
private:
    idType id = 1;
    std::vector<Message> massive_messages;
};
#endif //PROJECT_DATA_BASE_H
