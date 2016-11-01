#ifndef VIDEOCALLBACKS_H
#define VIDEOCALLBACKS_H


class VideoCallbacks
{
public:
    VideoCallbacks();
    static void onVideoLoaded (JNIEnv *, jobject);
    static void onVideoFailedToLoad (JNIEnv *, jobject);
    static void onVideoShown (JNIEnv *, jobject);
    static void onVideoFinished (JNIEnv *, jobject);
    static void onVideoClosed (JNIEnv *, jobject);
};

#endif // VIDEOCALLBACKS_H
