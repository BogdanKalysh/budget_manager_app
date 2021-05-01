#include "loginWindow.h"
#include "ui_loginwindow.h"
#include "constants.h"
#include "userJsonBuilder.h"
<<<<<<< HEAD
#include "userparser.h"
=======
#include <QCryptographicHash>

>>>>>>> 66c1eb63193cf74ddaad7cb888a3f961f1103bff
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    manager.reset(new QNetworkAccessManager);

    manager = new QNetworkAccessManager();
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
<<<<<<< HEAD
=======
    //connect to db
    QByteArray passwordHash = QCryptographicHash::hash(ui->password_line->text().toLocal8Bit(), QCryptographicHash::Sha224);
    User user(ui->email_line->text(), passwordHash.toHex().data());

>>>>>>> 66c1eb63193cf74ddaad7cb888a3f961f1103bff
    QString query = "SELECT * FROM user WHERE mail = " + ui->email_line->text() + " AND password = " + ui->password_line->text();
    qDebug()<<query;
    QNetworkReply *getUserReply = manager->get(QNetworkRequest(QUrl("http://127.0.0.1:5000/getusers")));
    connect(getUserReply, &QIODevice::readyRead, this, &LoginWindow::onResult);
}


void LoginWindow::on_signUpLoginButton_clicked()
{
    signUpWindow->show();
    this->close();
}


void LoginWindow::onResult()
{
    QNetworkReply *getUserReply = qobject_cast<QNetworkReply*>(sender());
    if(!getUserReply->error())
    {
        QJsonDocument jsonResponse = QJsonDocument::fromJson(getUserReply->readAll());
        QJsonObject jUser = jsonResponse.object();
        qDebug()<<jUser;
        UserParser parser;
        user = parser.parse(jUser);
        if(user.getName().length()){
            qDebug()<<user.getName();
            mainWindow = new MainWindow(user, manager);
            mainWindow->show();
            this->close();
        }
        else
        {
            qDebug()<<user.getName().length();
            QMessageBox::critical(this, "Failed", "Wrong login or password");
        }
    }
    else
    {
        qDebug()<<getUserReply->error();
    }

    getUserReply->close();
}
