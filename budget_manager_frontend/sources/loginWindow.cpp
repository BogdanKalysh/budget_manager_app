#include "loginWindow.h"
#include "ui_loginwindow.h"
#include "constants.h"
#include "loginJsonBuilder.h"

#include <QDebug>

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
    //connect to db
    QByteArray passwordHash = QCryptographicHash::hash(ui->password_line->text().toLocal8Bit(), QCryptographicHash::Sha224);
    User user(ui->email_line->text(), passwordHash.toHex().data());

    LoginJsonBuilder jObj;
    QJsonObject json = jObj.buildJson(user);
    qDebug()<<json;

    //if(database.open()){

    if(ui->email_line->text()=="qwerty" && ui->password_line->text() == "123123"){
        mainWindow = new MainWindow();
        mainWindow->show();
        this->close();
    }
    else{
        QMessageBox::critical(this, "Failed", "Wrong login or password");
    }


}


void LoginWindow::on_signUpLoginButton_clicked()
{
    signUpWindow->show();
    this->close();
}
