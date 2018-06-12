#-------------------------------------------------
#
# Project created by QtCreator 2018-05-20T22:57:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Flappybrids
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ave.cpp \
    obstaculo.cpp \
    nube.cpp \
    gameover.cpp \
    avion.cpp \
    insecto.cpp \
    form.cpp \
    menu.cpp \
    pause.cpp

HEADERS += \
        mainwindow.h \
    ave.h \
    obstaculo.h \
    nube.h \
    gameover.h \
    avion.h \
    insecto.h \
    form.h \
    menu.h \
    pause.h

FORMS += \
        mainwindow.ui \
    gameover.ui \
    form.ui \
    menu.ui \
    pause.ui

RESOURCES += \
    imagenes.qrc
