#include "data_sql.h"
#include "data_base.h"
#include <vector>
#include <string>
#include <sqlite3.h>
#include <iostream>
#include <cstdlib>

//SQL

int SQL::callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for (i = 0; i < 3; i++)
        argv[i] ? argv[i] : "NULL";
        std::string S = argv[i];
        if (i == 0) {
            user.id = atoi(S.c_str()); // strtol
        } else if (i == 1) {
            user.name = argv[i];
        } else {
            user.login = argv[i];
        }
    return 0;
}

void SQL::check(int k, const std::string s, char* zErrMsg) {
    if (k != SQLITE_OK) {
        std::cout << stderr << "SQL error: " << zErrMsg << "\n";
        std::cout << s;
    } else {
        std::cout << "Table " << s << " created successfully!\n";
    }
}

sqlite3* SQL::create_data_base() {
    int rc;
    char* sql;
    char* zErrMsg = 0;
    rc = sqlite3_open("data_base.db", &Db);
    if (rc) {
        std::cout << stderr << "Can't open database: " << sqlite3_errmsg(Db) << std::endl;
    } else {
        std::cout << "Opened database successfully!\n";
    }

    //delete already exists

    sql = "DROP TABLE USER;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sql = "DROP TABLE DIALOG;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sql = "DROP TABLE MESSAGE;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sql = "DROP TABLE DIALOG_MEMBERS;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);

    sql = "CREATE TABLE USER(" \
    "ID INTEGER," \
    "NAME VARCHAR(16)," \
    "LOGIN VARCHAR(32) PRIMARY KEY);";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"USER", zErrMsg);

    sql = "CREATE TABLE DIALOG(ID INTEGER);";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"DIALOG", zErrMsg);

    sql = "CREATE TABLE MESSAGE(" \
    "ID INTEGER AUTO_INCREMENT PRIMARY KEY," \
    "sender_id INTEGER, dialog_id INTEGER," \
    "message_text TEXT," \
    "time VARCHAR(8));";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"MESSAGE", zErrMsg);

    sql = "CREATE TABLE DIALOG_MEMBERS(" \
    "id INTEGER AUTO_INCREMENT," \
    "dialog_id INTEGER," \
    "member_id INTEGER);";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"DIALOG_MEMBERS", zErrMsg);
    callbackPointer = callback(void *NotUsed, int argc, char **argv, char **azColName);
    sqlite3_close(Db);
    return Db;
}

sqlite3* SQL::get_db() {
    return Db;
}

//USER

User UserManagerSQL::get_user(const std::string &login1) {
    sqlite3* Database;
    Database = get_db();
    sqlite3_open("data_base.db", &Database);
    sqlite3 *Db = get_db();
    const char* sql;

    sql = "INSERT INTO USER(ID, NAME, LOGIN) VALUES (1, 'ivan', 'login', " \
    "2, 'name', 'loginnnn');";
    sqlite3_exec(Database, sql, nullptr, nullptr, nullptr);

    sql = "SELECT `ID` FROM USER WHERE LOGIN = &login1";
    char **argv = {};
    char **azColName = {};
    int(*callbackPointer)();
    callbackPointer = SQL::callback(void *NotUsed, int argc, char **argv, char **azColName);
    callbackPointer();
    sqlite3_exec(Database, sql,
                 reinterpret_cast<int (*)(void *, int, char **, char **)>(SQL::callback(nullptr, 3, argv,
                                                                                        azColName)), nullptr, nullptr); //queryall

    //sql = "SELECT `NAME` FROM user WHERE (login1 == login)";
    //sqlite3_exec(Database, sql, nullptr, nullptr, nullptr);
    //user.name = Name;
    //std::cout << user.id;

    sqlite3_close(Db);
    return user;
}

idType UserManagerSQL::get_user_id(const std::string &login) {
    idType id;
    return id;
}

User UserManagerSQL::create_user(const std::string &name, const std::string &login) {
    User user;
    return user;
}