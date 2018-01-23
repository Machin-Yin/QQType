#-------------------------------------------------
#
# Project created by QtCreator 2017-12-26T15:00:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MachinType
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


SOURCES += \
        main.cpp \
        machintype.cpp \
    headtool.cpp \
    sendarticle/sendarticle.cpp \
    sendarticle/leftwidget/customtoolbox.cpp \
    sendarticle/leftwidget/toolboxitem.cpp \
    sendarticle/rightwidget/articlewidget.cpp \
    sendarticle/rightwidget/customstack.cpp \
    sendarticle/rightwidget/rightwidget.cpp \
    sendarticle/rightwidget/wordwidget.cpp

HEADERS += \
        machintype.h \
    headtool.h \
    sendarticle/sendarticle.h \
    sendarticle/leftwidget/customtoolbox.h \
    sendarticle/leftwidget/toolboxitem.h \
    sendarticle/rightwidget/articlewidget.h \
    sendarticle/rightwidget/customstack.h \
    sendarticle/rightwidget/rightwidget.h \
    sendarticle/rightwidget/wordwidget.h

RESOURCES += \
    resource.qrc
