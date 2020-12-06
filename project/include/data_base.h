#ifndef PROJECT_DATA_BASE_H
#define PROJECT_DATA_BASE_H
#include <vector>
#include <string>
#include "structures.h"

// Interface

class IMessageManager {
public:
    virtual std::vector<Message> get_messages (idType dialog_id, idType last_msg_id, idType limit) = 0;
    virtual Message post_message (const Message& message) = 0;
};

class IUserManager {
public:
    virtual User get_user (const std::string& login) = 0;
    virtual idType get_user_id (const std::string& login) = 0;
    virtual User create_user (const std::string& name, const std::string& login) = 0;
};

class IDialogManager {
public:
    virtual std::vector<Dialog> get_dialog (idType user_id, idType last_dlg_id, idType limit) = 0;
    // virtual idType check_dialog_creation (idType user_id, idType address_id) = 0;
    virtual idType create_dlg_and_add_members (idType user_id, std::vector<idType> massive_customers) = 0;
};

#endif //PROJECT_DATA_BASE_H
