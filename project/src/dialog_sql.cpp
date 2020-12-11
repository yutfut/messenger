#include <sqlite3.h>
#include <iostream>
#include "sql.h"
#include "interface.h"
#include <string>
#include<cstdlib>

// DIALOGUES

int DialogManagerSQL::callback(void *NotUsed, int argc, char **argv, char **azColName) {
    std::vector<idType> *dlg_members = (std::vector<idType>*)NotUsed;
    for (int i = 0; i < argc; ++i) {
        std::string S = argv[i];
        dlg_members->push_back(atoi(S.c_str()));
    }
    return 0;
}

int DialogManagerSQL::callback_vec(void *NotUsed, int argc, char **argv, char **azColName) {
    Dialog dlg;
    std::vector<Dialog> *dlg_vector = (std::vector<Dialog>*)NotUsed;
    for (int i = 0; i < argc; ++i) {;
        dlg.id = atoi(argv[i]);
        dlg_vector->push_back(dlg);
    }
    return 0;
}

int DialogManagerSQL::callback_check(void *NotUsed, int argc, char **argv, char **azColName) {
    int* check_result  = (int*) NotUsed;
    if (check_result != nullptr) {
        check_result[0] = 1;
    } else {
        check_result[0] = 0;
    }
    return check_result[0] - 1;
}

int DialogManagerSQL::callback_id(void *NotUsed, int argc, char **argv, char **azColName) {
    Idr* id_result = (Idr*)NotUsed;
    id_result->id = atoi(argv[0]);
    return 0;
}

idType DialogManagerSQL::create_dlg(idType user_id, std::vector<idType> massive_customers) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql = "INSERT INTO DIALOG(ID) VALUES (NULL)";
    sqlite3_exec(Db,sql, nullptr, nullptr, nullptr);
    sql = "SELECT MAX(ID) FROM DIALOG";
    rc = sqlite3_exec(Db,sql, &DialogManagerSQL::callback_id, &id_result, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    DialogManagerSQL::add_members(id_result.id,massive_customers);
    sqlite3_close(Db);
    return id_result.id;
}

int DialogManagerSQL::add_members(idType dialog_id, std::vector<idType> members_to_add) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    for (unsigned int i = 0; i < members_to_add.size(); ++i) {
        sql = sqlite3_mprintf("INSERT INTO DIALOG_MEMBERS(DIALOG_ID, MEMBER_ID) VALUES (%d, %d)", dialog_id, members_to_add[i]);
        rc = sqlite3_exec(Db,sql, &DialogManagerSQL::callback, &dlg_members, nullptr);
        if (rc != SQLITE_OK) {
            std::cout << sqlite3_errmsg(Db);
        }
    }
    sqlite3_close(Db);
    return 0;
}

std::vector<Dialog> DialogManagerSQL::get_dialog (idType user_id, idType last_dlg_id, idType limit) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    if (last_dlg_id > limit) {
        sql = sqlite3_mprintf("SELECT DIALOG_ID FROM DIALOG_MEMBERS WHERE MEMBER_ID = %d AND DIALOG_ID "
                              "<= %d ORDER BY ID LIMIT %d;",user_id, last_dlg_id, limit);
        rc = sqlite3_exec(Db,sql, &DialogManagerSQL::callback_vec, &dlg_vector, nullptr);
        if (rc != SQLITE_OK) {
            std::cout << sqlite3_errmsg(Db);
        }
    } else {
        sql = sqlite3_mprintf("SELECT DIALOG_ID FROM DIALOG_MEMBERS WHERE MEMBER_ID = %d AND DIALOG_ID "
                              "<= %d ORDER BY ID LIMIT %d;",user_id, last_dlg_id, last_dlg_id);
        rc = sqlite3_exec(Db,sql, &DialogManagerSQL::callback_vec, &dlg_vector, nullptr);
        if (rc != SQLITE_OK) {
            std::cout << sqlite3_errmsg(Db);
        }
    }
    sqlite3_close(Db);
    return dlg_vector;
}

int DialogManagerSQL::is_user_in_dlg(idType dialog_id, idType user_id) {
    sqlite3_stmt* select_stmt;
    sqlite3_open("data_base.db", &Db);
    sql = sqlite3_mprintf("SELECT MEMBER_ID FROM DIALOG_MEMBERS WHERE DIALOG_ID = %d AND MEMBER_ID = %d;",dialog_id, user_id);
    sqlite3_exec(Db,sql,&DialogManagerSQL::callback_check, &check_result, nullptr);
    sqlite3_close(Db);
    return check_result;
}

std::vector<idType> DialogManagerSQL::get_users_in_dlg(idType dialog_id, idType user_id) {
    sqlite3_stmt* select_stmt;
    sqlite3_open("data_base.db", &Db);
    sql = sqlite3_mprintf("SELECT MEMBER_ID FROM DIALOG_MEMBERS WHERE DIALOG_id = %d AND MEMBER_ID != %d;",dialog_id, user_id);
    //sql = "SELECT MEMBER_ID FROM DIALOG_MEMBERS WHERE DIALOG_id = ? AND MEMBER_ID != ?;";
    //sqlite3_prepare_v2(Db,sql,-1,&select_stmt, nullptr);
    //sqlite3_bind_int(select_stmt,1,dialog_id);
    //sqlite3_bind_int(select_stmt,2,user_id);
    sqlite3_exec(Db,sql,&DialogManagerSQL::callback, &dlg_members, nullptr);
    sqlite3_close(Db);
    return dlg_members;
}
