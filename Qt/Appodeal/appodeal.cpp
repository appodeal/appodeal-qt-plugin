#include "QAndroidJniObject"
#include <QPA/QPlatformNativeInterface.h>
#include <QApplication>
#include <QDebug>
#include <jni.h>
#include "appodeal.h"

#if (__ANDROID_API__ >= 9)

Appodeal::Appodeal()
    : m_Activity(0)
{
    QPlatformNativeInterface* interface = QApplication::platformNativeInterface();
    jobject activity = (jobject)interface->nativeResourceForIntegration("QtActivity");
    if (activity)
    {
        m_Activity = new QAndroidJniObject(activity);
    }

}

Appodeal::~Appodeal()
{
    if (m_Activity)
    {
        delete m_Activity;
    }
}

void Appodeal::Initialize(const QString &appKey, const int &adType)
{
    QAndroidJniObject appKeyS = QAndroidJniObject::fromString(appKey);
    m_Activity->callMethod<void>("initialize", "(Ljava/lang/String;I)V",  appKeyS.object<jstring>(), adType);
}

bool Appodeal::Show(const int &adType)
{
    return m_Activity->callMethod<jboolean>("show", "(I)Z", adType);
}

void Appodeal::Hide(const int &adType)
{
    m_Activity->callMethod<void>("hide", "(I)V", adType);
}

void Appodeal::SetTesting(const bool &flag)
{
    m_Activity->callMethod<void>("setTesting", "(Z)V", flag);
}

void Appodeal::setLogging(const bool &flag)
{
    m_Activity->callMethod<void>("setLogging", "(Z)V", flag);
}

bool Appodeal::isLoaded(const int &adType)
{
    return m_Activity->callMethod<jboolean>("isLoaded", "(I)Z", adType);
}

bool Appodeal::isPrecache(const int &adType)
{
    return m_Activity->callMethod<jboolean>("isPrecache", "(I)Z", adType);
}

void Appodeal::cache(const int &adType)
{
    m_Activity->callMethod<void>("cache", "(I)V", adType);
}

void Appodeal::setAutoCache(const int &adType, const bool &flag)
{
    m_Activity->callMethod<void>("setAutoCache", "(IZ)V", adType, flag);
}

void Appodeal::setOnLoadedTriggerBoth(const int &adType, const bool &flag)
{
    m_Activity->callMethod<void>("setOnLoadedTriggerBoth", "(IZ)V", adType, flag);
}
void Appodeal::setInterstitialCallback()
{
    m_Activity->callMethod<void>("setInterstitialCallback", "()V");
}

void Appodeal::setBannerCallback ()
{
      m_Activity->callMethod<void>("setBannerCallback", "()V");
}

void Appodeal::setVideoCallback()
{
      m_Activity->callMethod<void>("setVideoCallback", "()V");
}

void Appodeal::setRewardedVideoCallback()
{
     m_Activity->callMethod<void>("setRewardedVideoCallback", "()V");
}

bool Appodeal::showWithPriceFloor (const int &adType)
{
    return m_Activity->callMethod<jboolean>("showWithPriceFloor", "(I)Z", adType);
}

bool Appodeal::isLoadedWithPriceFloor (const int &adType)
{
    return m_Activity->callMethod<jboolean>("isLoadedWithPriceFloor", "(I)Z", adType);
}

void Appodeal::disableNetwork(const QString &network)
{
    QAndroidJniObject networkS = QAndroidJniObject::fromString(network);
    m_Activity->callMethod<void>("disableNetwork", "(Ljava/lang/String)V",  networkS.object<jstring>());
}

void Appodeal::disableNetwork(const QString &network, const int &adType)
{
    QAndroidJniObject networkS = QAndroidJniObject::fromString(network);
    m_Activity->callMethod<void>("disableNetwork", "(Ljava/lang/String;I)V",  networkS.object<jstring>(), adType);
}

void Appodeal::disableLocationPermissionCheck()
{
    m_Activity->callMethod<void>("disableLocationPermissionCheck", "()V");
}

void Appodeal::trackInAppPurchase (const QString &currencyCode, const int &amount)
{
    QAndroidJniObject currencyCodeS = QAndroidJniObject::fromString(currencyCode);
    m_Activity->callMethod<void>("trackInAppPurchase", "(Ljava/lang/String;I)V", currencyCodeS.object<jstring>(), amount);
}

void Appodeal::getUserSettings ()
{
    m_Activity->callMethod<void>("getUserSettings", "()V");
}
#endif
