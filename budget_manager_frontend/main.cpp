#include "mainWindow.h"
#include "loginWindow.h"
#include <QApplication>

#include <QtCore>
//#include <QtHttpServer>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow loginWindow;
    loginWindow.show();

//    User usr("ddd", "ddd");
//    MainWindow mainW(usr);
//    mainW.show();

    return a.exec();
}
