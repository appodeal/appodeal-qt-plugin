package com.appodeal.plugin;

import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.util.Log;

import android.app.Activity;
import android.content.res.AssetManager;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.R;

import com.appodeal.ads.Appodeal;
import com.appodeal.ads.BannerCallbacks;
import com.appodeal.ads.InterstitialCallbacks;
import com.appodeal.ads.NonSkippableVideoCallbacks;
import com.appodeal.ads.RewardedVideoCallbacks;
import com.appodeal.ads.UserSettings;


public class QTAppodeal{

    public static UserSettings userSettings;
	private boolean showSucceded;

    public void initialize (Activity a_activity, String appKey, int adType)
    {
		Appodeal.setFramework("qt", "2.1.4");
        Appodeal.initialize(a_activity, appKey, adType);
    }
	
    public boolean show(final Activity a_activity, final int adType)
    {
		showSucceded = false;
		a_activity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				showSucceded = Appodeal.show(a_activity, adType);
			}
		});
        return showSucceded;
    }
	
	public boolean show(final Activity a_activity, final int adType, final String placement){
		showSucceded = false;
		a_activity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				showSucceded = Appodeal.show(a_activity, adType, placement);
			}
		});
		return showSucceded;
	}

    public void hide (final Activity a_activity, final int adType)
    {
		a_activity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				Appodeal.hide(a_activity, adType);
			}
		});
    }

    public void setTesting (boolean flag)
    {
        Appodeal.setTesting(flag);
    }

    public void setLogLevel (int level)
    {
        com.appodeal.ads.utils.Log.LogLevel appodealLevel;
		switch(level)
		{
			case 0:
                appodealLevel = com.appodeal.ads.utils.Log.LogLevel.debug;
				break;
			case 1:
                appodealLevel = com.appodeal.ads.utils.Log.LogLevel.verbose;
				break;
			case 2:
            default:
                appodealLevel = com.appodeal.ads.utils.Log.LogLevel.none;
		}
        Appodeal.setLogLevel(appodealLevel);
    }

    public boolean isLoaded (int adType)
    {
        return Appodeal.isLoaded(adType);
    }

    public boolean isPrecache (int adType)
    {
        return Appodeal.isPrecache(adType);
    }

    public void cache (Activity a_activity, int adType)
    {
        Appodeal.cache(a_activity, adType);
    }

    public void setAutoCache (int adType, boolean flag)
    {
         Appodeal.setAutoCache(adType, flag);
    }

    public void setTriggerOnLoadedOnPrecache (int adType, boolean flag)
    {
        Appodeal.setTriggerOnLoadedOnPrecache(adType, flag);
    }

    public static native void onInterstitialLoaded(boolean isPrecache);
    public static native void onInterstitialFailedToLoad();
    public static native void onInterstitialShown();
    public static native void onInterstitialClicked();
    public static native void onInterstitialClosed();

    public void setInterstitialCallback ()
    {
        Appodeal.setInterstitialCallbacks(new InterstitialCallbacks() {

            @Override
            public void onInterstitialLoaded(boolean isPrecache){QTAppodeal.onInterstitialLoaded(isPrecache);}
            @Override
            public void onInterstitialFailedToLoad(){QTAppodeal.onInterstitialFailedToLoad();}
            @Override
            public void onInterstitialShown(){QTAppodeal.onInterstitialShown();}
            @Override
            public void onInterstitialClicked(){QTAppodeal.onInterstitialClicked();}
            @Override
            public void onInterstitialClosed(){QTAppodeal.onInterstitialClosed();}
          });

    }

    public static native void onBannerLoaded (int height, boolean isPrecache);
    public static native void onBannerFailedToLoad ();
    public static native void onBannerShown ();
    public static native void onBannerClicked ();

    public void setBannerCallback ()
    {
        Appodeal.setBannerCallbacks(new BannerCallbacks() {

            @Override
            public void onBannerLoaded(int height, boolean isPrecache){QTAppodeal.onBannerLoaded(height, isPrecache);}
            @Override
            public void onBannerFailedToLoad(){QTAppodeal.onBannerFailedToLoad();}
            @Override
            public void onBannerShown(){QTAppodeal.onBannerShown();}
            @Override
            public void onBannerClicked(){QTAppodeal.onBannerClicked();}
          });
    }
	
    public static native void onNonSkippableVideoLoaded ();
    public static native void onNonSkippableVideoFailedToLoad ();
    public static native void onNonSkippableVideoShown ();
    public static native void onNonSkippableVideoFinished ();
    public static native void onNonSkippableVideoClosed (boolean isFinished);
	
	public void setNonSkippableVideoCallback(){
		Appodeal.setNonSkippableVideoCallbacks(new NonSkippableVideoCallbacks(){
				@Override
				public void onNonSkippableVideoLoaded() { QTAppodeal.onNonSkippableVideoLoaded(); }
				@Override
				public void onNonSkippableVideoFailedToLoad() { QTAppodeal.onNonSkippableVideoFailedToLoad(); }
				@Override
				public void onNonSkippableVideoShown() {QTAppodeal.onNonSkippableVideoShown();}
				@Override
				public void onNonSkippableVideoFinished() { QTAppodeal.onNonSkippableVideoFinished(); }
				@Override
				public void onNonSkippableVideoClosed(boolean isFinished) { QTAppodeal.onNonSkippableVideoClosed(isFinished); }
		});
    }

    public static native void onRewardedVideoLoaded ();
    public static native void onRewardedVideoFailedToLoad ();
    public static native void onRewardedVideoShown ();
    public static native void onRewardedVideoFinished (int i, String s);
    public static native void onRewardedVideoClosed (boolean isFinished);

    public void setRewardedVideoCallback ()
    {
        Appodeal.setRewardedVideoCallbacks(new RewardedVideoCallbacks() {
			@Override
			public void onRewardedVideoLoaded() {QTAppodeal.onRewardedVideoLoaded();}
			@Override
			public void onRewardedVideoFailedToLoad() {QTAppodeal.onRewardedVideoFailedToLoad();}
			@Override
			public void onRewardedVideoShown() {QTAppodeal.onRewardedVideoShown();}
			@Override
			public void onRewardedVideoFinished(int i, String s) {QTAppodeal.onRewardedVideoFinished(i, s == null? "" : s);}
			@Override
			public void onRewardedVideoClosed(boolean isFinished) {QTAppodeal.onRewardedVideoClosed(isFinished);}
        });
    }

    public void disableNetwork (Activity a_activity, String network)
    {
        Appodeal.disableNetwork((Context) a_activity, (String) network);
    }

    public void disableNetwork (Activity a_activity, String network, int adType)
    {
        Appodeal.disableNetwork((Context) a_activity, (String) network, adType);
    }

    public void disableLocationPermissionCheck ()
    {
        Appodeal.disableLocationPermissionCheck();
    }

    public void trackInAppPurchase (Activity a_activity, String currencyCode, int amount)
    {
        Appodeal.trackInAppPurchase(a_activity, amount, currencyCode);
    }
	
	public boolean canShow(int adType){
		return Appodeal.canShow(adType);
	}
	
	public boolean canShow(int adType, String placement){
		return Appodeal.canShow(adType, placement);
	}
	
	public void setChildDirectedTreatment(boolean flag){
		Appodeal.setChildDirectedTreatment(flag);
	}
	
	public void muteVideosIfCallsMuted(boolean flag){
		Appodeal.muteVideosIfCallsMuted(flag);
	}

    private UserSettings getUserSettings (Activity a_activity)
    {
		if(userSettings == null)
			userSettings = Appodeal.getUserSettings(a_activity);
		return userSettings;
    }

    public void setAge (Activity a_activity, int age)
    {
        getUserSettings(a_activity).setAge(age);
    }

    public void setGender (Activity a_activity, int gender)
    {
        switch (gender)
        {
            case 0:
                getUserSettings(a_activity).setGender(UserSettings.Gender.FEMALE);
                break;
            case 1:
                getUserSettings(a_activity).setGender(UserSettings.Gender.MALE);
                break;
            case 2:
                getUserSettings(a_activity).setGender(UserSettings.Gender.OTHER);
                break;
        }
    }
	
	public void setUserId(Activity a_activity, String userId){
		getUserSettings(a_activity).setUserId(userId);
	}
	
	public void disableWriteExternalStoragePermissionCheck(){
		Appodeal.disableWriteExternalStoragePermissionCheck();
	}
	
	public void requestAndroidMPermissions(Activity a_activity){
		Appodeal.requestAndroidMPermissions(a_activity, null);
	}
	
	public void set728x90Banners(boolean flag){
		Appodeal.set728x90Banners(flag);
	}
	
	public void setBannerAnimation(boolean flag){
		Appodeal.setBannerAnimation(flag);
	}
	
	public void setCustomRule(String name, String value){
		Appodeal.setCustomRule(name, value);
	}
	
	public void setCustomRule(String name, double value){
		Appodeal.setCustomRule(name, value);
	}
	
	public void setCustomRule(String name, boolean value){
		Appodeal.setCustomRule(name, value);
	}
	
	public void setCustomRule(String name, int value){
		Appodeal.setCustomRule(name, value);
	}
	
	public void setSmartBanners(boolean flag){
		Appodeal.setSmartBanners(flag);
	}
}

