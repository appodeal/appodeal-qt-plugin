#ifndef APPODEALINTERFACE
#define APPODEALINTERFACE

#include <QString>
#include "nonskippablevideocallbacks.h"
#include "bannercallbacks.h"
#include "interstitialcallbacks.h"
#include "rewardedvideocallbacks.h"

class AppodealInterface
{
public:
    virtual void initialize (const QString &appKey, const int &adType) = 0;
    virtual bool show (const int &adType) = 0;
    virtual bool show (const int &adType, const QString &placement) = 0;
    virtual void hide (const int &adType) = 0;
    virtual void setTesting(const bool &flag) = 0;
    virtual void setLogLevel (const int &level) = 0;
    virtual bool isLoaded (const int &adType) = 0;
    virtual bool isPrecache (const int &adType) = 0;
    virtual void cache (const int &adType) = 0;
    virtual void setAutoCache (const int &adType, const bool &flag) = 0;
    virtual void setTriggerOnLoadedOnPrecache (const int &adType, const bool &flag) = 0;
    virtual void setInterstitialCallback (InterstitialCallbacks* callback) = 0;
    virtual void setBannerCallback (BannerCallbacks* callbacks) = 0;
    virtual void setRewardedVideoCallback (RewardedVideoCallbacks* callbacks) = 0;
    virtual void disableNetwork(const QString &network) = 0;
    virtual void disableNetwork(const QString &network, const int &adType) = 0;
    virtual void disableLocationPermissionCheck() = 0;
    virtual void trackInAppPurchase (const QString &currencyCode, const int &amount) = 0;

    //new methods
    virtual void setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks) = 0;
    virtual void setAge (const int &age) = 0;
    virtual void setGender(const int &gender) = 0;
    virtual void setUserId(const QString &userId) =0;
    virtual bool canShow(const int &adType) =0;
    virtual bool canShow(const int &adType, const QString &placement) =0;
    virtual void setChildDirectedTreatment(const bool &flag) =0;
    virtual void muteVideosIfCallsMuted(const bool &flag) =0;
    virtual void disableWriteExternalStoragePermissionCheck() = 0;
    virtual void requestAndroidMPermissions(/*callback*/) = 0;
    virtual void set728x90Banners(const bool &flag) = 0;
    virtual void setBannerAnimation(const bool &flag) = 0;
    virtual void setSmartBanners(const bool &flag) = 0;
    virtual void setCustomRule(const QString &name, const double &value) = 0;
    virtual void setCustomRule(const QString &name, const int &value) = 0;
    virtual void setCustomRule(const QString &name, const bool &value) = 0;
    virtual void setCustomRule(const QString &name, const QString &value) = 0;
    virtual void destroy(const int &adTypes) = 0;
};

#endif // APPODEALINTERFACE
