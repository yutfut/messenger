#include <iostream>
#include <vector>

#include "../include/data_base.h"
#include "../include/data_map.h"

// USERS

idType UserManagerMap::get_user_id(const std::string &login) {
    for (const auto& i : massive_users) {
        if (i.login == login) {
            return i.id;
        }
    }
    idType id_user = 0;
    return id_user;
}

User UserManagerMap::get_user(const std::string &login) {
    for (const auto& i : massive_users) {
        if (i.login == login) {
            return i;
        }
    }
    User user = {};
    return user;
}

User UserManagerMap::create_user(const std::string &name, const std::string &login) {
    User user = {id, name, login};
    id++;
    massive_users.push_back(user);
    return user;
}

// DIALOGUES

idType DialogManagerMap::create_dlg (idType user_id, std::vector<idType> massive_customers) {
    for (const auto i : massive_customers) {
        members_dlg_id.emplace_back(dialog_id, massive_customers[i]);
    }
    return dialog_id++;
}

int DialogManagerMap::add_members(idType dialog_id, idType future_member_id, std::vector<idType> members_to_add) {
    for (size_t i = 0; i < members_to_add.size(); ++i) {
        members_dlg_id.push_back(std::pair<idType, idType>(dialog_id, members_to_add[i]));
    }
    return 0;
}

int DialogManagerMap::getUserIdInDialogues(idType dialogID, int &user_id) {
    if (members_dlg_id.size() == 1) {
        return members_dlg_id[0].second;
    } else {
        for(size_t i = 0; i < members_dlg_id.size(); ++i) {
            if (members_dlg_id[i].first == dialogID && members_dlg_id[i].second != user_id) {
                std::cout << members_dlg_id[i].second << " " << user_id << std::endl;
                return members_dlg_id[i].second;
            }
        }
    }
    return -1;
}

int DialogManagerMap::isUserInDialog(idType dialogID, idType &userID) {
    bool isDialogID_existed = false;
    for(size_t i = 0; i < members_dlg_id.size(); ++i) {
        if (members_dlg_id[i].first == dialogID && members_dlg_id[i].second == userID) {
            return 1;
        } else if (members_dlg_id[i].first == dialogID) {
            isDialogID_existed = true;
        }
    }
    return isDialogID_existed - 1;
}

std::vector<Dialog> DialogManagerMap::get_dialog (idType user_id, idType last_dlg_id/*why*/, idType limit) {
    std::vector<Dialog> dialogues;
    last_dlg_id = dialog_id;
    if (last_dlg_id <= limit) {
        for (unsigned int i = last_dlg_id; i >= 1; --i) {
            dialogues.push_back(massive_dlg[i]);
        }
    } else {
        for (unsigned int i = last_dlg_id - 1; i > last_dlg_id - limit; --i) {
            dialogues.push_back(massive_dlg[i]);
        }
    }
    return dialogues;
}

// MESSAGES

Message MessageManagerMap::post_message(const Message& message) {
    massive_messages.push_back(message);
    id++;
    return message;
}

int MessageManagerMap::getMessageId() {
    return id;
}

std::vector<Message> MessageManagerMap::get_messages (idType dialog_id, idType last_msg_id, idType limit) {
    std::vector<Message> messages;
    last_msg_id = id;
    if (last_msg_id <= limit) {
        for (unsigned int i = 0; i < last_msg_id; ++i) {
            if (massive_messages[i].dialog_id == dialog_id) {
                messages.push_back(massive_messages[i]);
            }
        }
    } else {
        for (unsigned int i = last_msg_id- limit; i > last_msg_id - 1; ++i) {
            if (massive_messages[i].dialog_id == dialog_id) {
                messages.push_back(massive_messages[i]);
            }
        }
    }
    return messages;
}
