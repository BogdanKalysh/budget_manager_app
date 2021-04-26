#include "loginWindow.h"
#include "ui_loginwindow.h"
#include "constants.h"
#include "userJsonBuilder.h"
#include "userparser.h"
#include <QDebug>



LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->email_line->setPlaceholderText("email");
    ui->password_line->setPlaceholderText("password");

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
    QString query = "SELECT * FROM user WHERE mail = " + ui->email_line->text() + " AND password = " + ui->password_line->text();
    qDebug()<<query;
    QNetworkReply *getUserReply = manager->get(QNetworkRequest(QUrl("http://127.0.0.1:5000/getuser")));
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
