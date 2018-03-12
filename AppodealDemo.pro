#-------------------------------------------------
#
# Project created by QtCreator 2016-09-28T12:17:50
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AppodealDemo
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp 

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY =

android {
	ANDROID_PACKAGE_SOURCE_DIR += $$PWD/android
        APP_ABI = armeabi-v7a armeabi mips x86
}
include(Appodeal/Appodeal.pri)

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

RESOURCES += \
    assets.qrc
