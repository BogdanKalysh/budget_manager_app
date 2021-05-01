#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkAccessManager>

//#include "user.h"


namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpWindow(QNetworkAccessManager* manager, QWidget *parent = nullptr);
    ~SignUpWindow();

signals:
    void loginWindow();

private slots:
    void on_signUpButton_clicked();

    void on_backToLoginButton_clicked();

    void postUser();

private:
    Ui::SignUpWindow *ui;
    QNetworkAccessManager* manager;
};

#endif // SIGNUPWINDOW_H



