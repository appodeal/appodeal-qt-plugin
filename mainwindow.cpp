#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QString>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList list;
    list << "Banner" << "Interstitial" << "Rewarded video";
    ui->adType->addItems(list);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::red);
    setAutoFillBackground(true);
    setPalette(Pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_initializeButton_clicked()
{
    int adTypes = getRealAdTypes();
    bool autoCache = ui->autoCache->isChecked();
	
    AppodealAds::setAutoCache(adTypes, autoCache);
    AppodealAds::setTesting(false);
    AppodealAds::setLogLevel(AppodealAds::LogLevel::verbose);
    AppodealAds::muteVideosIfCallsMuted(true);
    AppodealAds::setChildDirectedTreatment(true);
    AppodealAds::setTriggerOnLoadedOnPrecache(AppodealAds::INTERSTITIAL, true);
    AppodealAds::disableNetwork("cheetah");
    AppodealAds::setAge(42);
    AppodealAds::setGender(AppodealAds::Gender::MALE);
    AppodealAds::setCustomRule("special_user", true);
    AppodealAds::requestAndroidMPermissions();
    //AppodealAds::setNonSkippableVideoCallback(this);
    AppodealAds::setBannerCallback(this);
    AppodealAds::setInterstitialCallback(this);
    AppodealAds::setRewardedVideoCallback(this);

    AppodealAds::initialize("fee50c333ff3825fd6ad6d38cff78154de3025546d47a84f", adTypes);
}

void MainWindow::on_showButton_clicked()
{
    AppodealAds::show(getRealAdTypes(), "main_menu");
}

void MainWindow::on_isLoadedButton_clicked()
{
    bool isLoaded = AppodealAds::isLoaded(getRealAdTypes());
    bool canShow = AppodealAds::canShow(getRealAdTypes());
    bool canShowPlacement = AppodealAds::canShow(getRealAdTypes(), "default");
    QMessageBox::information(this, "Loading information", isLoaded ? "Loaded" : "Not loaded", QMessageBox::Ok);
    QMessageBox::information(this, "Can Show?", canShow ? "True" : "False", QMessageBox::Ok);
    QMessageBox::information(this, "Can Show Default?", canShowPlacement ? "True" : "False", QMessageBox::Ok);
}

void MainWindow::on_hideButton_clicked()
{
    AppodealAds::hide(getRealAdTypes());
}

void MainWindow::on_cacheButton_clicked()
{
    AppodealAds::cache(getRealAdTypes());
}

int MainWindow::getRealAdTypes(){
    int adType = ui->adType->currentIndex();
    switch(adType){
        case 0:
            adType = AppodealAds::BANNER;
            break;
        case 1:
            adType = AppodealAds::INTERSTITIAL;
            break;
        case 2:
            adType = AppodealAds::REWARDED_VIDEO;
            break;
    }
    return adType;
}

void MainWindow::onNonSkippableVideoLoaded(){
    qInfo("Video loaded");
    QMessageBox::information(this, "Video Callback", "Video Loaded", QMessageBox::Ok);
}
void MainWindow::onNonSkippableVideoFailedToLoad(){
    qInfo("Video falied to load");
    QMessageBox::information(this, "Video Callback", "Video Failed to load", QMessageBox::Ok);
}
void MainWindow::onNonSkippableVideoShown(){
    qInfo("Video shown");
    QMessageBox::information(this, "Video Callback", "Video  Shown", QMessageBox::Ok);
}
void MainWindow::onNonSkippableVideoFinished(){
    QMessageBox::information(this, "Video Callback", "Video  Finished", QMessageBox::Ok);
    qInfo("Video finished");
}
void MainWindow::onNonSkippableVideoClosed(bool isFinished){
    qInfo("Video closed");
    QMessageBox::information(this, "Video Callback", "Video Closed", QMessageBox::Ok);
}

void MainWindow::onBannerLoaded(int height, bool isPrecache){
    qInfo("Banner loaded");
    QMessageBox::information(this, "Banner Callback", "Banner Loaded", QMessageBox::Ok);
}

void MainWindow::onBannerFailedToLoad(){
    qInfo("Banner failed to load");
    QMessageBox::information(this, "Banner Callback", "Banner Failed to load", QMessageBox::Ok);
}

void MainWindow::onBannerShown(){
    qInfo("Banner shown");
    QMessageBox::information(this, "Banner Callback", "Banner Shown", QMessageBox::Ok);
}

void MainWindow::onBannerClicked(){
    qInfo("Banner clicked");
    QMessageBox::information(this, "Banner Callback", "Banner clicked", QMessageBox::Ok);
}

void MainWindow::onInterstitialLoaded (bool isPrecache){
    qInfo("Interstitial loaded");
    QMessageBox::information(this, "Interstitial Callback", "Interstitial Loaded", QMessageBox::Ok);
}
void MainWindow::onInterstitialFailedToLoad (){
    qInfo("Interstitial failed to load");
    QMessageBox::information(this, "Interstitial Callback", "Interstitial Failed to load", QMessageBox::Ok);
}
void MainWindow::onInterstitialShown(){
    qInfo("Interstitial shown");
    QMessageBox::information(this, "Interstitial Callback", "Interstitial Shown", QMessageBox::Ok);
}
void MainWindow::onInterstitialClicked(){
    qInfo("Interstitial clicked");
    QMessageBox::information(this, "Interstitial Callback", "Interstitial Clicked", QMessageBox::Ok);
}
void MainWindow::onInterstitialClosed(){
    qInfo("Interstitial closed");
    QMessageBox::information(this, "Interstitial Callback", "Interstitial Closed", QMessageBox::Ok);
}

void MainWindow::onRewardedVideoLoaded (){
    qInfo("Rewarded loaded");
    QMessageBox::information(this, "Rewarded Callback", "Rewarded Loaded", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoFailedToLoad (){
    qInfo("Rewarded failed to load");
    QMessageBox::information(this, "Rewarded Callback", "Rewarded Failed to load", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoShown (){
    qInfo("Rewarded shown");
    QMessageBox::information(this, "Rewarded Callback", "Rewarded Shown", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoFinished (int value, QString currency){
    QMessageBox::information(this, "Rewarded Callback", "Rewarded Finished", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoClosed (bool isFinished){
    qInfo("Rewarded closed");
    QMessageBox::information(this, "Rewarded Callback", "Rewarded Closed", QMessageBox::Ok);
}
