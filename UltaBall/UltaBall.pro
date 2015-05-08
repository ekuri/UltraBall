#-------------------------------------------------
#
# Project created by QtCreator 2015-04-19T11:54:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UltaBall
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ball.cpp \
    coreservice.cpp \
    wall.cpp \
    action.cpp \
    mainlayout.cpp \
    target.cpp

HEADERS  += mainwindow.h \
    ball.h \
    coreservice.h \
    wall.h \
    action.h \
    mainlayout.h \
    target.h

FORMS    += mainwindow.ui \
    mainlayout.ui

RESOURCES += \
    image.qrc
