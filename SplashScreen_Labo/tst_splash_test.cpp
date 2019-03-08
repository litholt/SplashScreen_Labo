#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "spl.h"

class Splash_test: public SplashScreen
{
public:
    explicit Splash_test(QWidget *parent = nullptr): SplashScreen{parent} {}
Q_OBJECT
private slots:
    void testGui();
};

void Splash_test::testGui()
{
    //Control of the First bar
    QVERIFY(getProgress() == 0);//All'inizio

    //Control of the second bar (the one showing the loading of all the files in progress)
    //At 100% the loading was successful
    QVERIFY(getProgress2() == 100);//Alla fine

    QVERIFY(windowFlags().testFlag(Qt::WindowTransparentForInput));
    QVERIFY(windowFlags().testFlag(Qt::WindowStaysOnTopHint));
}

#include "tst_splash_test.moc"
/*
class Splash_test : public QObject
{
    Q_OBJECT

public:
    Splash_test();
    ~Splash_test();

private slots:
    void test_case1();

};

Splash_test::Splash_test()
{

}

Splash_test::~Splash_test()
{

}

void Splash_test::test_case1()
{

}
*/
