#ifndef PROJECT_SQL_H
#define PROJECT_SQL_H

#include "structures.h"
#include "interface.h"
#include <sqlite3.h>

// USERS
class SQL{
 public:
    sqlite3* create_data_base();
    static void check(int k, const std::string s, char*zErrMsg);
 protected:
    sqlite3 *Db = nullptr;
};

class UserManagerSQL : public IUserManager, public SQL {
public:
    UserManagerSQL();
    User get_user (const std::string& login1) override;
    User get_user (idType id) override;
    User create_user (const std::string &name, const std::string &login, const std::string &salt, const std::string &password_hash) override;
    User set_user_approved (const std::string& login, int approved) override;
    void delete_user (const std::string &login) override;
    void recovery_user (const std::string &login) override;
    int check_status_user (const std::string &login) override;

    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    static int callback_delete(void *NotUsed, int argc, char **argv, char **azColName);
private:
    const char *sql;
    User user;
    int user_status;
};

// DIALOGUES
struct Idr {
    idType id;
};

class DialogManagerSQL : public IDialogManager, public SQL{
public:

    idType create_dlg (idType user_id, std::vector<idType> massive_customers) override;
    int add_members(idType dialog_id, std::vector<idType> members_to_add) override;
    std::vector<Dialog> get_dialog (idType user_id, idType last_dlg_id, idType limit) override;
    std::vector<idType> get_users_in_dlg(idType dialog_id) override;
    int is_user_in_dlg(idType dialog_id, idType user_id) override;

    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
    static int callback_check(void *NotUsed, int argc, char **argv, char **azColName);
    static int callback_id(void *NotUsed, int argc, char **argv, char **azColName);
    static int callback_vec(void *NotUsed, int argc, char **argv, char **azColName);
private:
    char *sql;
    std::vector<idType> dlg_members;
    std::vector<Dialog> dlg_vector;
    Idr id_result;
    int check_result;
};

// MESSAGES

struct LastMessage{
    idType last_msg_id;
};


class MessageManagerSQL: public IMessageManager, public SQL{
public:

    Message post_message(const Message& message) override;
    std::vector<Message> get_messages (idType dialog_id, idType last_msg_id, idType limit) override;
    int get_message_id() override;
    void delete_messages(std::vector<Message> messages_id) override;
    void forward_messages (std::vector<Message> messages_id) override;

    static int callback_vec(void *NotUsed, int argc, char **argv, char **azColName);
    static idType callback_id(void *NotUsed, int argc, char **argv, char **azColName);
    static int callback_mes(void *NotUsed, int argc, char **argv, char **azColName);
private:
    char* sql;
    std::vector<Message> msg_vector;
    Message msg;
    LastMessage the_last_message_id;
};

#endif //PROJECT_INTERFACE_H
