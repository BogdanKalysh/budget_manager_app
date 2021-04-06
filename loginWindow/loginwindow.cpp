#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->email_line->setPlaceholderText("email");
    ui->password_line->setPlaceholderText("password");
    signUpWindow = new SignUpWindow();
    connect(signUpWindow, &SignUpWindow::loginWindow, this, &LoginWindow::show);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_loginButton_clicked()
{
    mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void LoginWindow::on_signUpLoginButton_clicked()
{
    signUpWindow->show();
    this->close();
}
