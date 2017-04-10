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
    list << "Banner" << "Interstitial" << "Rewarded video" << "Skippable Video" << "Video or Interstitial";
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
    AppodealAds::setTesting(true);
    AppodealAds::setLogLevel(AppodealAds::LogLevel::verbose);
    AppodealAds::setAge(42);
    AppodealAds::setGender(AppodealAds::Gender::MALE);
    AppodealAds::setOccupation(AppodealAds::Occupation::OCCUPATION_OTHER);
    AppodealAds::setEmail("example@gmail.com");
    AppodealAds::setInterests("jogging, football");
    AppodealAds::setCustomRule("special_user", true);
    AppodealAds::confirm(AppodealAds::SKIPPABLE_VIDEO);
    AppodealAds::requestAndroidMPermissions();
    AppodealAds::setNonSkippableVideoCallback(this);
    AppodealAds::setBannerCallback(this);
    AppodealAds::setInterstitialCallback(this);
    AppodealAds::setRewardedVideoCallback(this);
    AppodealAds::setSkippableVideoCallback(this);

    AppodealAds::initialize("722fb56678445f72fe2ec58b2fa436688b920835405d3ca6", adTypes);
}

void MainWindow::on_showButton_clicked()
{
    AppodealAds::show(getRealAdTypes(), "main_menu");
}

void MainWindow::on_isLoadedButton_clicked()
{
    bool isLoaded = AppodealAds::isLoaded(getRealAdTypes());
    QMessageBox::information(this, "Loading information", isLoaded ? "Loaded" : "Not loaded", QMessageBox::Ok);
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
        case 3:
            adType = AppodealAds::SKIPPABLE_VIDEO;
            break;
        case 4:
            adType = AppodealAds::SKIPPABLE_VIDEO | AppodealAds::INTERSTITIAL;
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

void MainWindow::onSkippableVideoLoaded(){
    qInfo("Skippable loaded");
    QMessageBox::information(this, "Skippable Callback", "Skippable Loaded", QMessageBox::Ok);
}
void MainWindow::onSkippableVideoFailedToLoad(){
    qInfo("Skippable failed to load");
    QMessageBox::information(this, "Skippable Callback", "Skippable Failed to load", QMessageBox::Ok);
}
void MainWindow::onSkippableVideoShown(){
    qInfo("Skippable shown");
    QMessageBox::information(this, "Skippable Callback", "Skippable Shown", QMessageBox::Ok);
}
void MainWindow::onSkippableVideoFinished(){
    qInfo("Skippable finished");
    QMessageBox::information(this, "Skippable Callback", "Skippable Finished", QMessageBox::Ok);
}
void MainWindow::onSkippableVideoClosed(bool isFinished){
    qInfo("Skippable closed");
    QMessageBox::information(this, "Skippable Callback", "Skippable Closed", QMessageBox::Ok);
}
