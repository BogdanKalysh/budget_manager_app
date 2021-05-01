#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QScopedPointer>
#include "mainWindow.h"
#include "signUpWindow.h"
#include <QSharedPointer>


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
    void onResult();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;
    SignUpWindow *signUpWindow;
<<<<<<< HEAD
    //QScopedPointer<QNetworkAccessManager> manager;
    QNetworkAccessManager *manager;
    User user;
=======
    QSharedPointer<QNetworkAccessManager> manager;
>>>>>>> 66c1eb63193cf74ddaad7cb888a3f961f1103bff
};

#endif // LOGINWINDOW_H
