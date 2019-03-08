#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

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

QTEST_MAIN(Splash_test)

#include "tst_splash_test.moc"
