//package place your package name here;

import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.util.Log;
import org.qtproject.qt5.android.bindings.QtActivity;
import org.qtproject.qt5.android.bindings.QtApplication;

import android.app.Activity;
import android.content.res.AssetManager;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.R;

import com.appodeal.ads.Appodeal;
import com.appodeal.ads.BannerCallbacks;
import com.appodeal.ads.InterstitialCallbacks;
import com.appodeal.ads.VideoCallbacks;
import com.appodeal.ads.RewardedVideoCallbacks;
import com.appodeal.ads.UserSettings;


public class AppodealActivity extends QtActivity{

    public static AppodealActivity a_activity = null;
    public static UserSettings userSettings;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        a_activity = this;
        super.onCreate(savedInstanceState);
    }

    public void initialize (String appKey, int adType)
    {
        Appodeal.initialize(a_activity, appKey, adType);
    }
	
    public boolean show(int adType)
    {
        return Appodeal.show(a_activity, adType);
    }

    public void hide (int adType)
    {
        Appodeal.hide(a_activity, adType);
    }

    public void setTesting (boolean flag)
    {
        Appodeal.setTesting(flag);
    }

    public void setLogging (boolean flag)
    {
        Appodeal.setLogging(flag);
    }

    public boolean isLoaded (int adType)
    {
        return Appodeal.isLoaded(adType);
    }

    public boolean isPrecache (int adType)
    {
        return Appodeal.isPrecache(adType);
    }

    public void cache (int adType)
    {
        Appodeal.cache((Activity)a_activity, adType);
    }

    public void setAutoCache (int adType, boolean flag)
    {
         Appodeal.setAutoCache(adType, flag);
    }

    public void setOnLoadedTriggerBoth (int adType, boolean flag)
    {
        Appodeal.setOnLoadedTriggerBoth(adType, flag);
    }

    public static native void onInterstitialLoaded();
    public static native void onInterstitialFailedToLoad();
    public static native void onInterstitialShown();
    public static native void onInterstitialClicked();
    public static native void onInterstitialClosed();

    public void setInterstitialCallback ()
    {
        Appodeal.setInterstitialCallbacks(new InterstitialCallbacks() {

            @Override
            public void onInterstitialLoaded(boolean isPrecache)
            {
                AppodealActivity.onInterstitialLoaded();
            }

            @Override
            public void onInterstitialFailedToLoad()
            {
                AppodealActivity.onInterstitialFailedToLoad();
            }

            @Override
            public void onInterstitialShown()
            {
                AppodealActivity.onInterstitialShown();
            }

            @Override
            public void onInterstitialClicked()
            {
                AppodealActivity.onInterstitialClicked();
            }

            @Override
            public void onInterstitialClosed()
            {
                AppodealActivity.onInterstitialClosed();
            }

          });

    }

    public static native void onBannerLoaded ();
    public static native void onBannerFailedToLoad ();
    public static native void onBannerShown ();
    public static native void onBannerClicked ();

    public void setBannerCallback ()
    {
        Appodeal.setBannerCallbacks(new BannerCallbacks() {

            @Override
            public void onBannerLoaded()
            {
                AppodealActivity.onBannerLoaded();
            }

            @Override
            public void onBannerFailedToLoad()
            {
                AppodealActivity.onBannerFailedToLoad();
            }

            @Override
            public void onBannerShown()
            {
                AppodealActivity.onBannerShown();
            }

            @Override
            public void onBannerClicked()
            {
                AppodealActivity.onBannerClicked();
            }

          });
    }

    public static native void onVideoLoaded ();
    public static native void onVideoFailedToLoad ();
    public static native void onVideoShown ();
    public static native void onVideoFinished ();
    public static native void onVideoClosed ();

    public void setVideoCallback ()
    {
        Appodeal.setVideoCallbacks(new VideoCallbacks() {

            @Override
            public void onVideoLoaded()
            {
                AppodealActivity.onVideoLoaded();
            }

            @Override
            public void onVideoFailedToLoad()
            {
                AppodealActivity.onVideoFailedToLoad();
            }

            @Override
            public void onVideoShown()
            {
                AppodealActivity.onVideoShown();
            }

            @Override
            public void onVideoFinished()
            {
                AppodealActivity.onVideoFinished();
            }

            @Override
            public void onVideoClosed()
            {
                AppodealActivity.onVideoClosed();
            }

          });
    }

    public static native void onRewardedVideoLoaded ();
    public static native void onRewardedVideoFailedToLoad ();
    public static native void onRewardedVideoShown ();
    public static native void onRewardedVideoFinished ();
    public static native void onRewardedVideoClosed ();

    public void setRewardedVideoCallback ()
    {
        Appodeal.setRewardedVideoCallbacks(new RewardedVideoCallbacks() {

            @Override
            public void onVideoLoaded()
            {
                AppodealActivity.onRewardedVideoLoaded();
            }

            @Override
            public void onVideoFailedToLoad()
            {
                AppodealActivity.onRewardedVideoFailedToLoad();
            }

            @Override
            public void onVideoShown()
            {
                AppodealActivity.onRewardedVideoShown();
            }

            @Override
            public void onVideoFinished(int amount, String name)
            {
                AppodealActivity.onRewardedVideoFinished();
            }

            @Override
            public void onVideoClosed()
            {
                AppodealActivity.onRewardedVideoClosed();
            }

          });
    }

    public boolean showWithPriceFloor (int adType)
    {
        return Appodeal.showWithPriceFloor(a_activity, adType);
    }

    public boolean isLoadedWithPriceFloor (int adType)
    {
        return Appodeal.isLoadedWithPriceFloor(adType);
    }

    public void disableNetwork (String network)
    {
        Appodeal.disableNetwork((Context) a_activity, (String) network);
    }

    public void disableNetwork (String network, int adType)
    {
        Appodeal.disableNetwork((Context) a_activity, (String) network, adType);
    }

    public void disableLocationPermissionCheck ()
    {
        Appodeal.disableLocationPermissionCheck();
    }

    public void trackInAppPurchase (String currencyCode, int amount)
    {
        Appodeal.trackInAppPurchase(a_activity, amount, currencyCode);
    }

    public void getUserSettings ()
    {
        userSettings = Appodeal.getUserSettings(a_activity);
    }

    public void setAge (int age)
    {
        userSettings.setAge(age);
    }

    public void setBirthday (String day)
    {
        userSettings.setBirthday(day);
    }

    public void setEmail (String email)
    {
        userSettings.setEmail(email);
    }

    public void setFacebookId (String faceId)
    {
        userSettings.setFacebookId(faceId);
    }

    public void setVkId (String vkId)
    {
        userSettings.setVkId(vkId);
    }

    public void setGender (int gender)
    {
        switch (gender)
        {
            case 0:
                userSettings.setGender(UserSettings.Gender.FEMALE);
                break;
            case 1:
                userSettings.setGender(UserSettings.Gender.MALE);
                break;
            case 2:
                userSettings.setGender(UserSettings.Gender.OTHER);
                break;
        }
    }

    public void setInterests (String interest)
    {
        userSettings.setInterests(interest);
    }

    public void setOccupation (int occupation)
    {
        switch (occupation)
        {
            case 0:
                userSettings.setOccupation(UserSettings.Occupation.WORK);
                break;
            case 1:
                userSettings.setOccupation(UserSettings.Occupation.UNIVERSITY);
                break;
            case 2:
                userSettings.setOccupation(UserSettings.Occupation.SCHOOL);
                break;
            case 3:
                userSettings.setOccupation(UserSettings.Occupation.OTHER);
                break;
        }
    }

    public void setRelation (int relation)
    {
        switch (relation)
        {
            case 0:
                userSettings.setRelation(UserSettings.Relation.DATING);
                break;
            case 1:
                userSettings.setRelation(UserSettings.Relation.ENGAGED);
                break;
            case 2:
                userSettings.setRelation(UserSettings.Relation.MARRIED);
                break;
            case 3:
                userSettings.setRelation(UserSettings.Relation.SEARCHING);
                break;
            case 4:
                userSettings.setRelation(UserSettings.Relation.SINGLE);
                break;
            case 5:
                userSettings.setRelation(UserSettings.Relation.OTHER);
                break;
        }
    }

    public void setAlcohol (int alcohol)
    {
        switch (alcohol)
        {
            case 0:
                userSettings.setAlcohol(UserSettings.Alcohol.NEGATIVE);
                break;
            case 1:
                userSettings.setAlcohol(UserSettings.Alcohol.NEUTRAL);
                break;
            case 2:
                userSettings.setAlcohol(UserSettings.Alcohol.POSITIVE);
                break;
        }
    }

    public void setSmoking (int smoking)
    {
        switch (smoking)
        {
            case 0:
                userSettings.setSmoking(UserSettings.Smoking.NEGATIVE);
                break;
            case 1:
                userSettings.setSmoking(UserSettings.Smoking.NEUTRAL);
                break;
            case 2:
                userSettings.setSmoking(UserSettings.Smoking.POSITIVE);
                break;
        }
    }

    @Override
    protected void onDestroy ()
    {
        super.onDestroy();
        a_activity = null;
    }
	
}

