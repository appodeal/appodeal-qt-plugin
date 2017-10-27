#ifndef APPODEALADS_H
#define APPODEALADS_H

#include "appodealinterface.h"

class AppodealAds
{
public:
    enum Gender{MALE=0, FFEMALE=1, OTHER=2};
    enum LogLevel{none=2, debug=0, verbose=1};
    static const int NONE;
    static const int INTERSTITIAL;
    static const int BANNER;
    static const int BANNER_BOTTOM;
    static const int BANNER_TOP;
    static const int REWARDED_VIDEO;
    static const int NON_SKIPPABLE_VIDEO;

    static void initialize (const QString &appKey, const int &adType);
    static bool show (const int &adType);
    static bool show (const int &adType, const QString &placement);
    static void hide (const int &adType);
    static void setTesting(const bool &flag);
    static void setLogLevel (const LogLevel &level);
    static bool isLoaded (const int &adType);
    static bool isPrecache (const int &adType);
    static void cache (const int &adType);
    static void setAutoCache (const int &adType, const bool &flag);
    static void setTriggerOnLoadedOnPrecache (const int &adType, const bool &flag);
    static void setInterstitialCallback (InterstitialCallbacks* callback);
    static void setBannerCallback (BannerCallbacks* callbacks);
    static void setRewardedVideoCallback (RewardedVideoCallbacks* callbacks);
    static void disableNetwork(const QString &network);
    static void disableNetwork(const QString &network, const int &adType);
    static void disableLocationPermissionCheck();
    static void trackInAppPurchase (const QString &currencyCode, const int &amount);

    static void setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks);
    static void setAge (const int &age);
    static void setGender(const Gender &gender);
    static void setUserId(const QString &userId);
    static bool canShow(const int &adType);
    static bool canShow(const int &adType, const QString &placement);
    static void setChildDirectedTreatment(const bool &flag);
    static void muteVideosIfCallsMuted(const bool &flag);
    static void disableWriteExternalStoragePermissionCheck();
    static void requestAndroidMPermissions(/*callback*/);
    static void set728x90Banners(const bool &flag);
    static void setBannerAnimation(const bool &flag);
    static void setSmartBanners(const bool &flag);
    static void setCustomRule(const QString &name, const double &value);
    static void setCustomRule(const QString &name, const int &value);
    static void setCustomRule(const QString &name, const bool &value);
    static void setCustomRule(const QString &name, const QString &value);

private:
    static AppodealInterface* appodeal;
    static AppodealInterface* getInstance();
};

#endif // APPODEALADS_H
