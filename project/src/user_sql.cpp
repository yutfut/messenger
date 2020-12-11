#include <string>
#include <sqlite3.h>
#include <iostream>
#include "sql.h"

//USER

int UserManagerSQL::callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    User *user = (User*)NotUsed;
    for (i = 0; i < argc; ++i) {
        if (i == 0) {
            user->id = atoi(argv[i]);
        } else if (i == 1) {
            user->name = argv[i];
        } else {
            user->login = argv[i];
        }
    }
    return 0;
}

User UserManagerSQL::get_user(const std::string &login1) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("SELECT * FROM USER WHERE LOGIN = '%s';",login1.c_str());
    rc = sqlite3_exec(Db, sql, &UserManagerSQL::callback, &user, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
    return user;
}

User UserManagerSQL::create_user(const std::string &name, const std::string &login) {
    sqlite3_stmt* insert_stmt;
    sqlite3_open("data_base.db", &Db);
    sql = sqlite3_mprintf("INSERT INTO USER(NAME, LOGIN) VALUES ('%s','%s');", name.c_str(), login.c_str());
    sqlite3_exec(Db,sql, nullptr, nullptr, nullptr);
    sqlite3_close(Db);
    return user;
}
