#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "constants.h"
#include <QJsonObject>
#include <QJsonValue>



SignUpWindow::SignUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    ui->nameLine->setPlaceholderText(" name");
    ui->emailLine->setPlaceholderText(" email");
    ui->passwordLine->setPlaceholderText(" password");
    ui->repeatPasswordLine->setPlaceholderText(" repeat password");
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_signUpButton_clicked()
{
    //need to create database connection
    if(ui->nameLine->text().isEmpty() || ui->emailLine->text().isEmpty() || ui->passwordLine->text().isEmpty()){
         QMessageBox::information(this, "Check", "Please, fill in all fields");
    }
    else if(ui->passwordLine->text() != ui->repeatPasswordLine->text())
    {
        ui->passwordLine->clear();
        ui->repeatPasswordLine->clear();
        QMessageBox::information(this, "Check", "Passwords do not match");
    }
    else{
        //if(database.open())
        QJsonObject jObj;
        jObj.insert(jsoncreator::NAME, QJsonValue::fromVariant(ui->nameLine->text()));
        jObj.insert(jsoncreator::EMAIL, QJsonValue::fromVariant(ui->emailLine->text()));
        jObj.insert(jsoncreator::PASSWORD, QJsonValue::fromVariant(ui->passwordLine->text()));

        // insert data from object "user" to database
        this->clearMask();
        this->close();
        emit loginWindow();
    }
}

void SignUpWindow::on_backToLoginButton_clicked()
{
    this->close();
    emit loginWindow();
}
