#ifndef TESTSIGNUPWINDOW_H
#define TESTSIGNUPWINDOW_H

#include <QObject>
#include <QtTest/QtTest>
#include <QtWidgets>
#include <signUpWindow.h>

class TestSignUpWindow : public QObject
{
    Q_OBJECT
private slots:
    void testSignUp();
};

#endif // TESTSIGNUPWINDOW_H
