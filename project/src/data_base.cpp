#include <iostream>
#include <vector>
#include "data_base.h"

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

idType DialogManagerMap::check_dialog_creation(idType user_id, idType address_id) {
    for (const auto i : members_dlg_id) {
        if ((i.first == user_id && i.second == address_id) ||
            (i.first == address_id && i.second == user_id)) {
            return dialog_id;
        }
    }
    members_dlg_id.emplace_back(std::make_pair(user_id, address_id)); // добавляем в вектор пар айди пользователя и адресата
    Dialog dialogue = {};
    dialogue.id = dialog_id;
    massive_dlg.push_back(dialogue); // добавляем в вектор диалогов айди диалога
    return dialog_id++;
}

std::vector<Dialog> DialogManagerMap::get_dialog (idType user_id, idType address_id/*better to add login?*/, idType last_dlg_id/*why*/, size_t limit) {
    size_t size = massive_dlg.size();
    std::vector<Dialog> dialogues;
    if (size <= limit) {
        for (unsigned int i = size; i >= 1; --i) {
            dialogues.push_back(massive_dlg[i]);
        }
    } else {
        for (unsigned int i = size - 1; i > size - limit; --i) {
            dialogues.push_back(massive_dlg[i]);
        }
    }
    return dialogues;
}

// MESSAGES

Message MessageManagerMap::post_message(const Message& message1) {
    massive_messages.push_back(message1);
    id++;
    return message1;
}

std::vector<Message> MessageManagerMap::get_messages (idType dialog_id, idType last_msg_id/*why?really need?*/, size_t limit) {
    size_t size = massive_messages.size();
    std::vector<Message> messages;
    if (size <= limit) {
        for (unsigned int i = 0; i < size; ++i) {
            if (massive_messages[i].dialog_id == dialog_id) {
                messages.push_back(massive_messages[i]);
            }
        }
    } else {
        for (unsigned int i = size - limit; i > size - 1; ++i) {
            if (massive_messages[i].dialog_id == dialog_id) {
                messages.push_back(massive_messages[i]);
            }
        }
    }
    return messages;
}
