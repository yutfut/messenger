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
        ../project/src/data_map.cpp \
        ../project/src/data_sql.cpp \

HEADERS  += mainwindow.h \
            ../lib/header/message_protocol.h \
            ../project/include/data_map.h \
            ../project/include/data_sql.h \
            ../project/include/data_base.h \
            ../project/include/structures.h \

FORMS    += mainwindow.ui
