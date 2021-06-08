#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QScopedPointer>
#include "mainWindow.h"
#include "signUpWindow.h"
#include <QSharedPointer>
#include "testloginwindow.h"

namespace Ui {
class LoginWindow;
class testloginwindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_loginButton_clicked();
    void on_signUpLoginButton_clicked();
    void onResult();

private:
    void setEmail(QString email);
    void setPassword(QString password);
    friend class testloginwindow;
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;
    SignUpWindow *signUpWindow;
    QSharedPointer<QNetworkAccessManager> manager;
    User user;

};

#endif // LOGINWINDOW_H
