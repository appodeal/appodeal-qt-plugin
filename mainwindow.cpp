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
    if(ui->logging->isChecked())
        Appodeal::setLogLevel(Appodeal::LogLevel::verbose);
    else
        Appodeal::setLogLevel(Appodeal::LogLevel::none);
    Appodeal::setTesting(ui->testing->isChecked());
    Appodeal::setAutoCache(adTypes, ui->autoCache->isChecked());
    Appodeal::setOnLoadedTriggerBoth(adTypes, ui->enableTriggerOnLoadedOnPrecache->isChecked());
    if(ui->confirm->isChecked())
        Appodeal::confirm(adTypes);

    Appodeal::setAge(42);
    Appodeal::setGender(Appodeal::Gender::MALE);
    Appodeal::setOccupation(Appodeal::Occupation::OCCUPATION_OTHER);
    Appodeal::setEmail("example@gmail.com");
    Appodeal::setInterests("jogging, football");

    Appodeal::setCustomRule("special_user", true);
    Appodeal::setCustomRule("user_age", 25);
    Appodeal::setCustomRule("time_online", 1.5);
    Appodeal::setCustomRule("some_string_rule", "value");


    Appodeal::requestAndroidMPermissions();
    Appodeal::set728x90Banners(!ui->disable728x90Banners->isChecked());
    Appodeal::setSmartBanners(!ui->disableSmartBanners->isChecked());
    Appodeal::setBannerAnimation(!ui->disableBannerAnimation->isChecked());
    if(ui->disableLocationPermissionCheck->isChecked())
        Appodeal::disableLocationPermissionCheck();
    if(ui->disableWriteExternalStorageCheck->isChecked())
        Appodeal::disableWriteExternalStoragePermissionCheck();

    Appodeal::setNonSkippableVideoCallback(this);
    Appodeal::setBannerCallback(this);
    Appodeal::setInterstitialCallback(this);
    Appodeal::setRewardedVideoCallback(this);

    Appodeal::initialize("fee50c333ff3825fd6ad6d38cff78154de3025546d47a84f", adTypes);
}

void MainWindow::on_showButton_clicked()
{
    Appodeal::show(getRealAdTypes());
}

void MainWindow::on_isLoadedButton_clicked()
{
    bool isLoaded = Appodeal::isLoaded(getRealAdTypes());
    QMessageBox::information(this, "Loading information", isLoaded ? "Loaded" : "Not loaded", QMessageBox::Ok);
}

void MainWindow::on_hideButton_clicked()
{
    Appodeal::hide(getRealAdTypes());
}

void MainWindow::on_cacheButton_clicked()
{
    Appodeal::cache(getRealAdTypes());
}

int MainWindow::getRealAdTypes(){
    int adType = ui->adType->currentIndex();
    switch(adType){
        case 0:
            adType = Appodeal::BANNER;
            break;
        case 1:
            adType = Appodeal::INTERSTITIAL;
            break;
        case 2:
            adType = Appodeal::REWARDED_VIDEO;
            break;
    }
    return adType;
}

void MainWindow::onNonSkippableVideoLoaded(){
    qInfo("Video loaded");
    QMessageBox::information(this, "Video Callback", "Loaded", QMessageBox::Ok);
}
void MainWindow::onNonSkippableVideoFailedToLoad(){
    qInfo("Video falied to load");
    QMessageBox::information(this, "Video Callback", "Failed to load", QMessageBox::Ok);
}
void MainWindow::onNonSkippableVideoShown(){
    qInfo("Video shown");
    QMessageBox::information(this, "Video Callback", "Shown", QMessageBox::Ok);
}
void MainWindow::onNonSkippableVideoFinished(){
    qInfo("Video finished");
}
void MainWindow::onNonSkippableVideoClosed(bool isFinished){
    qInfo("Video closed");
    QMessageBox::information(this, "Video Callback", "Closed", QMessageBox::Ok);
}

void MainWindow::onBannerLoaded(int height, bool isPrecache){
    qInfo("Banner loaded");
    QMessageBox::information(this, "Banner Callback", "Loaded", QMessageBox::Ok);
}

void MainWindow::onBannerFailedToLoad(){
    qInfo("Banner failed to load");
    QMessageBox::information(this, "Banner Callback", "Failed to load", QMessageBox::Ok);
}

void MainWindow::onBannerShown(){
    qInfo("Banner shown");
    QMessageBox::information(this, "Banner Callback", "Shown", QMessageBox::Ok);
}

void MainWindow::onBannerClicked(){
    qInfo("Banner clicked");
    QMessageBox::information(this, "Banner Callback", "clicked", QMessageBox::Ok);
}

void MainWindow::onInterstitialLoaded (bool isPrecache){
    qInfo("Interstitial loaded");
    QMessageBox::information(this, "Interstitial Callback", "Loaded", QMessageBox::Ok);
}
void MainWindow::onInterstitialFailedToLoad (){
    qInfo("Interstitial failed to load");
    QMessageBox::information(this, "Interstitial Callback", "Failed to load", QMessageBox::Ok);
}
void MainWindow::onInterstitialShown(){
    qInfo("Interstitial shown");
    QMessageBox::information(this, "Interstitial Callback", "Shown", QMessageBox::Ok);
}
void MainWindow::onInterstitialClicked(){
    qInfo("Interstitial clicked");
    QMessageBox::information(this, "Interstitial Callback", "Clicked", QMessageBox::Ok);
}
void MainWindow::onInterstitialClosed(){
    qInfo("Interstitial closed");
    QMessageBox::information(this, "Interstitial Callback", "Closed", QMessageBox::Ok);
}

void MainWindow::onInterstitialFinished(){
	qInfo("Interstitial finished");
    QMessageBox::information(this, "Interstitial Callback", "Finished", QMessageBox::Ok);
}

void MainWindow::onRewardedVideoLoaded (){
    qInfo("Rewarded loaded");
    QMessageBox::information(this, "Rewarded Callback", "Loaded", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoFailedToLoad (){
    qInfo("Rewarded failed to load");
    QMessageBox::information(this, "Rewarded Callback", "Failed to load", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoShown (){
    qInfo("Rewarded shown");
    QMessageBox::information(this, "Rewarded Callback", "Shown", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoFinished (int value, QString currency){
    qInfo("Rewarded finished");
    qInfo(QString::number(value).toStdString().c_str());
    qInfo(currency.toStdString().c_str());
    QMessageBox::information(this, "Rewarded Callback", "Finished", QMessageBox::Ok);
}
void MainWindow::onRewardedVideoClosed (bool isFinished){
    qInfo("Rewarded closed");
    QMessageBox::information(this, "Rewarded Callback", "Closed", QMessageBox::Ok);
}

void MainWindow::on_isPrecacheButton_clicked()
{
    bool isLoaded = Appodeal::isPrecache(getRealAdTypes());
    QMessageBox::information(this, "Information", isLoaded ? "Precache" : "Not precache", QMessageBox::Ok);
}

void MainWindow::on_showWithPlacement_clicked()
{
    Appodeal::show(getRealAdTypes(), "main_menu");
}
