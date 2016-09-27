SOURCES += \
     $$PWD/appodeal.cpp \
    $$PWD/interstitialcallbacks.cpp \
    $$PWD/jnicallbacks.cpp \
    $$PWD/bannercallbacks.cpp \
    $$PWD/videocallbacks.cpp \
    $$PWD/rewardedvideocallbacks.cpp \
    $$PWD/usersettings.cpp

HEADERS  += \
     $$PWD/appodeal.h \
     $$PWD/appodealinterface.h \
    $$PWD/interstitialcallbacks.h \
    $$PWD/bannercallbacks.h \
    $$PWD/videocallbacks.h \
    $$PWD/rewardedvideocallbacks.h \
    $$PWD/usersettings.h

DEFINES += PACKAGE_NAME=\\\"com/example/kian/apptest/AppodealActivity\\\"
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
