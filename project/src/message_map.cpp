#include <iostream>
#include <vector>
#include "../include/interface.h"
#include "../include/map.h"

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
