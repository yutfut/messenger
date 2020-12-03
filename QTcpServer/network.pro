#-------------------------------------------------
#
# Project created by QtCreator 2011-10-28T11:20:51
#
#-------------------------------------------------
QT       += network
QT       += core gui network
QT       += widgets

TARGET = network
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        ../lib/src/message_protocol.cpp

HEADERS  += mainwindow.h \
            ../lib/header/message_protocol.h

FORMS    += mainwindow.ui
