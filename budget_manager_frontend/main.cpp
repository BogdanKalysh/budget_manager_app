#include "mainWindow.h"
#include "loginWindow.h"
#include <QApplication>
#include <QSharedPointer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow loginWindow;
    loginWindow.show();

    return a.exec();
}
