#include "signUpWindow.h"
#include "ui_signupwindow.h"
#include "constants.h"
#include "userJsonBuilder.h"
#include <QDebug>


SignUpWindow::SignUpWindow(QNetworkAccessManager* manager, QWidget *parent) :
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
    if(ui->nameLine->text().isEmpty() || ui->emailLine->text().isEmpty() || ui->passwordLine->text().isEmpty()){
         QMessageBox::information(this, "Check", "Please, fill in all fields");
    }
    else if(ui->passwordLine->text() != ui->repeatPasswordLine->text())
    {
        ui->passwordLine->clear();
        ui->repeatPasswordLine->clear();
        QMessageBox::information(this, "Check", "Passwords do not match");
    }
    else
    {
        User user(ui->nameLine->text(), ui->emailLine->text(), ui->passwordLine->text());
        UserJsonBuilder builder;
        QJsonObject jsonData =  builder.buildJson(user);
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
