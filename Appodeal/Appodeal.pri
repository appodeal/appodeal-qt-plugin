SOURCES += \
    $$PWD/jnicallbacks.cpp \
    $$PWD/usersettings.cpp \
    $$PWD/appodealunsupported.cpp \
    $$PWD/appodealandroid.cpp \
    $$PWD/signalreceiver.cpp \
    $$PWD/appodealads.cpp

HEADERS  += \
    $$PWD/appodealinterface.h \
    $$PWD/interstitialcallbacks.h \
    $$PWD/bannercallbacks.h \
    $$PWD/rewardedvideocallbacks.h \
    $$PWD/usersettings.h \
    $$PWD/appodealunsupported.h \
    $$PWD/appodealandroid.h \
    $$PWD/nonskippablevideocallbacks.h \
    $$PWD/signalreceiver.h \
    $$PWD/skippablevideocallbacks.h \
    $$PWD/appodealads.h \
    $$PWD/appodealios.h

android {
    QT += androidextras
    QT += gui-private
	
    DEFINES += PACKAGE_NAME=\\\"com/appodeal/test/AppodealActivity\\\"
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
}

ios {
    QMAKE_IOS_DEPLOYMENT_TARGET = 8.0

    QMAKE_INFO_PLIST = $$PWD/ios/Info.plist
    OBJECTIVE_SOURCES += $$PWD/ios/src/appodealObjC.mm
    QMAKE_LFLAGS += -ObjC

    APPODEAL_SDK_DIR = $$PWD/ios/libs
    LIBS += -F $$APPODEAL_SDK_DIR -framework Appodeal
    LIBS += -lc++
    LIBS += -lsqlite3
    LIBS += -lxml2.2
    LIBS += -lz
    LIBS += -framework AdSupport
    LIBS += -framework AudioToolbox
    LIBS += -framework AVFoundation
    LIBS += -framework CFNetwork
    LIBS += -framework CoreFoundation
    LIBS += -framework CoreGraphics
    LIBS += -framework CoreImage
    LIBS += -framework CoreLocation
    LIBS += -framework CoreMedia
    LIBS += -framework CoreMotion
    LIBS += -framework CoreTelephony
    LIBS += -framework CoreBluetooth
    LIBS += -framework EventKit
    LIBS += -framework EventKitUI
    LIBS += -framework MediaPlayer
    LIBS += -framework MessageUI
    LIBS += -framework MobileCoreServices
    LIBS += -framework QuartzCore
    LIBS += -framework Security
    LIBS += -framework Social
    LIBS += -framework StoreKit
    LIBS += -framework SystemConfiguration
    LIBS += -framework Twitter
    LIBS += -framework UIKit
    LIBS += -framework WebKit
    LIBS += -framework JavaScriptCore
    LIBS += -framework GLKit
    LIBS += -framework SafariServices

    appodeal_bundle.files = $$files($$APPODEAL_SDK_DIR/Resources/*)
    QMAKE_BUNDLE_DATA += appodeal_bundle
}

