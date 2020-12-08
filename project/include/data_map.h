#ifndef PROJECT_DATA_MAP_H
#define PROJECT_DATA_MAP_H
#include "structures.h"
#include "data_base.h"

// USERS

class UserManagerMap : public IUserManager {
public:
    User get_user (const std::string& login) override;
    User create_user (const std::string& name,const std::string& login) override;
    idType get_user_id (const std::string& login) override;
private:
    std::vector<User> massive_users;
    idType id = 0;
};

// DIALOGUES

class DialogManagerMap : public IDialogManager {
public:
    std::vector<Dialog> get_dialog (idType user_id, idType last_dlg_id, idType limit) override;
    idType create_dlg(idType user_id, std::vector<idType> massive_customers) override;
    int add_members(idType dialog_id, idType future_member_id, std::vector<idType> members_to_add) override;
    int getUserIdInDialogues(idType dialogID, int &user_id) override;
    int isUserInDialog(idType dialogID, idType &userID) override;
private:
    std::vector<std::pair<idType, idType>> members_dlg_id;
    std::vector<Dialog> massive_dlg;
    idType dialog_id = 0;
};

// MESSAGES

class MessageManagerMap : public IMessageManager {
public:
    Message post_message(const Message& message) override;
    std::vector<Message> get_messages (idType dialog_id, idType last_msg_id, idType limit) override;
    int getMessageId() override;
private:
    idType id = 0;
    std::vector<Message> massive_messages;
};

#endif //PROJECT_DATA_MAP_H