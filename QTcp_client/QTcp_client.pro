#-------------------------------------------------
#
# Project created by QtCreator 2011-10-13T22:35:09
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
        ../lib/src/message_protocol.cpp

HEADERS  += dialog.h \
            ../lib/headers/message_protocol.h


FORMS    += dialog.ui



