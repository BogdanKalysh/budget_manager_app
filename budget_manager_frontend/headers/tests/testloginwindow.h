#ifndef TESTLOGINWINDOW_H
#define TESTLOGINWINDOW_H

#include <QObject>
#include <loginWindow.h>
#include <QtTest/QtTest>
#include <QtWidgets>

class testloginwindow : public QObject
{
    Q_OBJECT
private slots:
    void testlogin();
};

#endif // TESTLOGINWINDOW_H
