#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSharedPointer>


namespace Ui{
class SignUpWindow;
class TestSignUpWindow;
}

class SignUpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignUpWindow(const QSharedPointer<QNetworkAccessManager> &manager, QWidget *parent = nullptr);
    ~SignUpWindow();

signals:
    void loginWindow();

private slots:
    int on_signUpButton_clicked();
    void on_backToLoginButton_clicked();
    void postUser();
    void setName(QString name);
    void setEmail(QString surname);
    void setPassword(QString password);
    void setPasswordConfirmation(QString confirmation);
private:

    Ui::SignUpWindow *ui;
    QSharedPointer<QNetworkAccessManager> manager;
    friend class TestSignUpWindow;
};

#endif // SIGNUPWINDOW_H
