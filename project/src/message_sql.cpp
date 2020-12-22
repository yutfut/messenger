#include <sqlite3.h>
#include <iostream>
#include <string>
#include "../include/sql.h"

int MessageManagerSQL::callback_vec(void *NotUsed, int argc, char **argv, char **azColName) {
    std::vector<Message> *msg = (std::vector<Message>*)NotUsed;
    Message mes;
    for (int i = 0; i < argc; ++i) {
        if (i % 6 == 0) {
            mes.id = atoi(argv[i]);
        } else if (i % 6 == 1) {
            mes.sender_id = atoi(argv[i]);
        } else if (i % 6 == 2) {
            mes.dialog_id = atoi(argv[i]);
        } else if (i % 6 == 3) {
            mes.text = argv[i];
        } else if (i % 6 == 4) {
            mes.data = argv[i];
        } else {
            mes.time = argv[i];
            msg->push_back(mes);
        }
    }
    return 0;
}

int MessageManagerSQL::callback_mes(void *NotUsed, int argc, char **argv, char **azColName) {
    Message *msg = (Message*)NotUsed;
    for (int i = 0; i < argc; ++i) {
        if (i == 0) {
            msg->id = atoi(argv[i]);
        } else if (i == 1) {
            msg->sender_id = atoi(argv[i]);
        } else if (i == 2) {
            msg->dialog_id = atoi(argv[i]);
        } else if (i == 3) {
            msg->text = argv[i];
        } else if (i == 4) {
            msg->data = argv[i];
        } else {
            msg->time = argv[i];
        }
    }
    return 0;
}

idType MessageManagerSQL::callback_id(void *NotUsed, int argc, char **argv, char **azColName) {
    LastMessage *the_last_message_id = (LastMessage *)NotUsed;
    the_last_message_id->last_msg_id = atoi(argv[0]);
    return 0;
}

std::vector<Message> MessageManagerSQL::get_messages(idType dialog_id, idType last_msg_id, idType limit) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql = sqlite3_mprintf("SELECT * FROM MESSAGE WHERE DIALOG_ID = %d AND ID <= %d AND "
                          "FLAG_DELETE_MESSAGE <> 1 ORDER BY ID DESC LIMIT %d;",dialog_id,last_msg_id, limit);
    rc = sqlite3_exec(Db,sql, &MessageManagerSQL::callback_vec, &msg_vector, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
    return msg_vector;
}

Message MessageManagerSQL::post_message(const Message &message) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql = sqlite3_mprintf("INSERT INTO MESSAGE(SENDER_ID, DIALOG_ID, MESSAGE_TEXT,DATA,TIME,FLAG_DELETE_MESSAGE) "
                          "VALUES (%d,%d,'%s','%s','%s',0)",message.sender_id,message.dialog_id,
                          message.text.c_str(),message.data.c_str(),message.time.c_str());
    rc = sqlite3_exec(Db,sql, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sql = "SELECT * FROM MESSAGE;";
    sqlite3_exec(Db,sql,&MessageManagerSQL::callback_mes,&msg, nullptr);
    sqlite3_close(Db);
    return msg;
}

int MessageManagerSQL::get_message_id() {
    int rc;
    sqlite3_open("data_base.db", &Db);
    sql = "SELECT ID FROM MESSAGE ORDER BY ID DESC LIMIT 1;";
    rc = sqlite3_exec(Db,sql,&MessageManagerSQL::callback_id, &the_last_message_id, nullptr);
    if (rc != SQLITE_OK) {
        std::cout << sqlite3_errmsg(Db);
    }
    sqlite3_close(Db);
    return the_last_message_id.last_msg_id;
}


void MessageManagerSQL::delete_messages(std::vector<Message> messages_id) {
    int rc;
    sqlite3_open("data_base.db", &Db);
    for (unsigned int i = 0; i < messages_id.size(); ++i) {
        sql = sqlite3_mprintf("UPDATE MESSAGE SET FLAG_DELETE_MESSAGE = 1 WHERE ID = %d", messages_id[i].id);
        sqlite3_exec(Db,sql, nullptr, nullptr, nullptr);
    }
    sqlite3_close(Db);
}

void MessageManagerSQL::forward_messages (std::vector<Message> messages_id) {

}