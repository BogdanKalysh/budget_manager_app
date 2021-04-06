#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->email_line->setPlaceholderText("email");
    ui->password_line->setPlaceholderText("password");

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_loginButton_clicked()
{
    this->hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();

}
