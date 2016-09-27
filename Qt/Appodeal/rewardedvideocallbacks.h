#ifndef REWARDEDVIDEOCALLBACKS_H
#define REWARDEDVIDEOCALLBACKS_H


class RewardedVideoCallbacks
{
public:
    RewardedVideoCallbacks();
    static void onRewardedVideoLoaded (JNIEnv *, jobject);
    static void onRewardedVideoFailedToLoad (JNIEnv *, jobject);
    static void onRewardedVideoShown (JNIEnv *, jobject);
    static void onRewardedVideoFinished (JNIEnv *, jobject);
    static void onRewardedVideoClosed (JNIEnv *, jobject);
};

#endif // REWARDEDVIDEOCALLBACKS_H
