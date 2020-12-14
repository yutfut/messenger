#include <iostream>
#include <vector>
#include "../include/interface.h"
#include "../include/map.h"

// DIALOGUES

idType DialogManagerMap::create_dlg (idType user_id, std::vector<idType> massive_customers) {
    for (const auto i : massive_customers) {
        members_dlg_id.emplace_back(dialog_id, massive_customers[i]);
    }
    return dialog_id++;
}

int DialogManagerMap::add_members(idType dialog_id, std::vector<idType> members_to_add) {
    for (size_t i = 0; i < members_to_add.size(); ++i) {
        members_dlg_id.push_back(std::pair<idType, idType>(dialog_id, members_to_add[i]));
    }
    return 0;
}

std::vector<idType> DialogManagerMap::get_users_in_dlg(idType dialog_id) {
    std::vector<idType> v;
    for(unsigned int i = 0; i < members_dlg_id.size(); ++i) {
        if (members_dlg_id[i].first == dialog_id) {
            v.push_back(members_dlg_id[i].second);
        }
    }
    return v;
}

int DialogManagerMap::is_user_in_dlg(idType dialog_id, idType user_id) {
    bool isDialogID_existed = false;
    for(size_t i = 0; i < members_dlg_id.size(); ++i) {
        if (members_dlg_id[i].first == dialog_id && members_dlg_id[i].second == user_id) {
            return 1;
        } else if (members_dlg_id[i].first == dialog_id) {
            isDialogID_existed = true;
        }
    }
    return isDialogID_existed - 1;
}

std::vector<Dialog> DialogManagerMap::get_dialog (idType user_id, idType last_dlg_id, idType limit) {
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
