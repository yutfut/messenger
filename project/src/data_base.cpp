#include <iostream>
#include <vector>
#include "data_base.h"
// Interface
user User_manager_map::get_user(id_type_t id) {
    for (auto i : massive_users) {
        if (i.id == id) {
            return i;
        }
    }
}

user User_manager_map::get_user(const std::string &name) {
    for (auto i : massive_users) {
        if (i.name == name) {
            return i;
        }
    }
}

id_type_t Dialog_manager_map::check_dialog_creation(id_type_t user_id, id_type_t address_id) {
    for (auto i : members_dlg_id) {
        if ((i.first == user_id && i.second == address_id) ||
            (i.first == address_id && i.second == user_id)) {
            return dialog_id;
        }
    }
    members_dlg_id.emplace_back(std::make_pair(user_id, address_id)); // добавляем в вектор пар айди пользователя и адресата
    dialog dialogue = {};
    dialogue.id = dialog_id;
    massive_dlg.push_back(dialogue); // добавляем в вектор диалогов айди диалога
    return dialog_id++;
}

id_type_t Dialog_manager_map::get_dialog_id (id_type_t user_id, id_type_t address_id) {
    return(check_dialog_creation(user_id, address_id));
}

std::vector<dialog> Dialog_manager_map::get_dialog (id_type_t user_id, id_type_t address_id, id_type_t last_dlg_id, size_t limit) {
    size_t size = massive_dlg.size();
    std::vector<dialog> dialogues;
    for (unsigned int i = size - 1; i > size - limit; --i) {
        dialogues.push_back(massive_dlg[i]);
    }
    return dialogues;
}

message Message_manager_map::create_message(message& message1) {
    massive_messages.push_back(message1);
}

std::vector<message> Message_manager_map::get_messages (id_type_t dialog_id, id_type_t last_msg_id, size_t limit) {
    size_t size = massive_messages.size();
    std::vector<message> messages;
    for (unsigned int i = size - 1; i > size - limit; --i) {
        messages.push_back(massive_messages[i]);
    }
    return messages;
}
