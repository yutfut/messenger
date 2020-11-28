#ifndef PROJECT_DATA_BASE_H
#define PROJECT_DATA_BASE_H
#include <vector>

typedef int id_type_t;

struct Message_content {
    std::string text;
};

struct user {
    id_type_t id;
    std::string name;
    std::string login;
};

struct message {
    id_type_t id;
    id_type_t sender_id;
    id_type_t dialog_id;
    Message_content content;
    time_t time;
};

struct dialog {
    id_type_t id;
};

struct dialogue_members {
    id_type_t id;
    id_type_t  dialog_id;
    id_type_t member_id;
};
// Interface

class I_msg_manager {
public:
    virtual std::vector<message> get_messages (id_type_t dialog_id, id_type_t last_msg_id, size_t limit) = 0;
    virtual message Post_message (const message& message1) = 0;
};

class I_user_manager {
public:
    virtual user get_user (const std::string& login) = 0;
    virtual user get_user (id_type_t id) = 0;
    virtual user get_user (std::string &name) = 0;
};

class I_dlg_manager {
public:
    virtual std::vector<dialog> get_dialog(id_type_t user_id, id_type_t address_id, id_type_t last_dlg_id, size_t limit) = 0;
};

class Dialog_manager_map : public I_dlg_manager {
public:
    id_type_t check_dialog_creation(id_type_t user_id, id_type_t address_id);
    id_type_t get_dialog_id (id_type_t user_id, id_type_t address_id);
    std::vector<dialog> get_dialog (id_type_t user_id, id_type_t address_id, id_type_t last_dlg_id, size_t limit) override;
private:
    std::vector<std::pair<id_type_t, id_type_t>> members_dlg_id; // vector dialog members id
    std::vector<dialog> massive_dlg;
    id_type_t dialog_id;
};

class User_manager_map : public I_user_manager {
public:
    user get_user (const std::string& login) override;
    user get_user (id_type_t id) override;
private:
    std::vector<user> massive_users;
};

class Message_manager_map : public I_msg_manager {
public:
    message create_message(message& message1);
    std::vector<message> get_messages (id_type_t dialog_id, id_type_t last_msg_id, size_t limit) override;
private:
    std::vector<message> massive_messages;
};
#endif //PROJECT_DATA_BASE_H
