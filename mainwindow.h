#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Appodeal/appodeal.h"
#include "Appodeal/nonskippablevideocallbacks.h"
#include "Appodeal/bannercallbacks.h"
#include "Appodeal/interstitialcallbacks.h"
#include "Appodeal/rewardedvideocallbacks.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public NonSkippableVideoCallbacks, public BannerCallbacks, public InterstitialCallbacks, public RewardedVideoCallbacks
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual void onNonSkippableVideoLoaded();
    virtual void onNonSkippableVideoFailedToLoad();
    virtual void onNonSkippableVideoShown();
    virtual void onNonSkippableVideoFinished();
    virtual void onNonSkippableVideoClosed(bool isFinished);
    virtual void onBannerLoaded(int height, bool isPrecache);
    virtual void onBannerFailedToLoad();
    virtual void onBannerShown();
    virtual void onBannerClicked();
    virtual void onInterstitialLoaded (bool isPrecache);
    virtual void onInterstitialFailedToLoad ();
    virtual void onInterstitialShown();
    virtual void onInterstitialClicked();
    virtual void onInterstitialClosed();
	virtual void onInterstitialFinished();
    virtual void onRewardedVideoLoaded ();
    virtual void onRewardedVideoFailedToLoad ();
    virtual void onRewardedVideoShown ();
    virtual void onRewardedVideoFinished (int value, QString currency);
    virtual void onRewardedVideoClosed (bool isFinished);
    ~MainWindow();

private slots:
    void on_initializeButton_clicked();

    void on_showButton_clicked();

    void on_isLoadedButton_clicked();

    void on_hideButton_clicked();

    void on_cacheButton_clicked();

    void on_isPrecacheButton_clicked();

    void on_showWithPlacement_clicked();

private:
    Ui::MainWindow *ui;
    int getRealAdTypes();
};

#endif // MAINWINDOW_H
