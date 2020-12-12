#include <string>
#include <sqlite3.h>
#include <iostream>
#include "../project/include/sql.h"

//SQL

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
    sql = "DROP TABLE USER;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sql = "DROP TABLE DIALOG;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sql = "DROP TABLE MESSAGE;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);
    sql = "DROP TABLE DIALOG_MEMBERS;";
    sqlite3_exec(Db, sql, nullptr, nullptr, nullptr);

    sql = "CREATE TABLE USER(" \
    "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
    "NAME VARCHAR(16)," \
    "LOGIN VARCHAR(32));";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"USER", zErrMsg);

    sql = "CREATE TABLE DIALOG(" \
    "ID INTEGER  PRIMARY KEY AUTOINCREMENT NOT NULL);";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"DIALOG", zErrMsg);

    // СДЕЛАТЬ TIME ТИПА DEFAULT CURRENT_TIMESTAMP

    sql = "CREATE TABLE MESSAGE(" \
    "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
    "SENDER_ID INTEGER," \
    "DIALOG_ID INTEGER," \
    "MESSAGE_TEXT TEXT," \
    "TIME VARCHAR(8)," \
    "FOREIGN KEY(SENDER_ID) REFERENCES USER(ID)" \
    "FOREIGN KEY(DIALOG_ID) REFERENCES DIALOG(ID));";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"MESSAGE", zErrMsg);

    sql = "CREATE TABLE DIALOG_MEMBERS(" \
    "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
    "DIALOG_ID INTEGER," \
    "MEMBER_ID INTEGER," \
    "FOREIGN KEY (DIALOG_ID) REFERENCES DIALOG(ID)" \
    "FOREIGN KEY (MEMBER_ID) REFERENCES USER(ID));";
    rc = sqlite3_exec(Db, sql, nullptr, nullptr, &zErrMsg);
    check(rc,"DIALOG_MEMBERS", zErrMsg);
    sqlite3_close(Db);
    return Db;
}

sqlite3* SQL::get_db() {
    return Db;
}
