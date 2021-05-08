#include "signUpWindow.h"
#include "ui_signupwindow.h"
#include "constants.h"
#include "userJsonBuilder.h"
#include <QCryptographicHash>

#include <QScopedPointer>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>

SignUpWindow::SignUpWindow(QSharedPointer<QNetworkAccessManager> manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    ui->nameLine->setPlaceholderText(" name");
    ui->emailLine->setPlaceholderText(" email");
    ui->passwordLine->setPlaceholderText(" password");
    ui->repeatPasswordLine->setPlaceholderText(" repeat password");
    this->manager = manager;
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_signUpButton_clicked()
{
    //need to create database connection
    QRegularExpression emailRegExp("^[a-z0-9]([a-z0-9.]+[a-z0-9])?\\@[a-z0-9.-]+$");
    QRegularExpression passwordRegExp("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");


    if(ui->nameLine->text().isEmpty() || ui->emailLine->text().isEmpty() || ui->passwordLine->text().isEmpty()){
         QMessageBox::information(this, "Check", "Please, fill in all fields");
    }
    else if(ui->passwordLine->text() != ui->repeatPasswordLine->text())
    {
        ui->passwordLine->clear();
        ui->repeatPasswordLine->clear();
        QMessageBox::information(this, "Check", "Passwords do not match");
    }
    else if(!emailRegExp.match(ui->emailLine->text()).hasMatch() ||
           !passwordRegExp.match(ui->passwordLine->text()).hasMatch())
    {
         QMessageBox::information(this, "Check", "Not valid login or password (Password must contain minimum eight characters, at least one letter and one number)");
    }
    else
    {
        QByteArray hash = QCryptographicHash::hash(ui->passwordLine->text().toLocal8Bit(), QCryptographicHash::Sha224);
        User user(ui->nameLine->text(), ui->emailLine->text(), hash.toHex().data());
        QScopedPointer<IJsonBuilder<User>> builder (new UserJsonBuilder);
        QJsonObject jsonData =  builder->buildJson(user);
        QJsonDocument jsonDoc(jsonData);
        QByteArray byteData = jsonDoc.toJson();
        QNetworkRequest request = QNetworkRequest(QUrl("http://127.0.0.1:5000/setuser"));
        request.setRawHeader("Content-Type", "application/json");
        QNetworkReply *postUserReply = manager->post(request, byteData);
        connect(postUserReply, &QNetworkReply::finished, this, &SignUpWindow::postUser);
    }
}


void SignUpWindow::on_backToLoginButton_clicked()
{
    this->close();
    emit loginWindow();
}


void SignUpWindow::postUser()
{
   QNetworkReply *postUserReply = qobject_cast<QNetworkReply*>(sender());
   if(!postUserReply->error())
   {
       qDebug() << postUserReply->readAll();
       this->clearMask();
       this->close();
       emit loginWindow();
   }
   else
   {
       qDebug()<<postUserReply->error();
   }
    postUserReply->close();
}
