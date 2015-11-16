#-------------------------------------------------
#
# Project created by QtCreator 2015-11-01T15:35:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacman-Amu
TEMPLATE = app
CONFIG +=c++11

SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    point.cpp \
    score.cpp \
    power.cpp \
    maze.cpp \
    labyrinthe.cpp

HEADERS  += \
    game.h \
    player.h \
    point.h \
    score.h \
    power.h \
    maze.h \
    labyrinthe.h
