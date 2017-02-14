#ifndef TESTAPPODEAL_H
#define TESTAPPODEAL_H

#include <QObject>

class TestAppodeal : public QObject
{
    Q_OBJECT
public:
    explicit TestAppodeal(QObject *parent = 0);

private slots:
    void isLoaded();
    void isPrecache();
    void show();
    void showWithPlacement();
};

#endif // TESTAPPODEAL_H
