#ifdef ANDROID

#ifndef APPODEALANDROID_H
#define APPODEALANDROID_H

#include "appodealinterface.h"
#include "jni.h"
#include "signalreceiver.h"
#include <QObject>

class QAndroidJniObject;

class AppodealAndroid: public AppodealInterface, public QObject
{
public:
    AppodealAndroid();
    ~AppodealAndroid();
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

    friend JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*);
private:
    QAndroidJniObject* m_Appodeal;

    static SignalReceiver* signalReceiver;
    //Static callbacks for interaction with java
    static void onNonSkippableVideoLoaded();
    static void onNonSkippableVideoFailedToLoad();
    static void onNonSkippableVideoShown();
    static void onNonSkippableVideoFinished();
    static void onNonSkippableVideoClosed(JNIEnv *, jobject, jboolean isFinished);
    static void onBannerLoaded(JNIEnv *, jobject, jint height, jboolean isPrecache);
    static void onBannerFailedToLoad();
    static void onBannerShown();
    static void onBannerClicked();
    static void onInterstitialLoaded (JNIEnv *, jobject, jboolean isPrecache);
    static void onInterstitialFailedToLoad ();
    static void onInterstitialShown();
    static void onInterstitialClicked();
    static void onInterstitialClosed();
    static void onRewardedVideoLoaded ();
    static void onRewardedVideoFailedToLoad ();
    static void onRewardedVideoShown ();
    static void onRewardedVideoFinished (JNIEnv *, jobject, jint i, jstring s);
    static void onRewardedVideoClosed (JNIEnv *, jobject, jboolean isFinished);
    static void onSkippableVideoLoaded();
    static void onSkippableVideoFailedToLoad();
    static void onSkippableVideoShown();
    static void onSkippableVideoFinished();
    static void onSkippableVideoClosed(JNIEnv *, jobject, jboolean isFinished);
};

#endif // APPODEALANDROID_H

#endif // ANDROID
