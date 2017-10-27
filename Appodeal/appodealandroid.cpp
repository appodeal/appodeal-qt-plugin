#ifdef ANDROID

#include "appodealandroid.h"
#include "QAndroidJniObject"
#include <qpa/qplatformnativeinterface.h>
#include <QApplication>
#include <QtAndroid>
#include <QDebug>
#include <jni.h>

SignalReceiver* AppodealAndroid::signalReceiver = 0;

AppodealAndroid::AppodealAndroid():m_Appodeal(0){
    if(!m_Appodeal)
    {
        m_Appodeal = new QAndroidJniObject("com/appodeal/plugin/QTAppodeal");
    }
    signalReceiver = new SignalReceiver;
    //
}
AppodealAndroid::~AppodealAndroid(){
    if (m_Appodeal)
    {
        delete m_Appodeal;
        m_Appodeal = 0;
        delete signalReceiver;
        signalReceiver = 0;
    }
}

void AppodealAndroid::initialize(const QString &appKey, const int &adType)
{
    QAndroidJniObject appKeyS = QAndroidJniObject::fromString(appKey);
    m_Appodeal->callMethod<void>("initialize", "(Landroid/app/Activity;Ljava/lang/String;I)V",  QtAndroid::androidActivity().object<jobject>(), appKeyS.object<jstring>(), adType);
}

bool AppodealAndroid::show(const int &adType)
{
    return m_Appodeal->callMethod<jboolean>("show", "(Landroid/app/Activity;I)Z", QtAndroid::androidActivity().object<jobject>(), adType);
}

bool AppodealAndroid::show(const int &adType, const QString &placement)
{
    QAndroidJniObject placementS = QAndroidJniObject::fromString(placement);
    return m_Appodeal->callMethod<jboolean>("show", "(Landroid/app/Activity;ILjava/lang/String;)Z", QtAndroid::androidActivity().object<jobject>(), adType, placementS.object<jstring>());
}

void AppodealAndroid::hide(const int &adType)
{
    m_Appodeal->callMethod<void>("hide", "(Landroid/app/Activity;I)V", QtAndroid::androidActivity().object<jobject>(), adType);
}

void AppodealAndroid::setTesting(const bool &flag)
{
    m_Appodeal->callMethod<void>("setTesting", "(Z)V", flag);
}

void AppodealAndroid::setLogLevel(const int &level)
{
    m_Appodeal->callMethod<void>("setLogLevel", "(I)V", level);
}

bool AppodealAndroid::isLoaded(const int &adType)
{
    return m_Appodeal->callMethod<jboolean>("isLoaded", "(I)Z", adType);
}

bool AppodealAndroid::isPrecache(const int &adType)
{
    return m_Appodeal->callMethod<jboolean>("isPrecache", "(I)Z", adType);
}

void AppodealAndroid::cache(const int &adType)
{
    qDebug("Android.cache");
    m_Appodeal->callMethod<void>("cache", "(Landroid/app/Activity;I)V", QtAndroid::androidActivity().object<jobject>(), adType);
}

void AppodealAndroid::setAutoCache(const int &adType, const bool &flag)
{
    m_Appodeal->callMethod<void>("setAutoCache", "(IZ)V", adType, flag);
}

void AppodealAndroid::setTriggerOnLoadedOnPrecache(const int &adType, const bool &flag)
{
    m_Appodeal->callMethod<void>("setTriggerOnLoadedOnPrecache", "(IZ)V", adType, flag);
}
void AppodealAndroid::setInterstitialCallback(InterstitialCallbacks* callback)
{
    signalReceiver->setInterstitialCallback(callback);
    m_Appodeal->callMethod<void>("setInterstitialCallback", "()V");
}

void AppodealAndroid::setBannerCallback (BannerCallbacks *callbacks)
{
    signalReceiver->setBannerCallback(callbacks);
    m_Appodeal->callMethod<void>("setBannerCallback", "()V");
}

void AppodealAndroid::setRewardedVideoCallback(RewardedVideoCallbacks* callbacks)
{
    signalReceiver->setRewardedVideoCallback(callbacks);
    m_Appodeal->callMethod<void>("setRewardedVideoCallback", "()V");
}


void AppodealAndroid::disableNetwork(const QString &network)
{
    QAndroidJniObject networkS = QAndroidJniObject::fromString(network);
    m_Appodeal->callMethod<void>("disableNetwork", "(Landroid/app/Activity;Ljava/lang/String;)V",  QtAndroid::androidActivity().object<jobject>(), networkS.object<jstring>());
}

