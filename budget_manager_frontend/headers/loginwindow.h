#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "mainwindow.h"
#include "signupwindow.h"


namespace Ui {
class LoginWindow;
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

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;
    SignUpWindow *signUpWindow;

};

#endif // LOGINWINDOW_H
