#include "mainWindow.h"
#include "loginWindow.h"
#include <QApplication>
#include <QSharedPointer>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow loginWindow;
    loginWindow.show();

//    User usr(1, "Петро Моставчук" ,"p_mostav@gmail.com", "password");
//    QSharedPointer<QNetworkAccessManager> manager;
//    manager.reset(new QNetworkAccessManager);
//    MainWindow mainW(usr, manager);
//    mainW.show();

    return a.exec();
}
