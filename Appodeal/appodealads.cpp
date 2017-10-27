#include "appodealads.h"

#include "appodealandroid.h"
#include "appodealios.h"
#include "appodealunsupported.h"

AppodealInterface* AppodealAds::appodeal = 0;

#if (__ANDROID_API__ >= 9)
const int AppodealAds::NONE                = 0;
const int AppodealAds::INTERSTITIAL        = 3;
const int AppodealAds::BANNER              = 4;
const int AppodealAds::BANNER_BOTTOM       = 8;
const int AppodealAds::BANNER_TOP          = 16;
const int AppodealAds::REWARDED_VIDEO      = 128;
const int AppodealAds::NON_SKIPPABLE_VIDEO = 128;
#else
const int AppodealAds::NONE                = 0;
const int AppodealAds::INTERSTITIAL        = 3;
const int AppodealAds::BANNER              = 4;
const int AppodealAds::BANNER_BOTTOM       = 8;
const int AppodealAds::BANNER_TOP          = 16;
const int AppodealAds::REWARDED_VIDEO      = 128;
const int AppodealAds::NON_SKIPPABLE_VIDEO = 256;
#endif

AppodealInterface* AppodealAds::getInstance(){
    if(!AppodealAds::appodeal){
        #if (__ANDROID_API__ >= 9)
            appodeal = new AppodealAndroid();
        #elif (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
            appodeal = new AppodealiOS();
        #else
            appodeal = new AppodealUnsupported();
        #endif
    }
    return AppodealAds::appodeal;
}

void AppodealAds::initialize (const QString &appKey, const int &adType){
    AppodealAds::getInstance()->initialize(appKey, adType);
}

bool AppodealAds::show (const int &adType){
    return AppodealAds::getInstance()->show(adType);
}

bool AppodealAds::show (const int &adType, const QString &placement){
    return AppodealAds::getInstance()->show(adType, placement);
}

void AppodealAds::hide (const int &adType){
    AppodealAds::getInstance()->hide(adType);
}
void AppodealAds::setTesting(const bool &flag){
    AppodealAds::getInstance()->setTesting(flag);
}
void AppodealAds::setLogLevel (const LogLevel &level){
    AppodealAds::getInstance()->setLogLevel(level);
}
bool AppodealAds::isLoaded (const int &adType){
    return AppodealAds::getInstance()->isLoaded(adType);
}
bool AppodealAds::isPrecache (const int &adType){
    return AppodealAds::getInstance()->isPrecache(adType);
}
void AppodealAds::cache (const int &adType){
    AppodealAds::getInstance()->cache(adType);
}
void AppodealAds::setAutoCache (const int &adType, const bool &flag){
    AppodealAds::getInstance()->setAutoCache(adType, flag);
}
void AppodealAds::setTriggerOnLoadedOnPrecache (const int &adType, const bool &flag){
    AppodealAds::getInstance()->setTriggerOnLoadedOnPrecache(adType, flag);
}
void AppodealAds::setInterstitialCallback (InterstitialCallbacks* callback){
    AppodealAds::getInstance()->setInterstitialCallback(callback);
}
void AppodealAds::setBannerCallback (BannerCallbacks* callbacks){
    AppodealAds::getInstance()->setBannerCallback(callbacks);
}
void AppodealAds::setRewardedVideoCallback (RewardedVideoCallbacks* callbacks){
    AppodealAds::getInstance()->setRewardedVideoCallback(callbacks);
}
void AppodealAds::disableNetwork(const QString &network){
    AppodealAds::getInstance()->disableNetwork(network);
}
void AppodealAds::disableNetwork(const QString &network, const int &adType){
    AppodealAds::getInstance()->disableNetwork(network, adType);
}
void AppodealAds::disableLocationPermissionCheck(){
    AppodealAds::getInstance()->disableLocationPermissionCheck();
}
void AppodealAds::trackInAppPurchase (const QString &currencyCode, const int &amount){
    AppodealAds::getInstance()->trackInAppPurchase(currencyCode, amount);
}

void AppodealAds::setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks){
    AppodealAds::getInstance()->setNonSkippableVideoCallback(callbacks);
}

void AppodealAds::setAge (const int &age){
    AppodealAds::getInstance()->setAge(age);
}

void AppodealAds::setGender(const Gender &gender){
    AppodealAds::getInstance()->setGender(gender);
}

void AppodealAds::setUserId(const QString &userId){
    AppodealAds::getInstance()->setUserId(userId);
}

bool AppodealAds::canShow(const int &adType){
    return AppodealAds::getInstance()->canShow(adType);
}

bool AppodealAds::canShow(const int &adType, const QString &placement){
    return AppodealAds::getInstance()->canShow(adType, placement);
}

void AppodealAds::setChildDirectedTreatment(const bool &flag){
    AppodealAds::getInstance()->setChildDirectedTreatment(flag);
}

void AppodealAds::muteVideosIfCallsMuted(const bool &flag){
    AppodealAds::getInstance()->muteVideosIfCallsMuted(flag);
}

void AppodealAds::disableWriteExternalStoragePermissionCheck(){
    AppodealAds::getInstance()->disableWriteExternalStoragePermissionCheck();
}

void AppodealAds::requestAndroidMPermissions(/*callback*/){
    AppodealAds::getInstance()->requestAndroidMPermissions();
}

void AppodealAds::set728x90Banners(const bool &flag){
    AppodealAds::getInstance()->set728x90Banners(flag);
}

void AppodealAds::setBannerAnimation(const bool &flag){
    AppodealAds::getInstance()->setBannerAnimation(flag);
}

void AppodealAds::setSmartBanners(const bool &flag){
    AppodealAds::getInstance()->setSmartBanners(flag);
}

void AppodealAds::setCustomRule(const QString &name, const double &value){
    AppodealAds::getInstance()->setCustomRule(name, value);
}

void AppodealAds::setCustomRule(const QString &name, const int &value){
    AppodealAds::getInstance()->setCustomRule(name, value);
}

void AppodealAds::setCustomRule(const QString &name, const bool &value){
    AppodealAds::getInstance()->setCustomRule(name, value);
}

void AppodealAds::setCustomRule(const QString &name, const QString &value){
    AppodealAds::getInstance()->setCustomRule(name, value);
}
