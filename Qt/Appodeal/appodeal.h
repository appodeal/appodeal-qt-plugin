#ifndef APPODEAL_H
#define APPODEAL_H

#include "appodealinterface.h"

class QAndroidJniObject;

class Appodeal : public AppodealInterface
{
public:
    Appodeal();
    virtual ~Appodeal();
    virtual void Initialize (const QString &appKey, const int &adType);
    virtual bool Show (const int &adType);
    virtual void Hide (const int &adType);
    virtual void SetTesting(const bool &flag);
    virtual void setLogging (const bool &flag);
    virtual bool isLoaded (const int &adType);
    virtual bool isPrecache (const int &adType);
    virtual void cache (const int &adType);
    virtual void setAutoCache (const int &adType, const bool &flag);
    virtual void setOnLoadedTriggerBoth (const int &adType, const bool &flag);
    virtual void setInterstitialCallback ();
    virtual void setBannerCallback ();
    virtual void setVideoCallback ();
    virtual void setRewardedVideoCallback ();
    virtual bool showWithPriceFloor (const int &adType);
    virtual bool isLoadedWithPriceFloor (const int &adType);
    virtual void disableNetwork(const QString &network);
    virtual void disableNetwork(const QString &network, const int &adType);
    virtual void disableLocationPermissionCheck();
    virtual void trackInAppPurchase (const QString &currencyCode, const int &amount);
    virtual void getUserSettings ();

private:
    QAndroidJniObject* m_Activity;
};

#endif // APPODEAL_H
