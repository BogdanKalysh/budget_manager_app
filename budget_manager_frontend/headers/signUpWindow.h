#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkAccessManager>
<<<<<<< HEAD

=======
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSharedPointer>
>>>>>>> 66c1eb63193cf74ddaad7cb888a3f961f1103bff
//#include "user.h"


namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpWindow(QSharedPointer<QNetworkAccessManager> manager, QWidget *parent = nullptr);
    ~SignUpWindow();

signals:
    void loginWindow();

private slots:
    void on_signUpButton_clicked();
    void on_backToLoginButton_clicked();

    void postUser();

private:
    Ui::SignUpWindow *ui;
    QSharedPointer<QNetworkAccessManager> manager;
};

#endif // SIGNUPWINDOW_H



