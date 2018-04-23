#include <QApplication>
#include <QObject>

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

#import "appodealios.h"
#include <UIKit/UIKit.h>
#import <Appodeal/Appodeal.h>

const int INTERSTITIAL          = 1;
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
    if ((adTypes & INTERSTITIAL) > 0) {
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

@interface QtAppodealBannerDelegate : NSObject<AppodealBannerDelegate> { BannerCallbacks* _bannerCallbacks; }
@property BannerCallbacks* bannerCallbacks;
@end

@implementation QtAppodealBannerDelegate
-(void) bannerDidLoadAdIsPrecache:(BOOL)precache { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onBannerLoaded", Qt::QueuedConnection, Q_ARG(int, (int)0), Q_ARG(bool, (bool)precache)); }
-(void) bannerDidClick { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onBannerClicked", Qt::QueuedConnection); }
-(void) bannerDidShow { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onBannerShown", Qt::QueuedConnection); }
-(void) bannerDidFailToLoadAd { QMetaObject::invokeMethod(AppodealiOS::signalReceiver, "onBannerFailedToLoad", Qt::QueuedConnection); }
@end

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



void AppodealiOS::initialize(const QString &appKey, const int &adType)
{
    NSLog(@"Appodeal QT Plugin v.2.1.10, iOS Initialized with appKey: %@", [NSString stringWithUTF8String:appKey.toLatin1()]);
    [Appodeal setFramework:APDFrameworkQt];
    [Appodeal setPluginVersion:@"2.1.10"];
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

bool AppodealiOS::canShow(const int &adType){
    return [Appodeal canShowAd:(AppodealShowStyle)nativeShowStyleForType(adType) forPlacement:@"default"];
}

bool AppodealiOS::canShow(const int &adType, const QString &placement){
    return [Appodeal canShowAd:(AppodealShowStyle)nativeShowStyleForType(adType) forPlacement:[NSString stringWithUTF8String:(placement.toLatin1())]];
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
            [Appodeal setLogLevel:APDLogLevelOff];
            break;
        case 1:
            [Appodeal setLogLevel:APDLogLevelDebug];
            break;
        case 2:
            [Appodeal setLogLevel:APDLogLevelInfo];
            break;
        default:
            [Appodeal setLogLevel:APDLogLevelOff];
            break;
    }
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

void AppodealiOS::setTriggerOnLoadedOnPrecache (const int &adType, const bool &flag) {
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
            
void AppodealiOS::setChildDirectedTreatment(const bool &flag) {
    NSLog(@"setChildDirectedTreatment Not Supported on Appodeal iOS SDK");
}

void AppodealiOS::muteVideosIfCallsMuted(const bool &flag) {
    NSLog(@"muteVideosIfCallsMuted Not Supported on Appodeal iOS SDK");
}
            
void AppodealiOS::destroy(const int &adTypes){
    NSLog(@"destroy Not Supported on Appodeal iOS SDK");
}

void AppodealiOS::setAge (const int &age) {
    [Appodeal setUserAge:age];
}

void AppodealiOS::setGender(const int &gender) {
    [Appodeal setUserGender:(AppodealUserGender)gender];
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
    NSString * key = [NSString stringWithUTF8String:(name.toLatin1())];
    NSNumber * valueNum = [NSNumber numberWithBool:value];
    NSDictionary * objCRule = key ? @{} : @{key : valueNum};
    [Appodeal setCustomRule:objCRule];
}

void AppodealiOS::setCustomRule(const QString &name, const QString &value) {
    NSDictionary *tempDictionary = @{[NSString stringWithUTF8String:(name.toLatin1())]: [NSString stringWithUTF8String:(value.toLatin1())]};
    NSDictionary *dict =  [NSDictionary dictionaryWithDictionary:tempDictionary];
    [Appodeal setCustomRule:dict];
}

#endif // TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
