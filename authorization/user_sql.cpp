#include <string>
#include <sqlite3.h>
#include <iostream>

#include "sql.h"

//USER
UserManagerSQL::UserManagerSQL() {
    if (!Db) {
        Db = this->create_data_base();
    }
}

int UserManagerSQL::callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    User *user = (User*)NotUsed;
    for (i = 0; i < argc; ++i) {
        switch(i) {
            case 0:
                user->id = atoi(argv[i]);
                break;
            case 1:
                user->name = argv[i];
                break;
            case 2:
                user->login = argv[i];
                break;
            case 3:
                user->salt = argv[i];
                break;
            case 4:
                user->password_hash = argv[i];
                break;
            case 5:
                user->approved = atoi(argv[i]);
                break;
            case 6:
                user->approve_code = atoi(argv[i]);
                break;
        }
    }
    return 0;
}

User UserManagerSQL::get_user(const std::string &login1) {
    int rc;
    sqlite3_stmt* select_stmt;
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("SELECT * FROM USER WHERE LOGIN = '%s';",login1.c_str());
    /*sql = "SELECT * FROM USER WHERE LOGIN = ?";
    rc = sqlite3_prepare_v2(Db,sql,-1,&select_stmt, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_bind_text(select_stmt,1,login1.c_str(),-1,SQLITE_STATIC);*/
    rc = sqlite3_exec(Db, sql, &UserManagerSQL::callback, &user, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
    return user;
}

User UserManagerSQL::get_user(idType id) {
    int rc;
    sqlite3_stmt* select_stmt;
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("SELECT * FROM USER WHERE LOGIN = '%d';",id);
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

User UserManagerSQL::set_user_approved (const std::string& login, int approved) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql = sqlite3_mprintf("UPDATE USER SET APPROVED = %d WHERE LOGIN = %s;", approved, login.c_str());
    rc = sqlite3_exec(Db,sql, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
}
