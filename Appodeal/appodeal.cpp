#include "appodeal.h"
#ifdef ANDROID
#include "appodealandroid.h"
#else
#include "appodealunsupported.h"
#endif

AppodealInterface* Appodeal::appodeal = 0;

const int Appodeal::NONE                = 0;
const int Appodeal::INTERSTITIAL        = 1;
const int Appodeal::SKIPPABLE_VIDEO     = 2;
const int Appodeal::BANNER              = 4;
const int Appodeal::BANNER_BOTTOM       = 8;
const int Appodeal::BANNER_TOP          = 16;
const int Appodeal::REWARDED_VIDEO      = 128;
const int Appodeal::NON_SKIPPABLE_VIDEO = 128;
const int Appodeal::ALL                 = 1023;

AppodealInterface* Appodeal::getInstance(){
    if(!Appodeal::appodeal){
#ifdef ANDROID
        qDebug("Android appodeal initialized");
        appodeal = new AppodealAndroid();
#else
        qDebug("Unsupported appodeal initialized");
        Appodeal::appodeal = new AppodealUnsupported();
#endif
    }
    return Appodeal::appodeal;
}

void Appodeal::clear()
{
    if(appodeal){
        qDebug("Appodeal destroyed");
        delete appodeal;
    }
}

void Appodeal::initialize (const QString &appKey, const int &adType){
    Appodeal::getInstance()->initialize(appKey, adType);
}
bool Appodeal::show (const int &adType){
    return Appodeal::getInstance()->show(adType);
}

bool Appodeal::show (const int &adType, const QString &placement){
    return Appodeal::getInstance()->show(adType, placement);
}

void Appodeal::hide (const int &adType){
    Appodeal::getInstance()->hide(adType);
}
void Appodeal::setTesting(const bool &flag){
    Appodeal::getInstance()->setTesting(flag);
}
void Appodeal::setLogLevel (const LogLevel &level){
    Appodeal::getInstance()->setLogLevel(level);
}
bool Appodeal::isLoaded (const int &adType){
    return Appodeal::getInstance()->isLoaded(adType);
}
bool Appodeal::isPrecache (const int &adType){
    return Appodeal::getInstance()->isPrecache(adType);
}
void Appodeal::cache (const int &adType){
    Appodeal::getInstance()->cache(adType);
}
void Appodeal::setAutoCache (const int &adType, const bool &flag){
    Appodeal::getInstance()->setAutoCache(adType, flag);
}
void Appodeal::setOnLoadedTriggerBoth (const int &adType, const bool &flag){
    Appodeal::getInstance()->setOnLoadedTriggerBoth(adType, flag);
}
void Appodeal::setInterstitialCallback (InterstitialCallbacks* callback){
    Appodeal::getInstance()->setInterstitialCallback(callback);
}
void Appodeal::setBannerCallback (BannerCallbacks* callbacks){
    Appodeal::getInstance()->setBannerCallback(callbacks);
}
void Appodeal::setSkippableVideoCallback (SkippalbeVideoCallbacks* callbacks){
    Appodeal::getInstance()->setSkippableVideoCallback(callbacks);
}
void Appodeal::setRewardedVideoCallback (RewardedVideoCallbacks* callbacks){
    Appodeal::getInstance()->setRewardedVideoCallback(callbacks);
}
void Appodeal::disableNetwork(const QString &network){
    Appodeal::getInstance()->disableNetwork(network);
}
void Appodeal::disableNetwork(const QString &network, const int &adType){
    Appodeal::getInstance()->disableNetwork(network, adType);
}
void Appodeal::disableLocationPermissionCheck(){
    Appodeal::getInstance()->disableLocationPermissionCheck();
}
void Appodeal::trackInAppPurchase (const QString &currencyCode, const int &amount){
    Appodeal::getInstance()->trackInAppPurchase(currencyCode, amount);
}

void Appodeal::setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks){
    Appodeal::getInstance()->setNonSkippableVideoCallback(callbacks);
}

void Appodeal::setAge (const int &age){
    Appodeal::getInstance()->setAge(age);
}

void Appodeal::setBirthday(const QString &bDay){
    Appodeal::getInstance()->setBirthday(bDay);
}

void Appodeal::setEmail(const QString &email){
    Appodeal::getInstance()->setEmail(email);
}

void Appodeal::setGender(const Gender &gender){
    Appodeal::getInstance()->setGender(gender);
}

void Appodeal::setInterests(const QString &interests){
    Appodeal::getInstance()->setInterests(interests);
}

void Appodeal::setOccupation(const Occupation &occupation){
    Appodeal::getInstance()->setOccupation(occupation);
}

void Appodeal::setRelation(const Relation &relation){
    Appodeal::getInstance()->setRelation(relation);
}

void Appodeal::setAlcohol(const Alcohol &alcohol){
    Appodeal::getInstance()->setAlcohol(alcohol);
}

void Appodeal::setSmoking(const Smoking &smoking){
    Appodeal::getInstance()->setSmoking(smoking);
}

void Appodeal::setUserId(const QString &userId){
    Appodeal::getInstance()->setUserId(userId);
}

void Appodeal::confirm(const int &adType){
    Appodeal::getInstance()->confirm(adType);
}

void Appodeal::disableWriteExternalStoragePermissionCheck(){
    Appodeal::getInstance()->disableWriteExternalStoragePermissionCheck();
}

void Appodeal::requestAndroidMPermissions(/*callback*/){
    Appodeal::getInstance()->requestAndroidMPermissions();
}

void Appodeal::set728x90Banners(const bool &flag){
    Appodeal::getInstance()->set728x90Banners(flag);
}

void Appodeal::setBannerAnimation(const bool &flag){
    Appodeal::getInstance()->setBannerAnimation(flag);
}

void Appodeal::setSmartBanners(const bool &flag){
    Appodeal::getInstance()->setSmartBanners(flag);
}

void Appodeal::setCustomRule(const QString &name, const double &value){
    Appodeal::getInstance()->setCustomRule(name, value);
}

void Appodeal::setCustomRule(const QString &name, const int &value){
    Appodeal::getInstance()->setCustomRule(name, value);
}

void Appodeal::setCustomRule(const QString &name, const bool &value){
    Appodeal::getInstance()->setCustomRule(name, value);
}

void Appodeal::setCustomRule(const QString &name, const QString &value){
    Appodeal::getInstance()->setCustomRule(name, value);
}
