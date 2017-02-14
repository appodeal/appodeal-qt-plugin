#include "testappodeal.h"
#include "Appodeal/appodeal.h"
#include <QtTest/QtTest>

TestAppodeal::TestAppodeal(QObject *parent) : QObject(parent)
{
    Appodeal::initialize("fee50c333ff3825fd6ad6d38cff78154de3025546d47a84f", Appodeal::BANNER);
    QThread::msleep(1000 * 30);
}

void TestAppodeal::isLoaded(){
    QCOMPARE(Appodeal::isLoaded(Appodeal::BANNER), true);
}
void TestAppodeal::isPrecache(){
    QCOMPARE(Appodeal::isPrecache(Appodeal::BANNER), false);
}
void TestAppodeal::show(){
    QCOMPARE(Appodeal::show(Appodeal::BANNER), true);
}
void TestAppodeal::showWithPlacement(){
    QCOMPARE(Appodeal::show(Appodeal::BANNER, "menu"), true);
}
