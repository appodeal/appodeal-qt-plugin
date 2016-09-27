#ifndef APPODEALINTERFACE
#define APPODEALINTERFACE

#include <QString>

class AppodealInterface
{
public:
    int INTERSTITIAL   = 1;
    int VIDEO          = 2;
    int BANNER         = 4;
    int BANNER_BOTTOM  = 8;
    int BANNER_TOP     = 16;
    int BANNER_CENTER  = 32;
    int REWARDED_VIDEO = 128;
    int ALL            = 255;
    int ANY            = 255;

    virtual ~AppodealInterface (){}
    virtual void Initialize (const QString &appKey, const int &adType) = 0;
    virtual bool Show (const int &adType) = 0;
    virtual void Hide (const int &adType) = 0;
    virtual void SetTesting(const bool &flag) = 0;
    virtual void setLogging (const bool &flag) = 0;
    virtual bool isLoaded (const int &adType) = 0;
    virtual bool isPrecache (const int &adType) = 0;
    virtual void cache (const int &adType) = 0;
    virtual void setAutoCache (const int &adType, const bool &flag) = 0;
    virtual void setOnLoadedTriggerBoth (const int &adType, const bool &flag) = 0;
    virtual void setInterstitialCallback () = 0;
    virtual void setBannerCallback () = 0;
    virtual void setVideoCallback () = 0;
    virtual void setRewardedVideoCallback () = 0;
    virtual bool showWithPriceFloor (const int &adType) = 0;
    virtual bool isLoadedWithPriceFloor (const int &adType) = 0;
    virtual void disableNetwork(const QString &network) = 0;
    virtual void disableNetwork(const QString &network, const int &adType) = 0;
    virtual void disableLocationPermissionCheck() = 0;
    virtual void trackInAppPurchase (const QString &currencyCode, const int &amount) = 0;
    virtual void getUserSettings () = 0;
};

#endif // APPODEALINTERFACE
