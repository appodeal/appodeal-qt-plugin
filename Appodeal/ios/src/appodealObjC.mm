#include <QApplication>
#include <QObject>

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#import "appodealios.h"
#include <UIKit/UIKit.h>
#import <Appodeal/Appodeal.h>

const int INTERSTITIAL          = 1;
const int SKIPPABLE_VIDEO       = 2;
const int BANNER                = 4;
const int BANNER_BOTTOM         = 8;
const int BANNER_TOP            = 16;
const int REWARDED_VIDEO        = 128;
const int NON_SKIPPABLE_VIDEO   = 256;

int nativeAdTypesForType(int adTypes) {
    int nativeAdTypes = 0;

    if ((adTypes & INTERSTITIAL) > 0) {
        nativeAdTypes |= AppodealAdTypeInterstitial;
    }

    if ((adTypes & SKIPPABLE_VIDEO) > 0) {
        nativeAdTypes |= AppodealAdTypeSkippableVideo;
    }

    if ((adTypes & BANNER) > 0 ||
        (adTypes & BANNER_TOP) > 0 ||
        (adTypes & BANNER_BOTTOM) > 0) {

        nativeAdTypes |= AppodealAdTypeBanner;
    }

    if ((adTypes & REWARDED_VIDEO) > 0) {
        nativeAdTypes |= AppodealAdTypeRewardedVideo;
    }

    if ((adTypes & NON_SKIPPABLE_VIDEO) > 0) {
        nativeAdTypes |= AppodealAdTypeNonSkippableVideo;
    }

    return nativeAdTypes;
}

int nativeShowStyleForType(int adTypes) {
    bool isInterstitial = (adTypes & INTERSTITIAL) > 0;
    bool isVideo = (adTypes & SKIPPABLE_VIDEO) > 0;

    if (isInterstitial && isVideo) {
        return AppodealShowStyleVideoOrInterstitial;
    } else if (isVideo) {
        return AppodealAdTypeSkippableVideo;
    } else if (isInterstitial) {
        return AppodealShowStyleInterstitial;
    }
    
    if ((adTypes & BANNER) > 0) {
        return AppodealShowStyleBannerBottom;
    }

    if ((adTypes & BANNER_TOP) > 0) {
        return AppodealShowStyleBannerTop;
    }

    if ((adTypes & BANNER_BOTTOM) > 0) {
        return AppodealShowStyleBannerBottom;
    }

    if ((adTypes & REWARDED_VIDEO) > 0) {
        return AppodealShowStyleRewardedVideo;
    }

    if ((adTypes & NON_SKIPPABLE_VIDEO) > 0) {
        return AppodealShowStyleNonSkippableVideo;
    }

    return 0;
}

static NSDateFormatter *DateFormatter() {
    static dispatch_once_t onceToken;
    static NSDateFormatter *formatter;
    dispatch_once(&onceToken, ^{
        formatter = [[NSDateFormatter alloc] init];
        formatter.dateFormat = @"dd/MM/yyyy";
    });

    return formatter;
}

SignalReceiver* AppodealiOS::signalReceiver = 0;

AppodealiOS::AppodealiOS() {
    signalReceiver = new SignalReceiver;
}

AppodealiOS::~AppodealiOS() {
    delete signalReceiver;
    signalReceiver = 0;
}

@interface QtAppodealInterstitialDelegate : NSObject<AppodealInterstitialDelegate> { InterstitialCallbacks* _interstitialCallbacks; }
@property InterstitialCallbacks* interstitialCallbacks;
@end

