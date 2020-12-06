#ifndef PROJECT_DATA_SQL_H
#define PROJECT_DATA_SQL_H
#include "structures.h"
#include "data_base.h"
#include <sqlite3.h>

// USERS

class SQL{
 public:
    sqlite3* create_data_base();
    sqlite3* get_db();
    int callback(void *NotUsed, int argc, char **argv, char **azColName);
    void(*callbackPointer);
    static void check(int k, const std::string s, char*zErrMsg);
 private:
    sqlite3 *Db;
    // idType id;
    //std::string name;
    //std::string login;
    User user;
};

class UserManagerSQL : public IUserManager, public SQL {
public:
    User get_user (const std::string& login1) override;
    User create_user (const std::string& name,const std::string& login) override;
    idType get_user_id (const std::string& login) override;
private:
    std::vector<User> massive_users;
    idType id = 1;
    User user;
};

// DIALOGUES

class DialogManagerSQL : public IDialogManager {
public:
    idType create_dlg_and_add_members (idType user_id, std::vector<idType> massive_customers) override;
    std::vector<Dialog> get_dialog (idType user_id, idType last_dlg_id, idType limit) override;
private:
    std::vector<std::pair<idType, idType>> members_dlg_id;
    std::vector<Dialog> massive_dlg;
    idType dialog_id = 1;
};

// MESSAGES

class MessageManagerSQL : public IMessageManager {
public:
    Message post_message(const Message& message) override;
    std::vector<Message> get_messages (idType dialog_id, idType last_msg_id, idType limit) override;
private:
    idType id = 1;
    std::vector<Message> massive_messages;
};

#endif //PROJECT_DATA_SQL_H
