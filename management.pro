#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T16:13:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = management
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    link.cpp \
    linklist.cpp \
    queue.cpp

HEADERS  += mainwindow.h \
    link.h \
    linklist.h \
    queue.h \
    hanshu.h

FORMS    += mainwindow.ui
