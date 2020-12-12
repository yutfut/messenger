#ifndef PROJECT_INTERFACE_H
#define PROJECT_INTERFACE_H
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
    virtual int getMessageId() = 0;
    // возвращает айди сообщения(последнего)
};

class IUserManager {
public:
    virtual User get_user (const std::string& login) = 0;
    // возвращает айди, имя и логин юзера по логину
    virtual User create_user (const std::string& name, const std::string& login) = 0;
    //создает юзера, вносит в бд
};

class IDialogManager {
public:
    virtual std::vector<Dialog> get_dialog (idType user_id, idType last_dlg_id, idType limit) = 0;
    // возвращает список диалогов начиная с last_dlg_id, количество = limit
    virtual idType create_dlg (idType user_id, std::vector<idType> massive_customers) = 0;
    // создает диалог/групповой чат,сразу добавляет туда пользователей
    virtual int add_members(idType dialog_id, std::vector<idType> members_to_add) = 0;
    // добавляет пользователей в групповой чат(в случае надобности)
    virtual std::vector<idType> get_users_in_dlg(idType dialog_id) = 0;
    // возвращает айди пользователей кроме самого юзера по айди диалога
    virtual int is_user_in_dlg(idType dialog_id, idType user_id) = 0;
    // Проверяет есть ли юзер в диалоге
};

#endif //PROJECT_INTERFACE_H
