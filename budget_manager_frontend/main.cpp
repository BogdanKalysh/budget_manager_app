#include "mainWindow.h"
#include "loginWindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow loginWindow;
    loginWindow.show();

//    User usr("Петро Моставчук" ,"p_mostav@gmail.com", "password");
//    QNetworkAccessManager *manager = new QNetworkAccessManager;
//    MainWindow mainW(usr, manager);
//    mainW.show();

    return a.exec();
}
