#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T12:17:50
#
#-------------------------------------------------
include(Appodeal/Appodeal.pri)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppodealDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \ 
    testappodeal.cpp


HEADERS  += mainwindow.h \ 
    testappodeal.h


FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

QT += testlib
