SOURCES += \
     $$PWD/appodeal.cpp \
    $$PWD/jnicallbacks.cpp \
    $$PWD/videocallbacks.cpp \
    $$PWD/usersettings.cpp \
    $$PWD/appodealunsupported.cpp \
    $$PWD/appodealandroid.cpp \
    $$PWD/signalreceiver.cpp

HEADERS  += \
     $$PWD/appodeal.h \
     $$PWD/appodealinterface.h \
    $$PWD/interstitialcallbacks.h \
    $$PWD/bannercallbacks.h \
    $$PWD/videocallbacks.h \
    $$PWD/rewardedvideocallbacks.h \
    $$PWD/usersettings.h \
    $$PWD/appodealunsupported.h \
    $$PWD/appodealandroid.h \
    $$PWD/nonskippablevideocallbacks.h \
    $$PWD/signalreceiver.h \
    $$PWD/skippablevideocallbacks.h

android{
    QT += androidextras
	QT += gui-private
	
	DEFINES += PACKAGE_NAME=\\\"com/appodeal/test/AppodealActivity\\\"
	ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
	
}

