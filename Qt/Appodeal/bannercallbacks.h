#ifndef BANNERCALLBACKS_H
#define BANNERCALLBACKS_H


class BannerCallbacks
{
public:
    BannerCallbacks();
    static void onBannerLoaded (JNIEnv *, jobject);
    static void onBannerFailedToLoad (JNIEnv *, jobject);
    static void onBannerShown (JNIEnv *, jobject);
    static void onBannerClicked (JNIEnv *, jobject);
};

#endif // BANNERCALLBACKS_H