void AppodealAndroid::disableNetwork(const QString &network, const int &adType)
{
    QAndroidJniObject networkS = QAndroidJniObject::fromString(network);
    m_Appodeal->callMethod<void>("disableNetwork", "(Landroid/app/Activity;Ljava/lang/String;I)V",  QtAndroid::androidActivity().object<jobject>(), networkS.object<jstring>(), adType);
}

void AppodealAndroid::disableLocationPermissionCheck()
{
    m_Appodeal->callMethod<void>("disableLocationPermissionCheck", "()V");
}

void AppodealAndroid::trackInAppPurchase (const QString &currencyCode, const int &amount)
{
    QAndroidJniObject currencyCodeS = QAndroidJniObject::fromString(currencyCode);
    m_Appodeal->callMethod<void>("trackInAppPurchase", "(Landroid/app/Activity;Ljava/lang/String;I)V", QtAndroid::androidActivity().object<jobject>(), currencyCodeS.object<jstring>(), amount);
}

void AppodealAndroid::setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks){
    signalReceiver->setNonSkippableCallback(callbacks);
    m_Appodeal->callMethod<void>("setNonSkippableVideoCallback", "()V");

}
void AppodealAndroid::setAge (const int &age){
    m_Appodeal->callMethod<void>("setAge", "(Landroid/app/Activity;I)V", QtAndroid::androidActivity().object<jobject>(), age);
}
void AppodealAndroid::setGender(const int &gender){
    m_Appodeal->callMethod<void>("setGender", "(Landroid/app/Activity;I)V", QtAndroid::androidActivity().object<jobject>(), gender);
}
void AppodealAndroid::setUserId(const QString &userId){
    QAndroidJniObject userIdS = QAndroidJniObject::fromString(userId);
    m_Appodeal->callMethod<void>("setUserId", "(Landroid/app/Activity;Ljava/lang/String;)V", QtAndroid::androidActivity().object<jobject>(), userIdS.object<jstring>());
}
bool AppodealAndroid::canShow(const int &adType){
    return m_Appodeal->callMethod<jboolean>("canShow", "(I)Z", adType);
}

bool AppodealAndroid::canShow(const int &adType, const QString &placement){
    QAndroidJniObject jplacement = QAndroidJniObject::fromString(placement);
    return m_Appodeal->callMethod<jboolean>("canShow", "(ILandroid/app/Activity;Ljava/lang/String;)Z", adType, jplacement.object<jstring>());
}
void AppodealAndroid::setChildDirectedTreatment(const bool &flag){
    m_Appodeal->callMethod<void>("setChildDirectedTreatment", "(Z)V", flag);
}
void AppodealAndroid::muteVideosIfCallsMuted(const bool &flag){
    m_Appodeal->callMethod<void>("muteVideosIfCallsMuted", "(Z)V", flag);
}
void AppodealAndroid::disableWriteExternalStoragePermissionCheck(){
    m_Appodeal->callMethod<void>("disableWriteExternalStoragePermissionCheck", "(V)V");
}
void AppodealAndroid::requestAndroidMPermissions(/*callback*/){
    m_Appodeal->callMethod<void>("requestAndroidMPermissions", "(Landroid/app/Activity;)V", QtAndroid::androidActivity().object<jobject>());
}
void AppodealAndroid::set728x90Banners(const bool &flag){
    m_Appodeal->callMethod<void>("set728x90Banners", "(Z)V", flag);
}
void AppodealAndroid::setBannerAnimation(const bool &flag){
    m_Appodeal->callMethod<void>("setBannerAnimation", "(Z)V", flag);
}
void AppodealAndroid::setSmartBanners(const bool &flag){
    m_Appodeal->callMethod<void>("setSmartBanners", "(Z)V", flag);
}
void AppodealAndroid::setCustomRule(const QString &name, const double &value){
    QAndroidJniObject nameS = QAndroidJniObject::fromString(name);
    m_Appodeal->callMethod<void>("setCustomRule", "(Ljava/lang/String;D)V", nameS.object<jstring>(), value);
}
void AppodealAndroid::setCustomRule(const QString &name, const int &value){
    QAndroidJniObject nameS = QAndroidJniObject::fromString(name);
    m_Appodeal->callMethod<void>("setCustomRule", "(Ljava/lang/String;I)V", nameS.object<jstring>(), value);
}
void AppodealAndroid::setCustomRule(const QString &name, const bool &value){
    QAndroidJniObject nameS = QAndroidJniObject::fromString(name);
    m_Appodeal->callMethod<void>("setCustomRule", "(Ljava/lang/String;Z)V", nameS.object<jstring>(), value);
}
void AppodealAndroid::setCustomRule(const QString &name, const QString &value){
    QAndroidJniObject nameS = QAndroidJniObject::fromString(name);
    QAndroidJniObject valueS = QAndroidJniObject::fromString(value);
    m_Appodeal->callMethod<void>("setCustomRule", "(Ljava/lang/String;Ljava/lang/String;)V", nameS.object<jstring>(), valueS.object<jstring>());
}

