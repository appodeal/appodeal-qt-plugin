#include "appodealunsupported.h"

AppodealUnsupported::AppodealUnsupported() { }

void AppodealUnsupported::initialize(const QString &appKey, const int &adType){
    //Hide unused parameter warning
    (void)appKey; (void)adType;
    qInfo("Appodeal disabled");
}
bool AppodealUnsupported::show(const int &adType){
    (void)adType;
    qInfo("Appodeal disabled");
    return false;
}
bool AppodealUnsupported::show(const int &adType, const QString &placement){
    (void)adType; (void)placement;
    qInfo("Appodeal disabled");
    return false;
}
void AppodealUnsupported::hide(const int &adType){
    (void)adType;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setTesting(const bool &flag){
    (void)flag;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setLogLevel(const int &level){
    (void)level;
    qInfo("Appodeal disabled");
}
bool AppodealUnsupported::isLoaded(const int &adType){
    (void)adType;
    qInfo("Appodeal disabled");
    return false;
}
bool AppodealUnsupported::isPrecache(const int &adType){
    (void)adType;
    qInfo("Appodeal disabled");
    return false;
}
void AppodealUnsupported::cache(const int &adType){
    (void)adType;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setAutoCache(const int &adType, const bool &flag){
    (void)adType; (void)flag;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setTriggerOnLoadedOnPrecache(const int &adType, const bool &flag){
    (void)adType; (void)flag;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setInterstitialCallback(InterstitialCallbacks* callback){
    (void)callback;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setBannerCallback (BannerCallbacks* callbacks){
    (void)callbacks;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setRewardedVideoCallback(RewardedVideoCallbacks* callbacks){
    (void)callbacks;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::disableNetwork(const QString &network){
    (void)network;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::disableNetwork(const QString &network, const int &adType){
    (void)network; (void)adType;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::disableLocationPermissionCheck(){qInfo("Appodeal disabled");}
void AppodealUnsupported::trackInAppPurchase (const QString &currencyCode, const int &amount){
    (void)currencyCode; (void) amount;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks){qInfo("Appodeal disabled");}
void AppodealUnsupported::setAge (const int &age){
    (void) age;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setGender(const int &gender){
    (void)gender;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setUserId(const QString &userId){
    (void)userId;
    qInfo("Appodeal disabled");
}
bool AppodealUnsupported::canShow(const int &adType){
    (void)adType;
    qInfo("Appodeal disabled");
    return false;
}
bool AppodealUnsupported::canShow(const int &adType, const QString &placement){
    (void)adType;
    (void)placement;
    qInfo("Appodeal disabled");
    return false;
}
void AppodealUnsupported::setChildDirectedTreatment(const bool &flag){
    (void)flag;
    qInfo("Appodeal disabled");
}

void AppodealUnsupported::muteVideosIfCallsMuted(const bool &flag){
    (void)flag;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::disableWriteExternalStoragePermissionCheck(){qInfo("Appodeal disabled");}
void AppodealUnsupported::requestAndroidMPermissions(/*callback*/){qInfo("Appodeal disabled");}
void AppodealUnsupported::set728x90Banners(const bool &flag){
    (void)flag;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setBannerAnimation(const bool &flag){
    (void)flag;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setSmartBanners(const bool &flag){
    (void)flag;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setCustomRule(const QString &name, const double &value){
    (void)name; (void)value;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setCustomRule(const QString &name, const int &value){
    (void)name; (void)value;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setCustomRule(const QString &name, const bool &value){
    (void)name; (void)value;
    qInfo("Appodeal disabled");
}
void AppodealUnsupported::setCustomRule(const QString &name, const QString &value){
    (void)name; (void)value;
    qInfo("Appodeal disabled");
}
AppodealUnsupported::~AppodealUnsupported(){}
