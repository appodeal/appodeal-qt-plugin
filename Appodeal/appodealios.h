#ifndef APPODEALIOS_H
#define APPODEALIOS_H

#include <QObject>
#include "appodealinterface.h"
#include "signalreceiver.h"

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

class AppodealiOS: public AppodealInterface {
    
public:
    AppodealiOS();
    virtual ~AppodealiOS();
    virtual void initialize (const QString &appKey, const int &adType);
    virtual bool show (const int &adType);
    virtual bool show (const int &adType, const QString &placement);
    virtual void hide (const int &adType);
    virtual void setTesting(const bool &flag);
    virtual void setLogLevel (const int &level);
    virtual bool isLoaded (const int &adType);
    virtual bool isPrecache (const int &adType);
    virtual void cache (const int &adType);
    virtual void setAutoCache (const int &adType, const bool &flag);
    virtual void setTriggerOnLoadedOnPrecache (const int &adType, const bool &flag);
    virtual void setInterstitialCallback (InterstitialCallbacks* callback);
    virtual void setBannerCallback (BannerCallbacks* callbacks);
    virtual void setRewardedVideoCallback (RewardedVideoCallbacks* callbacks);
    virtual void disableNetwork(const QString &network);
    virtual void disableNetwork(const QString &network, const int &adType);
    virtual void disableLocationPermissionCheck();
    virtual void trackInAppPurchase (const QString &currencyCode, const int &amount);
    virtual void setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks);
    virtual void setAge (const int &age);
    virtual void setGender(const int &gender);
    virtual void setUserId(const QString &userId);
    virtual bool canShow(const int &adType);
    virtual bool canShow(const int &adType, const QString &placement);
    virtual void setChildDirectedTreatment(const bool &flag);
    virtual void muteVideosIfCallsMuted(const bool &flag);
    virtual void disableWriteExternalStoragePermissionCheck();
    virtual void requestAndroidMPermissions(/*callback*/);
    virtual void set728x90Banners(const bool &flag);
    virtual void setBannerAnimation(const bool &flag);
    virtual void setSmartBanners(const bool &flag);
    virtual void setCustomRule(const QString &name, const double &value);
    virtual void setCustomRule(const QString &name, const int &value);
    virtual void setCustomRule(const QString &name, const bool &value);
    virtual void setCustomRule(const QString &name, const QString &value);
    virtual void destroy(const int &adTypes);


    static SignalReceiver* signalReceiver;

    static void onNonSkippableVideoLoaded();
    static void onNonSkippableVideoFailedToLoad();
    static void onNonSkippableVideoShown();
    static void onNonSkippableVideoFinished();
    static void onNonSkippableVideoClosed(bool isFinished);
    static void onBannerLoaded(int height, bool isPrecache);
    static void onBannerFailedToLoad();
    static void onBannerShown();
    static void onBannerClicked();
    static void onInterstitialLoaded (bool isPrecache);
    static void onInterstitialFailedToLoad ();
    static void onInterstitialShown();
    static void onInterstitialClicked();
    static void onInterstitialClosed();
    static void onRewardedVideoLoaded ();
    static void onRewardedVideoFailedToLoad ();
    static void onRewardedVideoShown ();
    static void onRewardedVideoFinished (int i, const QString &s);
    static void onRewardedVideoClosed (bool isFinished);
    static void onSkippableVideoLoaded();
    static void onSkippableVideoFailedToLoad();
    static void onSkippableVideoShown();
    static void onSkippableVideoFinished();
    static void onSkippableVideoClosed(bool isFinished);

};

#endif // TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR

#endif // APPODEALIOS_H
