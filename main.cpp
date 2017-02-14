#include "mainwindow.h"
#include <QApplication>
#include <QtTest/QtTest>
#include "testappodeal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new TestAppodeal, argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
    return 0;
}
