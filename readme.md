# Appodeal QT plugin

## Download SDK

You can download Appodeal plugin for QT here.

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

Also copy TARGET value from *.pro file, open Appodeal/android/AndroidManifest.xml in text editor, find the following line:
```
<meta-data android:name="android.app.lib_name" android:value="AppodealDemo"/>
```
And replace AppodealDemo with your TARGET value.

### iOS Integration

After building iOS Project you will get error: `Appodeal.framework/Appodeal(AVHttpClient.o)' does not contain bitcode. You must rebuild it with bitcode enabled (Xcode setting ENABLE_BITCODE), obtain an updated library from the vendor, or disable bitcode for this target. for architecture arm64` don't worry, just open compiled xcode project, go to `Build Settings` Set `Enable Bitcode` to `No` and remove `-fembed-bitcode-marker` flag from  `Other Linker Flags`.
Now you can succesfully build your project.

### Ad types

Appodeal::INTERSTITIAL

Appodeal::SKIPPABLE_VIDEO

Appodeal::BANNER

Appodeal::BANNER_TOP

Appodeal::BANNER_BOTTOM

Appodeal::REWARDED_VIDEO

Appodeal::NON_SKIPPABLE_VIDEO

Ad types can be combined using "|" operator. For example Appodeal::INTERSTITIAL | Appodeal::SKIPPABLE_VIDEO

Note that it is better to use NON_SKIPPABLE_VIDEO or REWARDED_VIDEO, but if you are sure you want to use SKIPPABLE_VIDEO you must confirm usage by calling Appodeal::confirm(Appodeal::SKIPPABLE_VIDEO) before SDK initialization

### SDK initialization

Import Appodeal header to your code:
```
#include "Appodeal/appodealads.h"
```
To initialize SDK you need to add following code:

```
QString appKey = "fee50c333ff3825fd6ad6d38cff78154de3025546d47a84f";
Appodeal::initialize(appKey, Appodeal::BANNER | Appodeal::INTERSTITIAL);
```

Note: appKey is the key you received when you created an app.

To initialize only interstitials use Appodeal::initialize(appKey, Appodeal::INTERSTITIAL)

To initialize only skippable videos use Appodeal::initialize(appKey, Appodeal::SKIPPABLE_VIDEO)

To initialize interstitials and videos use Appodeal::initialize(appKey, Appodeal::INTERSTITIAL | Appodeal::SKIPPABLE_VIDEO)

To initialize only banners use Appodeal::initialize(appKey, Appodeal::BANNER)

To initialize only rewarded video use Appodeal::initialize(appKey, Appodeal::REWARDED_VIDEO)

To initialize only non-skippable video use Appodeal::initialize(appKey, Appodeal::NON_SKIPPABLE_VIDEO)

###. Display ad

```
Appodeal::show(adTypes);
```

show() returns a boolean value indicating whether show call was passed to appropriate SDK

To display interstitial use Appodeal::show(Appodeal::INTERSTITIAL)

To display skippable video use Appodeal::show(Appodeal::SKIPPABLE_VIDEO)

To display rewarded video use Appodeal::show(Appodeal::REWARDED_VIDEO)

To display non-skippable video use Appodeal::show(Appodeal::NON_SKIPPABLE_VIDEO)

To display interstitial or video use Appodeal::show(Appodeal::INTERSTITIAL | Appodeal::SKIPPABLE_VIDEO)

To display banner at the bottom of the screen use sppodeal::Show(Appodeal::BANNER_BOTTOM)

To display banner at the top of the screen use Appodeal::show(Appodeal::BANNER_TOP)

### Hiding banner

To hide banner you need to call the following code:

```
Appodeal::hide(Appodeal::BANNER);
```

### Samples

Display interstitial after it was loaded

```
void YourClassName::onInterstitialLoaded(bool isPrecache){
	Appodeal::show(Appodeal::INTERSTITIAL);
}

Appodeal::setAutoCache(Appodeal::INTERSTITIAL, false);
Appodeal::initialize(appKey, Appodeal::INTERSTITIAL);
Appodeal::cache(Appodeal::INTERSTITIAL);
Appodeal::setInterstitialCallback(this);
```

