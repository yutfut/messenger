#ifndef PROJECT_DATA_BASE_H
#define PROJECT_DATA_BASE_H
#include <vector>
#include <string>
#include "structures.h"

// Interface

class IMessageManager {
public:
    virtual std::vector<Message> get_messages (idType dialog_id, idType last_msg_id, idType limit) = 0;
    // возвращает сообщения диалога начиная с last_msg_id, количество определяется лимитом
    virtual Message post_message (const Message& message) = 0;
    // регистрирует сообщение, вносит в бд
};

class IUserManager {
public:
    virtual User get_user (const std::string& login) = 0;
    // возвращает айди, имя и логин юзера по логину
    virtual idType get_user_id (const std::string& login) = 0;
    // возвращает айди юзера по логину
    virtual User create_user (const std::string& name, const std::string& login) = 0;
    //создает юзера, вносит в бд
};

class IDialogManager {
public:
    virtual std::vector<Dialog> get_dialog (idType user_id, idType last_dlg_id, idType limit) = 0;
    // возвращает список диалогов начиная с last_dlg_id, количество = limit
    virtual idType create_dlg (idType user_id, std::vector<idType> massive_customers) = 0;
    // создает диалог/групповой чат,сразу добавляет туда пользователей
    virtual int add_members(idtype_t dialog_id, idType future_member_id, std::vector<idType> members_to_add) = 0;
    // добавляет пользователей в групповой чат(в случае надобности)
};

#endif //PROJECT_DATA_BASE_H
