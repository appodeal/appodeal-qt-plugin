#include <QString>
#include <jni.h>
#include "interstitialcallbacks.h"
#include "bannercallbacks.h"
#include "videocallbacks.h"
#include "rewardedvideocallbacks.h"


//create a vector with all our JNINativeMethod(s)
static JNINativeMethod methods[] =
{
    {
        "onInterstitialLoaded",                              // const char* function name;
        "()V",                                               // const char* function signature
        (void *) InterstitialCallbacks::onInterstitialLoaded // function pointer
    },
    {
        "onInterstitialFailedToLoad",
        "()V",
        (void *) InterstitialCallbacks::onInterstitialFailedToLoad
    },
    {
        "onInterstitialShown",
        "()V",
        (void *) InterstitialCallbacks::onInterstitialShown
    },
    {
        "onInterstitialClicked",
        "()V",
        (void *) InterstitialCallbacks::onInterstitialClicked
    },
    {
        "onInterstitialClosed",
        "()V",
        (void *) InterstitialCallbacks::onInterstitialClosed
    },
    {
        "onBannerLoaded",
        "()V",
        (void *) BannerCallbacks::onBannerLoaded
    },
    {
        "onBannerFailedToLoad",
        "()V",
        (void *) BannerCallbacks::onBannerFailedToLoad
    },
    {
        "onBannerShown",
        "()V",
        (void *) BannerCallbacks::onBannerShown
    },
    {
        "onBannerClicked",
        "()V",
        (void *) BannerCallbacks::onBannerClicked
    },
    {
        "onVideoLoaded",
        "()V",
        (void *) VideoCallbacks::onVideoLoaded
    },
    {
        "onVideoFailedToLoad",
        "()V",
        (void *) VideoCallbacks::onVideoFailedToLoad
    },
    {
        "onVideoShown",
        "()V",
        (void *) VideoCallbacks::onVideoShown
    },
    {
        "onVideoFinished",
        "()V",
        (void *) VideoCallbacks::onVideoFinished
    },
    {
        "onVideoClosed",
        "()V",
        (void *) VideoCallbacks::onVideoClosed
    },
    {
        "onRewardedVideoLoaded",
        "()V",
        (void *) RewardedVideoCallbacks::onRewardedVideoLoaded
    },
    {
        "onRewardedVideoFailedToLoad",
        "()V",
        (void *) RewardedVideoCallbacks::onRewardedVideoFailedToLoad
    },
    {
        "onRewardedVideoShown",
        "()V",
        (void *) RewardedVideoCallbacks::onRewardedVideoShown
    },
    {
        "onRewardedVideoFinished",
        "()V",
        (void *) RewardedVideoCallbacks::onRewardedVideoFinished
    },
    {
        "onRewardedVideoClosed",
        "()V",
        (void *) RewardedVideoCallbacks::onRewardedVideoClosed
    },

};

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void*)
{
    JNIEnv* env;
    // get the JNIEnv pointer.
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
       return JNI_ERR;

    // search for Java class which declares the native methods
    jclass javaClass = env->FindClass(PACKAGE_NAME);
    if (!javaClass)
       return JNI_ERR;

    // register our native methods
    if (env->RegisterNatives(javaClass, methods, sizeof(methods) / sizeof(methods[0])) < 0)
    {
       return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}

