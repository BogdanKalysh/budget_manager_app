#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    ui->nameLine->setPlaceholderText("name");
    ui->emailLine->setPlaceholderText("email");
    ui->passwordLine->setPlaceholderText("password");
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_signUpButton_clicked()
{
    this->close();
    emit loginWindow();
}
