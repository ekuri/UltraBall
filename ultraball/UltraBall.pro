#-------------------------------------------------
#
# Project created by QtCreator 2015-04-19T11:54:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UltraBall
TEMPLATE = app


SOURCES += main.cpp\
    abstractball.cpp \
    physicalitem.cpp \
    item.cpp \
    commonball.cpp \
    gamelayout.cpp \
    coreservice.cpp \
    abstractwall.cpp \
    commonwall.cpp \
    debugwindow.cpp \
    commonballanimationitem.cpp \
    abstractanimationitem.cpp \
    targetanimationitem.cpp

HEADERS  += abstractball.h \
    physicalitem.h \
    itemtype.h \
    item.h \
    commonball.h \
    gamelayout.h \
    coreservice.h \
    paintservice.h \
    abstractwall.h \
    commonwall.h \
    ultraballhelper.h \
    debugwindow.h \
    commonballanimationitem.h \
    abstractanimationitem.h \
    targetanimationitem.h

FORMS    += \
    gamelayout.ui \
    debugwindow.ui

