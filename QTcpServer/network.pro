#-------------------------------------------------
#
# Project created by QtCreator 2011-10-28T11:20:51
#
#-------------------------------------------------
QT       += network
QT       += core gui network
QT       += widgets

LIBS += -lsqlite3

TARGET = network
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        ../lib/src/message_protocol.cpp \
        ../project/src/dialog_sql.cpp \
        ../project/src/message_sql.cpp \
        ../project/src/user_sql.cpp \
        ../project/src/data_base.cpp \

HEADERS  += mainwindow.h \
            ../lib/header/message_protocol.h \
            ../project/include/sql.h \
            ../project/include/structures.h \
            ../project/include/interface.h \

FORMS    += mainwindow.ui
