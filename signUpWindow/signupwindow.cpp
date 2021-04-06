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
    //need to create database connection

    //if(database.open())
   QString name = ui->nameLine->text();
   QString email = ui->emailLine->text();
   QString password = ui->passwordLine->text();

   User user(1, name, email, password);

   // insert data from object "user" to database

    this->close();
    emit loginWindow();
}