Your class must extend InterstitialCallbacks from Appodeal/interstitialcallbacks.h.

Display interstitial after app launch

```
Appodeal::initialize(appKey, Appodeal::INTERSTITIAL);
Appodeal::show(Appodeal::INTERSTITIAL);
```

`Note: showing fullscreen ads immediately after app launch doesn't allowed. Also, if an ad has not uploaded yet, you will see a loader, which will be disappeared after few seconds`

## Advanced features
#### Enabling test mode

```
Appodeal::setTesting(true);
```

In test mode test ads will be shown and debug data will be written to logcat

#### Enabling logging

```
Appodeal::setLogLevel(Appodeal::LogLevel::verbose);
```
Enable debug logging to logcat using tag "Appodeal"

Possible values: Appodeal::LogLevel::verbose, Appodeal::LogLevel::debug, Appodeal::LogLevel::none.

#### Checking if ad is loaded

```
Appodeal::isLoaded(adTypes);
```
To check if interstitial is loaded use Appodeal::isLoaded(Appodeal::INTERSTITIAL)

To check if skippable video is loaded use Appodeal::isLoaded(Appodeal::SKIPPABLE_VIDEO)

To check if rewarded video is loaded use Appodeal::(Appodeal::REWARDED_VIDEO)

To check if non-skippable video is loaded use Appodeal::(Appodeal::NON_SKIPPABLE_VIDEO)

To check if banner is loaded use Appodeal::isLoaded(Appodeal::BANNER)

#### Checking if loaded ad is precache

```
Appodeal::isPrecache(adTypes);
```

Currently supported only for interstitials, Use Appodeal::isPrecache(Appodeal::INTERSTITIAL)

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
Appodeal::setInterstitialCallback(this);
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
Appodeal::setSkippableVideoCallback(this);
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
Appodeal::setRewardedVideoCallback(this);
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
Appodeal::setNonSkippableVideoCallback(this);
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
Appodeal::setBannerCallback(this);
````

Don't forget to realize all methods.

#### Manual ad caching

```
Appodeal::cache(adTypes);
```

You should disable automatic caching before SDK initialization using setAutoCache(adTypes, false).

To cache interstitial use Appodeal::cache(Appodeal::INTERSTITIAL)

To cache skippable video use Appodeal::cache(Appodeal::SKIPPABLE_VIDEO)

To cache rewarded video use Appodeal::cache(Appodeal::REWARDED_VIDEO)

To cache non-skippable video use Appodeal::cache(Appodeal::NON_SKIPPABLE_VIDEO)

To cache interstitial and video use Appodeal::cache(Appodeal::INTERSTITIAL | Appodeal::SKIPPABLE_VIDEO)

#### Enabling or disabling automatic caching

```
Appodeal::setAutoCache(adTypes, false);
```

Should be used before SDK initialization

To disable automatic caching for interstitials use Appodeal::setAutoCache(Appodeal::INTERSTITIAL, false)

To disable automatic caching for skippable videos use Appodeal::setAutoCache(Appodeal::SKIPPABLE_VIDEO, false)

To disable automatic caching for rewarded videos use Appodeal::setAutoCache(Appodeal::REWARDED_VIDEO, false)

To disable automatic caching for non-skippable videos use Appodeal::setAutoCache(Appodeal::NON_SKIPPABLE_VIDEO, false)

#### Triggering onLoaded callback twice

```
Appodeal::setOnLoadedTriggerBoth(adTypes, true);
```

Currently supported only for interstitials

setOnLoadedTriggerBoth(Appodeal::INTERSTITIAL, false) - onInterstitialLoaded will trigger only when normal ad was loaded (default).

setOnLoadedTriggerBoth(Appodeal::INTERSTITIAL, true) - onInterstitialLoaded will trigger twice, both when precache and normal ad were loaded.

Should be used before SDK initialization.

#### Disabling networks

