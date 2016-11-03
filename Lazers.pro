#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T14:56:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
QT       += phonon

TARGET = Lazers
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    video.cpp \
    menu.cpp \
    gestionnaire_client.cpp \
    connectionbd.cpp \
    client.cpp \
    pub.cpp \
    plan.cpp \
    demande.cpp \
    chefcommerciale.cpp \
    gestionnairemarkting.cpp \
    g_marketing.cpp \
    formadmin.cpp \
    gerer_demande.cpp \
    recept.cpp
HEADERS  += mainwindow.h \
    video.h \
    menu.h \
    gestionnaire_client.h \
    connectionbd.h \
    client.h \
    pub.h \
    plan.h \
    demande.h \
    formadmin.h \
    gerer_demande.h \
    gestionnairemarkting.h \
    g_marketing.h \
    recept.h
FORMS    += mainwindow.ui \
    video.ui \
    menu.ui \
    gestionnairemarkting.ui \
    formadmin.ui
RESOURCES += \
    resources.qrc \
    aminee.qrc
