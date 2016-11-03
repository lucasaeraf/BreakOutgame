#-------------------------------------------------
#
# Project created by QtCreator 2016-11-02T00:18:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BreakOutGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paddle.cpp \
    brick.cpp \
    ball.cpp \
    breakout.cpp

HEADERS  += mainwindow.h \
    paddle.h \
    brick.h \
    ball.h \
    breakout.h

FORMS    += mainwindow.ui
