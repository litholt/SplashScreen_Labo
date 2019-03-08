#include "spl.h"
#include "r_manag.h"
#include "r_display.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;w.show();

    ResourceManager manager{"data"};
    ResourceDisplay splash{&manager};

    //Init
    manager.addResource(":/files/ima2.png","ima2.png");
    manager.addResource(":/files/open.txt","open.txt");
    manager.addResource(":/files/splash-720.jpg","splash-720.jpg");

    //Load
    manager.LoadResource();

    return a.exec();
}
