# Appodeal QT plugin

## Download SDK

You can download Appodeal plugin for QT [![](https://img.shields.io/badge/download-here-green.svg)](https://s3-us-west-1.amazonaws.com/appodeal-qt/Appodeal-Qt-110417-2.0.0.zip) .

Minimum OS requirements: Android API level 9 (Android OS 2.3).

Android Appodeal SDK version 1.15.9

iOS Appodeal SDK version 1.3.9

## QT Integration

### SDK files

Download the plugin and unzip it into your project directory. Open *.pro file from your project and add the following line:

```
include(Appodeal/Appodeal.pri)
```

### Android Integration

Copy TARGET value from *.pro file, open Appodeal/android/AndroidManifest.xml in text editor, find the following line:
```
<meta-data android:name="android.app.lib_name" android:value="AppodealDemo"/>
```
And replace AppodealDemo with your TARGET value.

### iOS Integration

After building iOS Project you will get error: `Appodeal.framework/Appodeal(AVHttpClient.o)' does not contain bitcode. You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target. for architecture arm64` don't worry, just open compiled xcode project, go to `Build Settings` Set `Enable Bitcode` to `No` and remove `-fembed-bitcode-marker` flag from  `Other Linker Flags`.
Now you can succesfully build your project.

### Ad types

AppodealAds::INTERSTITIAL

AppodealAds::SKIPPABLE_VIDEO

AppodealAds::BANNER

AppodealAds::BANNER_TOP

AppodealAds::BANNER_BOTTOM

AppodealAds::REWARDED_VIDEO

AppodealAds::NON_SKIPPABLE_VIDEO

Ad types can be combined using "|" operator. For example AppodealAds::INTERSTITIAL | AppodealAds::SKIPPABLE_VIDEO

Note that it is better to use NON_SKIPPABLE_VIDEO or REWARDED_VIDEO, but if you are sure you want to use SKIPPABLE_VIDEO you must confirm usage by calling AppodealAds::confirm(AppodealAds::SKIPPABLE_VIDEO) before SDK initialization

### SDK initialization

Import Appodeal header to your code:
```
#include "Appodeal/appodealads.h"
```
To initialize SDK you need to add following code:

```
QString appKey = "fee50c333ff3825fd6ad6d38cff78154de3025546d47a84f";
AppodealAds::initialize(appKey, AppodealAds::BANNER | AppodealAds::INTERSTITIAL);
```

Note: appKey is the key you received when you created an app.

To initialize only interstitials use AppodealAds::initialize(appKey, AppodealAds::INTERSTITIAL)

To initialize only skippable videos use AppodealAds::initialize(appKey, AppodealAds::SKIPPABLE_VIDEO)

To initialize interstitials and videos use AppodealAds::initialize(appKey, AppodealAds::INTERSTITIAL | AppodealAds::SKIPPABLE_VIDEO)

To initialize only banners use AppodealAds::initialize(appKey, AppodealAds::BANNER)

To initialize only rewarded video use AppodealAds::initialize(appKey, AppodealAds::REWARDED_VIDEO)

To initialize only non-skippable video use AppodealAds::initialize(appKey, AppodealAds::NON_SKIPPABLE_VIDEO)

###. Display ad

```
AppodealAds::show(adTypes);
```

show() returns a boolean value indicating whether show call was passed to appropriate SDK

To display interstitial use AppodealAds::show(AppodealAds::INTERSTITIAL)

To display skippable video use AppodealAds::show(AppodealAds::SKIPPABLE_VIDEO)

To display rewarded video use AppodealAds::show(AppodealAds::REWARDED_VIDEO)

To display non-skippable video use AppodealAds::show(AppodealAds::NON_SKIPPABLE_VIDEO)

To display interstitial or video use AppodealAds::show(AppodealAds::INTERSTITIAL | AppodealAds::SKIPPABLE_VIDEO)

To display banner at the bottom of the screen use sppodeal::Show(AppodealAds::BANNER_BOTTOM)

To display banner at the top of the screen use AppodealAds::show(AppodealAds::BANNER_TOP)

### Hiding banner

To hide banner you need to call the following code:

```
AppodealAds::hide(AppodealAds::BANNER);
```

### Samples

Display interstitial after it was loaded

```
void YourClassName::onInterstitialLoaded(bool isPrecache){
	AppodealAds::show(AppodealAds::INTERSTITIAL);
}

AppodealAds::setAutoCache(AppodealAds::INTERSTITIAL, false);
AppodealAds::initialize(appKey, AppodealAds::INTERSTITIAL);
AppodealAds::cache(AppodealAds::INTERSTITIAL);
AppodealAds::setInterstitialCallback(this);
```

Your class must extend InterstitialCallbacks from Appodeal/interstitialcallbacks.h.

Display interstitial after app launch

```
AppodealAds::initialize(appKey, AppodealAds::INTERSTITIAL);
AppodealAds::show(AppodealAds::INTERSTITIAL);
```

`Note: showing fullscreen ads immediately after app launch doesn't allowed. Also, if an ad has not uploaded yet, you will see a loader, which will be disappeared after few seconds`

## Advanced features
#### Enabling test mode

```
AppodealAds::setTesting(true);
```

In test mode test ads will be shown and debug data will be written to logcat

#### Enabling logging

```
AppodealAds::setLogLevel(AppodealAds::LogLevel::verbose);
```
Enable debug logging to logcat using tag "Appodeal"

Possible values: AppodealAds::LogLevel::verbose, AppodealAds::LogLevel::debug, AppodealAds::LogLevel::none.

#### Checking if ad is loaded

```
AppodealAds::isLoaded(adTypes);
```
To check if interstitial is loaded use AppodealAds::isLoaded(AppodealAds::INTERSTITIAL)

To check if skippable video is loaded use AppodealAds::isLoaded(AppodealAds::SKIPPABLE_VIDEO)

To check if rewarded video is loaded use AppodealAds::(AppodealAds::REWARDED_VIDEO)

To check if non-skippable video is loaded use AppodealAds::(AppodealAds::NON_SKIPPABLE_VIDEO)

To check if banner is loaded use AppodealAds::isLoaded(AppodealAds::BANNER)

#### Checking if loaded ad is precache

```
AppodealAds::isPrecache(adTypes);
```

Currently supported only for interstitials, Use AppodealAds::isPrecache(AppodealAds::INTERSTITIAL)

#### Setting Interstitial callbacks

Include interstitial callbacks:

```
#include "Appodeal/interstitialcallbacks.h"
```
Extend your class with InterstitialCallbacks:

```
class YourClassName : public InterstitialCallbacks
```

Add following methods to your class:

```
virtual void onInterstitialLoaded (bool isPrecache);
virtual void onInterstitialFailedToLoad ();
virtual void onInterstitialShown();
virtual void onInterstitialClicked();
virtual void onInterstitialClosed();
```

Call

```
AppodealAds::setInterstitialCallback(this);
````

Don't forget to realize all methods.

#### Setting skippable video callbacks

Include skippable video callbacks:

```
#include "Appodeal/skippablevideocallbacks.h"
```
Extend your class with SkippalbeVideoCallbacks:

```
class YourClassName : public SkippableVideoCallbacks
```

Add following methods to your class:

```
virtual void onSkippableVideoLoaded();
virtual void onSkippableVideoFailedToLoad();
virtual void onSkippableVideoShown();
virtual void onSkippableVideoFinished();
virtual void onSkippableVideoClosed(bool isFinished);
```

Call

```
AppodealAds::setSkippableVideoCallback(this);
````

Don't forget to realize all methods.

#### Setting rewarded video callbacks

Include rewarded video callbacks:

```
#include "Appodeal/rewardedvideocallbacks.h"
```
Extend your class with RewardedVideoCallbacks:

```
class YourClassName : public RewardedVideoCallbacks
```

Add following methods to your class:

```
virtual void onRewardedVideoLoaded ();
virtual void onRewardedVideoFailedToLoad ();
virtual void onRewardedVideoShown ();
virtual void onRewardedVideoFinished (int value, QString currency);
virtual void onRewardedVideoClosed (bool isFinished);
```

Call

```
AppodealAds::setRewardedVideoCallback(this);
````

Don't forget to realize all methods.

#### Setting non-skippable video callbacks

Include non-skippable video callbacks:

```
#include "Appodeal/nonskippablevideocallbacks.h"
```
Extend your class with NonSkippableVideoCallbacks:

```
class YourClassName : public NonSkippableVideoCallbacks
```

Add following methods to your class:

```
virtual void onNonSkippableVideoLoaded();
virtual void onNonSkippableVideoFailedToLoad();
virtual void onNonSkippableVideoShown();
virtual void onNonSkippableVideoFinished();
virtual void onNonSkippableVideoClosed(bool isFinished);
```

Call

```
AppodealAds::setNonSkippableVideoCallback(this);
````

Don't forget to realize all methods.

#### Setting banner callbacks

Include banner callbacks:

```
#include "Appodeal/bannercallbacks.h"
```
Extend your class with BannerCallbacks:

```
class YourClassName : public BannerCallbacks
```

Add following methods to your class:

```
virtual void onBannerLoaded(int height, bool isPrecache);
virtual void onBannerFailedToLoad();
virtual void onBannerShown();
virtual void onBannerClicked();
```

Call

```
AppodealAds::setBannerCallback(this);
````

Don't forget to realize all methods.

#### Manual ad caching

```
AppodealAds::cache(adTypes);
```

You should disable automatic caching before SDK initialization using setAutoCache(adTypes, false).

To cache interstitial use AppodealAds::cache(AppodealAds::INTERSTITIAL)

To cache skippable video use AppodealAds::cache(AppodealAds::SKIPPABLE_VIDEO)

To cache rewarded video use AppodealAds::cache(AppodealAds::REWARDED_VIDEO)

To cache non-skippable video use AppodealAds::cache(AppodealAds::NON_SKIPPABLE_VIDEO)

To cache interstitial and video use AppodealAds::cache(AppodealAds::INTERSTITIAL | AppodealAds::SKIPPABLE_VIDEO)

#### Enabling or disabling automatic caching

```
AppodealAds::setAutoCache(adTypes, false);
```

Should be used before SDK initialization

To disable automatic caching for interstitials use AppodealAds::setAutoCache(AppodealAds::INTERSTITIAL, false)

To disable automatic caching for skippable videos use AppodealAds::setAutoCache(AppodealAds::SKIPPABLE_VIDEO, false)

To disable automatic caching for rewarded videos use AppodealAds::setAutoCache(AppodealAds::REWARDED_VIDEO, false)

To disable automatic caching for non-skippable videos use AppodealAds::setAutoCache(AppodealAds::NON_SKIPPABLE_VIDEO, false)

#### Triggering onLoaded callback twice

```
AppodealAds::setOnLoadedTriggerBoth(adTypes, true);
```

Currently supported only for interstitials

setOnLoadedTriggerBoth(AppodealAds::INTERSTITIAL, false) - onInterstitialLoaded will trigger only when normal ad was loaded (default).

setOnLoadedTriggerBoth(AppodealAds::INTERSTITIAL, true) - onInterstitialLoaded will trigger twice, both when precache and normal ad were loaded.

Should be used before SDK initialization.

#### Disabling networks

```
AppodealAds::disableNetwork("networkName");
```

Also, it’s possible to disable network only for specific ad types.

```
AppodealAds::disableNetwork("networkName", adTypes);
```

Available parameters: "amazon_ads", "applovin", "chartboost", "mopub", "unity_ads", "mailru", "facebook", "adcolony", "vungle", "yandex", "startapp", "avocarrot", "flurry", "pubnative", "cheetah", "inner-active", "revmob".

Should be used before SDK initialization

#### Remove adapters from Project

First of all, it's required  to disable network, which you want to remove.
```
AppodealAds::disableNetwork("startapp");
```

After that, you can remove unused jar files from libs folder of Appodeal plugin. Some networks are included in appodeal-1.15.5.jar file. You can open it via an archiver and remove unused dex files from assets/dex folder.

#### Disabling location permission check

To disable toast messages ACCESS_COARSE_LOCATION permission is missing use the following method:

```
AppodealAds::disableLocationPermissionCheck();
```

Should be used before SDK initialization.

`Note: disabling location permission may have a negative impact on your revenue`

#### Disabling write external storage permission check

To disable toast messages WRITE_EXTERNAL_STORAGE permission is missing use the following method:

```
AppodealAds::disableWriteExternalStoragePermissionCheck();
```

Should be used before SDK initialization.

`Note: some networks don't work without write external storage permission. They will be disabled in your application.`

#### Tracking in-app purchase

```
AppodealAds::trackInAppPurchase(currencyCode, amount);
```

Tracks in-app purchase information and sends info to our servers for analytics. Example:

```
AppodealAds::trackInAppPurchase("USD", 5);
```

### Setting user data.
Initialization

Our SDK provides the transfer of user data for better ad targeting and higher eCPM. All parameters are optional and can be defined partially.

Set the age of the user

Positive integer value.

```
AppodealAds::setAge(25);
```

Set birth date

```
AppodealAds::setBirthday("17/06/1990");
```

birthday in format "DD/MM/YYYY" or "MM/YYYY" or "YYYY"

Set user email

```
AppodealAds::setEmail("hi@appodeal.com");
```

Specify gender of the user

```
AppodealAds::setGender(AppodealAds::Gender::MALE);
```

Possible values: AppodealAds::Gender::MALE, AppodealAds::Gender::FEMALE, AppodealAds::Gender::OTHER.

Set interests of the user

```
AppodealAds::setInterests("reading, games, movies, snowboarding");
```

Specify occupation of the user

```
AppodealAds::setOccupation(AppodealAds::Occupation::OCCUPATION_OTHER);
```

Possible values: AppodealAds::Occupation::WORK, AppodealAds::Occupation::UNIVERSITY, AppodealAds::Occupation::SCHOOL, AppodealAds::Occupation::OCCUPATION_OTHER

Specify marital status of the user

```
AppodealAds::setRelation(AppodealAds::Relation::DATING);
```

Possible values: AppodealAds::Relation::DATING, AppodealAds::Relation::ENGAGED, AppodealAds::Relation::MARRIED, AppodealAds::Relation::SEARCHING, AppodealAds::Relation::SINGLE, AppodealAds::Relation::RELATION_OTHER

Set drinking habits of the user

```
AppodealAds::setAlcohol(AppodealAds::Alcohol::ALCOHOL_POSITIVE);
```

Possible values:AppodealAds::Alcohol::ALCOHOL_NEGATIVE, AppodealAds::Alcohol::ALCOHOL_NEUTRAL, AppodealAds::Alcohol::ALCOHOL_POSITIVE.

User attitude to smoking

```
AppodealAds::setSmoking(AppodealAds::Smoking::SMOKING_NEGATIVE);
```

Possible values: AppodealAds::Smoking::SMOKING_NEGATIVE, AppodealAds::Smoking::SMOKING_POSITIVE, AppodealAds::Smoking::SMOKING_NEUTRAL.

## Changelog

2.0.0 (10.04.2017)
* Cross-platform support
* Appodeal iOS SDK 1.3.9
* Appodeal Android SDK 1.15.9

1.15.5 (03.10.2016)
* Release
