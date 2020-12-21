#include <string>
#include <sqlite3.h>
#include <iostream>
#include "../include/sql.h"
#define USER_DELETED -8
#define USER_REGISTERED -10
#define USER_NOT_FOUND -12

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
            case 7:
                user->flag_delete_ser = atoi(argv[i]);
                break;
        }
    }
    return 0;
}

int UserManagerSQL::callback_delete(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    int *user_status = (int*) NotUsed;
    if (atoi(argv[0]) == 1) {
        *user_status = USER_DELETED;
    } else if (atoi(argv[0]) == 0) {
        *user_status = USER_REGISTERED;
    } else {
        *user_status = USER_NOT_FOUND;
    }
}

User UserManagerSQL::get_user(const std::string &login1) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("SELECT * FROM USER WHERE LOGIN = '%s' AND FLAG_DELETE_USER <> 1;",login1.c_str());
    rc = sqlite3_exec(Db, sql, &UserManagerSQL::callback, &user, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
    return user;
}

User UserManagerSQL::get_user(idType id) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("SELECT * FROM USER WHERE ID = '%d' AND FLAG_DELETE_USER <> 1;",id);
    rc = sqlite3_exec(Db, sql, &UserManagerSQL::callback, &user, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
    return user;
}

User UserManagerSQL::create_user(const std::string &name, const std::string &login, const std::string &salt, const std::string &password_hash) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql = sqlite3_mprintf("INSERT INTO USER(NAME, LOGIN, PASSWORD_HASH, RECOVERY_CODE,APPROVE_CODE,APPROVED,"
                          "FLAG_DELETE_USER) VALUES ('%s','%s','%s',0,0,0,0);",
                          name.c_str(), login.c_str(), password_hash.c_str(),0,0,0);
    sqlite3_exec(Db,sql, nullptr, nullptr, nullptr);
    sql = sqlite3_mprintf("INSERT INTO SAFETY(LOGIN, SALT) VALUES ('%s','%s');",
                          login.c_str(), salt.c_str());
    rc = sqlite3_exec(Db,sql, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
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

void UserManagerSQL::delete_user (const std::string &login) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("UPDATE USER SET FLAG_DELETE_USER = 1 WHERE LOGIN = '%s';",login.c_str());
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
}

void UserManagerSQL::recovery_user (const std::string &login) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("UPDATE USER SET FLAG_DELETE_USER = 0 WHERE LOGIN = '%s';",login.c_str());
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
}

int UserManagerSQL::check_status_user(const std::string &login) {
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("SELECT FLAG_DELETE_USER FROM USER WHERE LOGIN = '%s';",login.c_str());
    sqlite3_exec(Db, sql, &UserManagerSQL::callback_delete, &user_status, nullptr);
    sqlite3_close(Db);
    return user_status;
}

void UserManagerSQL::set_recovery_code (const std::string &login, int recovery_code) {
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("UPDATE USER SET RECOVERY_CODE = %d WHERE LOGIN = '%s';",recovery_code,login.c_str());
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sqlite3_close(Db);
}

void UserManagerSQL::set_password_hash (const std::string &login, std::string &password_hash) {
    sqlite3_open("data_base.db", &Db);
    sql =  sqlite3_mprintf("UPDATE USER SET PASSWORD_HASH = %s WHERE LOGIN = '%s';",password_hash.c_str(),login.c_str());
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sqlite3_close(Db);
}
