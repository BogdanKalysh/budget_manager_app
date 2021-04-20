#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <stdarg.h>

#include <QDebug>
#include <iostream>
#include <QString>
#include "constants.h"
#include <QJsonObject>
#include <QJsonValue>

class A
{
    int a,b,c;
};

void func(int num, ...)
{
    va_list args;
    va_start(args, num);


    std::cout<<va_arg(args,int);
    num--;
    //std::cout<<va_arg(args, QString);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow loginWindow;
    loginWindow.show();

    func(2,1,2.5);
    QJsonObject jObj;
    jObj.insert(jsoncreator::EMAIL, QJsonValue::fromVariant("sdfsdfsdf"));
    jObj.insert(jsoncreator::PASSWORD, QJsonValue::fromVariant("aaaaaaaaaaaaa"));
    qDebug()<<jObj;

    return a.exec();
}
