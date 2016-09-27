#ifndef INTERSTITIALCALLBACKS_H
#define INTERSTITIALCALLBACKS_H

class InterstitialCallbacks
{
public:
    InterstitialCallbacks();
    static void onInterstitialLoaded (JNIEnv *, jobject);
    static void onInterstitialFailedToLoad (JNIEnv *, jobject);
    static void onInterstitialShown(JNIEnv *, jobject);
    static void onInterstitialClicked(JNIEnv *, jobject);
    static void onInterstitialClosed(JNIEnv *, jobject);
};

#endif // INTERSTITIALCALLBACKS_H
