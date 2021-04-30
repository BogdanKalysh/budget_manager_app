#include "loginWindow.h"
#include "ui_loginwindow.h"
#include "constants.h"
#include "userJsonBuilder.h"
#include <QCryptographicHash>

#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    manager.reset(new QNetworkAccessManager);

    signUpWindow = new SignUpWindow(manager);
    connect(signUpWindow, &SignUpWindow::loginWindow, this, &LoginWindow::show);
}

LoginWindow::~LoginWindow()
{
    if(mainWindow)
        delete mainWindow;
    if(signUpWindow)
        delete signUpWindow;
    delete ui;
}


void LoginWindow::on_loginButton_clicked()
{
    //connect to db
    QByteArray passwordHash = QCryptographicHash::hash(ui->password_line->text().toLocal8Bit(), QCryptographicHash::Sha224);
    User user(ui->email_line->text(), passwordHash.toHex().data());

    QString query = "SELECT * FROM user WHERE mail = " + ui->email_line->text() + " AND password = " + ui->password_line->text();

    UserJsonBuilder jObj;
    QJsonObject json = jObj.buildJson(user);
    qDebug()<<json;

    //if(database.open()){

    if(ui->email_line->text()=="qwerty" && ui->password_line->text() == "123123"){
        mainWindow = new MainWindow(user, manager);

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
