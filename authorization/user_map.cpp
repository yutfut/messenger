#include "interface.h"
#include "map.h"

// USERS

User UserManagerMap::get_user(const std::string &login) {
    for (const auto& i : massive_users) {
        if (i.login == login) {
            return i;
        }
    }
    User user = create_user("", "");
    return user;
}

User UserManagerMap::create_user(const std::string &name, const std::string &login) {
    User user = {id, name, login, "", "", false, 0};
    id++;
    massive_users.push_back(user);
    return user;
}