```
Appodeal::disableNetwork("networkName");
```

Also, it’s possible to disable network only for specific ad types.

```
Appodeal::disableNetwork("networkName", adTypes);
```

Available parameters: "amazon_ads", "applovin", "chartboost", "mopub", "unity_ads", "mailru", "facebook", "adcolony", "vungle", "yandex", "startapp", "avocarrot", "flurry", "pubnative", "cheetah", "inner-active", "revmob".

Should be used before SDK initialization

#### Remove adapters from Project

First of all, it's required  to disable network, which you want to remove.
```
Appodeal::disableNetwork("startapp");
```

After that, you can remove unused jar files from libs folder of Appodeal plugin. Some networks are included in appodeal-1.15.5.jar file. You can open it via an archiver and remove unused dex files from assets/dex folder.

#### Disabling location permission check

To disable toast messages ACCESS_COARSE_LOCATION permission is missing use the following method:

```
Appodeal::disableLocationPermissionCheck();
```

Should be used before SDK initialization.

`Note: disabling location permission may have a negative impact on your revenue`

#### Disabling write external storage permission check

To disable toast messages WRITE_EXTERNAL_STORAGE permission is missing use the following method:

```
Appodeal::disableWriteExternalStoragePermissionCheck();
```

Should be used before SDK initialization.

`Note: some networks don't work without write external storage permission. They will be disabled in your application.`

#### Tracking in-app purchase

```
Appodeal::trackInAppPurchase(currencyCode, amount);
```

Tracks in-app purchase information and sends info to our servers for analytics. Example:

```
Appodeal::trackInAppPurchase("USD", 5);
```

### Setting user data.
Initialization

Our SDK provides the transfer of user data for better ad targeting and higher eCPM. All parameters are optional and can be defined partially.

Set the age of the user

Positive integer value.

```
Appodeal::setAge(25);
```

Set birth date

```
Appodeal::setBirthday("17/06/1990");
```

birthday in format "DD/MM/YYYY" or "MM/YYYY" or "YYYY"

Set user email

```
Appodeal::setEmail("hi@appodeal.com");
```

Specify gender of the user

```
Appodeal::setGender(Appodeal::Gender::MALE);
```

Possible values: Appodeal::Gender::MALE, Appodeal::Gender::FEMALE, Appodeal::Gender::OTHER.

Set interests of the user

```
Appodeal::setInterests("reading, games, movies, snowboarding");
```

Specify occupation of the user

```
Appodeal::setOccupation(Appodeal::Occupation::OCCUPATION_OTHER);
```

Possible values: Appodeal::Occupation::WORK, Appodeal::Occupation::UNIVERSITY, Appodeal::Occupation::SCHOOL, Appodeal::Occupation::OCCUPATION_OTHER

Specify marital status of the user

```
Appodeal::setRelation(Appodeal::Relation::DATING);
```

Possible values: Appodeal::Relation::DATING, Appodeal::Relation::ENGAGED, Appodeal::Relation::MARRIED, Appodeal::Relation::SEARCHING, Appodeal::Relation::SINGLE, Appodeal::Relation::RELATION_OTHER

Set drinking habits of the user

```
Appodeal::setAlcohol(Appodeal::Alcohol::ALCOHOL_POSITIVE);
```

Possible values:Appodeal::Alcohol::ALCOHOL_NEGATIVE, Appodeal::Alcohol::ALCOHOL_NEUTRAL, Appodeal::Alcohol::ALCOHOL_POSITIVE.

User attitude to smoking

```
Appodeal::setSmoking(Appodeal::Smoking::SMOKING_NEGATIVE);
```

Possible values: Appodeal::Smoking::SMOKING_NEGATIVE, Appodeal::Smoking::SMOKING_POSITIVE, Appodeal::Smoking::SMOKING_NEUTRAL.

## Changelog

2.0.0 (10.04.2017)
* Cross-platform support
* Appodeal iOS SDK 1.3.9
* Appodeal Android SDK 1.15.9

1.15.5 (03.10.2016)
* Release
