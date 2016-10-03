#if ANDROID

#include <jni.h>
#include "videocallbacks.h"

VideoCallbacks::VideoCallbacks()
{

}

//define native methods
void VideoCallbacks::onVideoLoaded(JNIEnv *, jobject)
{

}

void VideoCallbacks::onVideoFailedToLoad (JNIEnv *, jobject)
{

}

void VideoCallbacks::onVideoShown (JNIEnv *, jobject)
{

}

void VideoCallbacks::onVideoFinished(JNIEnv *, jobject)
{

}

void VideoCallbacks::onVideoClosed (JNIEnv *, jobject)
{

}

#endif
