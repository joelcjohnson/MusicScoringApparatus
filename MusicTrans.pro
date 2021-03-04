#-------------------------------------------------
# Programmed by Ian Hudis
# Project created by QtCreator 2019-07-18T01:00:18
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MusicTrans
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += /usr/include/c++/6.3.0/


SOURCES += \
    gpio_input.cpp \
    gpio_output.cpp \
    main.cpp \
    mainwindow.cpp \
    sequencer.cpp \
    writefile.cpp


HEADERS  += \
    src/gpio_input.h \
    src/gpio_output.h \
    src/mainwindow.h \
    src/sequencer.h \
    src/writefile.h \

FORMS    += \
    mainwindow.ui \



LIBS += -L/usr/local/lib -lwiringPi
LIBS += -L/usr/local/lib -lwiringPiDev

LIBS += -L/usr/local/lib -lpthread


DISTFILES += \
    README.md

RESOURCES +=

SUBDIRS += \
    MusicTrans.pro