//Callbacks for interaction with java
void AppodealAndroid::onNonSkippableVideoLoaded(){
    QMetaObject::invokeMethod(signalReceiver, "onNonSkippableVideoLoaded", Qt::QueuedConnection);
}
void AppodealAndroid::onNonSkippableVideoFailedToLoad(){

    QMetaObject::invokeMethod(signalReceiver, "onNonSkippableVideoFailedToLoad", Qt::QueuedConnection);
}
void AppodealAndroid::onNonSkippableVideoShown(){
    QMetaObject::invokeMethod(signalReceiver, "onNonSkippableVideoShown", Qt::QueuedConnection);
}
void AppodealAndroid::onNonSkippableVideoFinished(){
    QMetaObject::invokeMethod(signalReceiver, "onNonSkippableVideoFinished", Qt::QueuedConnection);
}
void AppodealAndroid::onNonSkippableVideoClosed(JNIEnv *, jobject, jboolean isFinished){
    QMetaObject::invokeMethod(signalReceiver, "onNonSkippableVideoClosed", Qt::QueuedConnection, Q_ARG(bool, (bool)isFinished));
}
void AppodealAndroid::onBannerLoaded(JNIEnv *, jobject, jint height, jboolean isPrecache){
    QMetaObject::invokeMethod(signalReceiver, "onBannerLoaded", Qt::QueuedConnection, Q_ARG(int, (int)height), Q_ARG(bool, (bool)isPrecache));
}
void AppodealAndroid::onBannerFailedToLoad(){
    QMetaObject::invokeMethod(signalReceiver, "onBannerFailedToLoad", Qt::QueuedConnection);
}
void AppodealAndroid::onBannerShown(){
    QMetaObject::invokeMethod(signalReceiver, "onBannerShown", Qt::QueuedConnection);
}
void AppodealAndroid::onBannerClicked(){
    QMetaObject::invokeMethod(signalReceiver, "onBannerClicked", Qt::QueuedConnection);
}

void AppodealAndroid::onInterstitialLoaded (JNIEnv *, jobject, jboolean isPrecache){
    QMetaObject::invokeMethod(signalReceiver, "onInterstitialLoaded", Qt::QueuedConnection, Q_ARG(bool, (bool)isPrecache));
}
void AppodealAndroid::onInterstitialFailedToLoad (){
    QMetaObject::invokeMethod(signalReceiver, "onInterstitialFailedToLoad", Qt::QueuedConnection);
}
void AppodealAndroid::onInterstitialShown(){
    QMetaObject::invokeMethod(signalReceiver, "onInterstitialShown", Qt::QueuedConnection);
}
void AppodealAndroid::onInterstitialClicked(){
    QMetaObject::invokeMethod(signalReceiver, "onInterstitialClicked", Qt::QueuedConnection);
}
void AppodealAndroid::onInterstitialClosed(){
    QMetaObject::invokeMethod(signalReceiver, "onInterstitialClosed", Qt::QueuedConnection);
}

void AppodealAndroid::onRewardedVideoLoaded (){
    QMetaObject::invokeMethod(signalReceiver, "onRewardedVideoLoaded", Qt::QueuedConnection);
}
void AppodealAndroid::onRewardedVideoFailedToLoad (){
    QMetaObject::invokeMethod(signalReceiver, "onRewardedVideoFailedToLoad", Qt::QueuedConnection);
}
void AppodealAndroid::onRewardedVideoShown (){
    QMetaObject::invokeMethod(signalReceiver, "onRewardedVideoShown", Qt::QueuedConnection);
}
void AppodealAndroid::onRewardedVideoFinished (JNIEnv *env, jobject, jint value, jstring currency){
    QMetaObject::invokeMethod(signalReceiver, "onRewardedVideoFinished", Qt::QueuedConnection, Q_ARG(int, (int)value), Q_ARG(QString, QString(env->GetStringUTFChars(currency, NULL))));
}
void AppodealAndroid::onRewardedVideoClosed (JNIEnv *, jobject, jboolean isFinished){
    QMetaObject::invokeMethod(signalReceiver, "onRewardedVideoClosed", Qt::QueuedConnection, Q_ARG(bool, (bool)isFinished));
}

#endif
