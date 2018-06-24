#-------------------------------------------------
#
# Project created by QtCreator 2018-05-27T23:23:38
#
#-------------------------------------------------

QT       += core gui
QT += core gui widgets multimedia multimediawidgets
CONFIG   += resources_big
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test_vision1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    attribute.cpp \
    load_interface.cpp \
    run_interface.cpp \
    skill.cpp \
    player.cpp \
    interface.cpp \
    monster.cpp \
    system.cpp \
    equipment.cpp \
    mission_system.cpp \
    bag_system.cpp \
    setting_system.cpp \
    player_system.cpp \
    npc.cpp \
    fight_interface.cpp \
    weapon.cpp \
    map_game.cpp \
    world.cpp \
    monster_manual.cpp \
    object.cpp \
    money_system.cpp \
    pic1.cpp \
    position.cpp

HEADERS  += mainwindow.h \
    attribute.h \
    load_interface.h \
    run_interface.h \
    skill.h \
    player.h \
    interface.h \
    monster.h \
    system.h \
    equipment.h \
    mission_system.h \
    bag_system.h \
    setting_system.h \
    player_system.h \
    npc.h \
    fight_interface.h \
    weapon.h \
    map_game.h \
    world.h \
    monster_manual.h \
    object.h \
    money_system.h \
    position.h

FORMS    += mainwindow.ui

RESOURCES += \
    pic.qrc \
    pic2.qrc \
    pic1.qrc