@implementation QtAppodealInterstitialDelegate
-(void) interstitialDidLoadAdisPrecache:(BOOL)precache { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onInterstitialLoaded", Qt::QueuedConnection, Q_ARG(bool, (bool)precache)); }
-(void) interstitialDidClick { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onInterstitialClicked", Qt::QueuedConnection); }
-(void) interstitialDidDismiss { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onInterstitialClosed", Qt::QueuedConnection); }
-(void) interstitialWillPresent { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onInterstitialShown", Qt::QueuedConnection); }
-(void) interstitialDidFailToLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onInterstitialFailedToLoad", Qt::QueuedConnection); }
@end

@interface QtAppodealSkippableVideoDelegate : NSObject<AppodealSkippableVideoDelegate> { SkippableVideoCallbacks* _skippableVideoCallbacks; }
@property SkippableVideoCallbacks* skippableVideoCallbacks;
@end

@implementation QtAppodealSkippableVideoDelegate

-(void) skippableVideoDidLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onSkippableVideoLoaded", Qt::QueuedConnection); }
-(void) skippableVideoDidFailToLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onSkippableVideoFailedToLoad", Qt::QueuedConnection); }
-(void) skippableVideoDidPresent { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onSkippableVideoShown", Qt::QueuedConnection); }
-(void) skippableVideoWillDismiss { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onSkippableVideoClosed", Qt::QueuedConnection, Q_ARG(bool, (bool)false)); }
-(void) skippableVideoDidFinish { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onSkippableVideoFinished", Qt::QueuedConnection); }
-(void) skippableVideoDidClick { /* not supported on android */ }

@end

@interface QtAppodealNonSkippableVideoDelegate : NSObject<AppodealNonSkippableVideoDelegate> { NonSkippableVideoCallbacks* _nonSkippableVideoCallbacks; }
@property NonSkippableVideoCallbacks* nonSkippableVideoCallbacks;
@end

@implementation QtAppodealNonSkippableVideoDelegate

-(void) nonSkippableVideoDidLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onNonSkippableVideoLoaded", Qt::QueuedConnection); }
-(void) nonSkippableVideoDidFailToLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onNonSkippableVideoFailedToLoad", Qt::QueuedConnection); }
-(void) nonSkippableVideoDidPresent { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onNonSkippableVideoShown", Qt::QueuedConnection); }
-(void) nonSkippableVideoWillDismiss { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onNonSkippableVideoClosed", Qt::QueuedConnection, Q_ARG(bool, (bool)false)); }
-(void) nonSkippableVideoDidFinish { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onNonSkippableVideoFinished", Qt::QueuedConnection); }
-(void) nonSkippableVideoDidClick { /* not supported on android */ }

@end

@interface QtAppodealRewardedVideoDelegate : NSObject<AppodealRewardedVideoDelegate> { RewardedVideoCallbacks* _rewardedVideoCallbacks; }
@property RewardedVideoCallbacks* rewardedVideoCallbacks;
@end

@implementation QtAppodealRewardedVideoDelegate

- (void)rewardedVideoDidLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onRewardedVideoLoaded", Qt::QueuedConnection); }
- (void)rewardedVideoDidFailToLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onRewardedVideoFailedToLoad", Qt::QueuedConnection); }
- (void)rewardedVideoDidPresent { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onRewardedVideoShown", Qt::QueuedConnection); }
- (void)rewardedVideoWillDismiss { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onRewardedVideoClosed", Qt::QueuedConnection, Q_ARG(bool, (bool)false)); }
- (void)rewardedVideoDidFinish:(NSUInteger)rewardAmount name:(NSString *)rewardName { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onRewardedVideoFinished", Qt::QueuedConnection, Q_ARG(int, (int)rewardAmount), Q_ARG(QString, QString(rewardName.UTF8String)) ); }
- (void)rewardedVideoDidClick { }

@end

@interface QtAppodealBannerDelegate : NSObject<AppodealBannerDelegate> { BannerCallbacks* _bannerCallbacks; }
@property BannerCallbacks* bannerCallbacks;
@end

@implementation QtAppodealBannerDelegate



@end

void AppodealiOS::initialize(const QString &appKey, const int &adType)
{
    NSLog(@"Appodeal QT Plugin v.1.0.0, iOS Initialized with appKey: %@", [NSString stringWithUTF8String:appKey.toLatin1()]);
    [Appodeal initializeWithApiKey:[NSString stringWithUTF8String:(appKey.toLatin1())] types:nativeAdTypesForType(adType)];
}

bool AppodealiOS::show (const int &adType) {
    UIViewController *root = [[[UIApplication sharedApplication] keyWindow] rootViewController];
    return [Appodeal showAd:(AppodealShowStyle)nativeShowStyleForType(adType) rootViewController:root];
}

bool AppodealiOS::show (const int &adType, const QString &placement) {
    UIViewController *root = [[[UIApplication sharedApplication] keyWindow] rootViewController];
    return [Appodeal showAd:(AppodealShowStyle)nativeShowStyleForType(adType) forPlacement:[NSString stringWithUTF8String:(placement.toLatin1())] rootViewController:root];
}

void AppodealiOS::hide (const int &adType) {
    [Appodeal hideBanner];
}

void AppodealiOS::setTesting(const bool &flag) {
    [Appodeal setTestingEnabled:flag];
}

void AppodealiOS::setLogLevel (const int &level) {
    switch(level){
        case 0:
            //[Appodeal setLogLevel:APDLogLevelVerbose];
            [Appodeal setDebugEnabled:YES];
            break;
        case 1:
            //[Appodeal setLogLevel:APDLogLevelDebug];
            [Appodeal setDebugEnabled:YES];
            break;
        case 2:
            //[Appodeal setLogLevel:APDLogLevelInfo];
            [Appodeal setDebugEnabled:NO];
            break;
        default:
            //[Appodeal setLogLevel:APDLogLevelOff];
            [Appodeal setDebugEnabled:NO];
            break;
    }
}

void AppodealiOS::confirm(const int &adType) {
    [Appodeal confirmUsage:(AppodealAdType)nativeAdTypesForType(adType)];
}

bool AppodealiOS::isLoaded (const int &adType) {
    return [Appodeal isReadyForShowWithStyle:(AppodealShowStyle)nativeShowStyleForType(adType)];
}

bool AppodealiOS::isPrecache (const int &adType) {
    NSLog(@"isPrecache Not Supported on Appodeal iOS SDK for ad type: %i", adType);
    return false;
}

void AppodealiOS::cache (const int &adType) {
    [Appodeal cacheAd:(AppodealAdType)nativeAdTypesForType(adType)];
}

void AppodealiOS::setAutoCache (const int &adType, const bool &flag) {
    [Appodeal setAutocache:flag types:(AppodealAdType)nativeAdTypesForType(adType)];
}

void AppodealiOS::setOnLoadedTriggerBoth (const int &adType, const bool &flag) {
    NSLog(@"setOnLoadedTriggerBoth Not Supported on Appodeal iOS SDK for ad type: %i with value %d", adType, flag);
}

void AppodealiOS::disableNetwork(const QString &network) {
    [Appodeal disableNetworkForAdType:AppodealAdTypeBanner name:[NSString stringWithUTF8String:(network.toLatin1())]];
    [Appodeal disableNetworkForAdType:AppodealAdTypeInterstitial name:[NSString stringWithUTF8String:(network.toLatin1())]];
    [Appodeal disableNetworkForAdType:AppodealAdTypeSkippableVideo name:[NSString stringWithUTF8String:(network.toLatin1())]];
    [Appodeal disableNetworkForAdType:AppodealAdTypeNonSkippableVideo name:[NSString stringWithUTF8String:(network.toLatin1())]];
    [Appodeal disableNetworkForAdType:AppodealAdTypeRewardedVideo name:[NSString stringWithUTF8String:(network.toLatin1())]];
}

void AppodealiOS::disableNetwork(const QString &network, const int &adType) {
    [Appodeal disableNetworkForAdType:(AppodealAdType)nativeAdTypesForType(adType) name:[NSString stringWithUTF8String:(network.toLatin1())]];
}

void AppodealiOS::disableLocationPermissionCheck() {
    [Appodeal disableLocationPermissionCheck];
}

void AppodealiOS::trackInAppPurchase (const QString &currencyCode, const int &amount) {
    [[APDSdk sharedSdk] trackInAppPurchase:[NSNumber numberWithInt:amount] currency:[NSString stringWithUTF8String:(currencyCode.toLatin1())]];
}

void AppodealiOS::disableWriteExternalStoragePermissionCheck() {
    NSLog(@"disableWriteExternalStoragePermissionCheck Not Supported on Appodeal iOS SDK");
}

void AppodealiOS::setInterstitialCallback (InterstitialCallbacks* callbacks) {
    signalReceiver->setInterstitialCallback(callbacks);
    static QtAppodealInterstitialDelegate *qtAppodealInterstitialDelegate;
    qtAppodealInterstitialDelegate = [QtAppodealInterstitialDelegate new];
    qtAppodealInterstitialDelegate.interstitialCallbacks = callbacks;
    [Appodeal setInterstitialDelegate:qtAppodealInterstitialDelegate];
}

void AppodealiOS::setSkippableVideoCallback(SkippableVideoCallbacks *callbacks) {
    signalReceiver->setSkippableVideoCallback(callbacks);
    static QtAppodealSkippableVideoDelegate *qtSkippableVideoDelegate;
    qtSkippableVideoDelegate = [QtAppodealSkippableVideoDelegate new];
    qtSkippableVideoDelegate.skippableVideoCallbacks = callbacks;
    [Appodeal setSkippableVideoDelegate:qtSkippableVideoDelegate];
}

void AppodealiOS::setBannerCallback (BannerCallbacks* callbacks) {
    signalReceiver->setBannerCallback(callbacks);
    static QtAppodealBannerDelegate *qtBannerDelegate;
    qtBannerDelegate = [QtAppodealBannerDelegate new];
    qtBannerDelegate.bannerCallbacks = callbacks;
    [Appodeal setBannerDelegate:qtBannerDelegate];
}

void AppodealiOS::setRewardedVideoCallback (RewardedVideoCallbacks* callbacks) {
    signalReceiver->setRewardedVideoCallback(callbacks);
    static QtAppodealRewardedVideoDelegate *qtRewardedVideoDelegate;
    qtRewardedVideoDelegate = [QtAppodealRewardedVideoDelegate new];
    qtRewardedVideoDelegate.rewardedVideoCallbacks = callbacks;
    [Appodeal setRewardedVideoDelegate:qtRewardedVideoDelegate];
}

void AppodealiOS::setNonSkippableVideoCallback (NonSkippableVideoCallbacks *callbacks) {
    signalReceiver->setNonSkippableCallback(callbacks);
    static QtAppodealNonSkippableVideoDelegate *qtNonSkippableVideoDelegate;
    qtNonSkippableVideoDelegate = [QtAppodealNonSkippableVideoDelegate new];
    qtNonSkippableVideoDelegate.nonSkippableVideoCallbacks = callbacks;
    [Appodeal setNonSkippableVideoDelegate:qtNonSkippableVideoDelegate];
}


void AppodealiOS::setAge (const int &age) {
    [Appodeal setUserAge:age];
}

void AppodealiOS::setBirthday(const QString &bDay) {
    NSDate *date = [DateFormatter() dateFromString:[NSString stringWithUTF8String:(bDay.toLatin1())]];
    if (date) {
        [Appodeal setUserBirthday:date];
    }
}

void AppodealiOS::setEmail(const QString &email) {
    [Appodeal setUserEmail:[NSString stringWithUTF8String:(email.toLatin1())]];
}

void AppodealiOS::setGender(const int &gender) {
    [Appodeal setUserGender:(AppodealUserGender)gender];
}

void AppodealiOS::setInterests(const QString &interests) {
     [Appodeal setUserInterests:[NSString stringWithUTF8String:(interests.toLatin1())]];
}

void AppodealiOS::setOccupation(const int &occupation) {
    [Appodeal setUserOccupation:(AppodealUserOccupation)occupation];
}

void AppodealiOS::setRelation(const int &relation) {
    [Appodeal setUserRelationship:(AppodealUserRelationship)relation];
}

void AppodealiOS::setAlcohol(const int &alcohol) {
    const int &alco = alcohol + 1;
    [Appodeal setUserAlcoholAttitude:(AppodealUserAlcoholAttitude)alco];
}

void AppodealiOS::setSmoking(const int &smoking) {
    const int &smoke = smoking + 1;
    [Appodeal setUserSmokingAttitude:(AppodealUserSmokingAttitude)smoke];
}

void AppodealiOS::setUserId(const QString &userId) {
    [Appodeal setUserId:[NSString stringWithUTF8String:(userId.toLatin1())]];
}

void AppodealiOS::requestAndroidMPermissions(/*callback*/) {
    NSLog(@"requestAndroidMPermissions Not Supported on Appodeal iOS SDK");
}

void AppodealiOS::set728x90Banners(const bool &flag) {
    NSLog(@"set728x90Banners Not Supported on Appodeal iOS SDK, flag: %d", flag);
}

void AppodealiOS::setBannerAnimation(const bool &flag) {
    [Appodeal setBannerAnimationEnabled:flag];
}

void AppodealiOS::setSmartBanners(const bool &flag) {
    [Appodeal setSmartBannersEnabled:flag];
}

void AppodealiOS::setCustomRule(const QString &name, const double &value) {
    NSDictionary *tempDictionary = @{[NSString stringWithUTF8String:(name.toLatin1())]: [NSNumber numberWithDouble:value]};
    NSDictionary *dict =  [NSDictionary dictionaryWithDictionary:tempDictionary];
    [Appodeal setCustomRule:dict];
}

void AppodealiOS::setCustomRule(const QString &name, const int &value) {
    NSDictionary *tempDictionary = @{[NSString stringWithUTF8String:(name.toLatin1())]: [NSNumber numberWithInt:value]};
    NSDictionary *dict =  [NSDictionary dictionaryWithDictionary:tempDictionary];
    [Appodeal setCustomRule:dict];
}

void AppodealiOS::setCustomRule(const QString &name, const bool &value) {
    NSString *ValueFromBOOL;
    if(value) {
        ValueFromBOOL = @"YES";
    } else {
        ValueFromBOOL = @"NO";
    }

    NSDictionary *tempDictionary = @{[NSString stringWithUTF8String:(name.toLatin1())]: ValueFromBOOL};
    NSDictionary *dict =  [NSDictionary dictionaryWithDictionary:tempDictionary];
    [Appodeal setCustomRule:dict];
}

void AppodealiOS::setCustomRule(const QString &name, const QString &value) {
    NSDictionary *tempDictionary = @{[NSString stringWithUTF8String:(name.toLatin1())]: [NSString stringWithUTF8String:(value.toLatin1())]};
    NSDictionary *dict =  [NSDictionary dictionaryWithDictionary:tempDictionary];
    [Appodeal setCustomRule:dict];
}

#endif // TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
