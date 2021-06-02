#include "loginWindow.h"
#include "ui_loginwindow.h"
#include "constants.h"
#include "userJsonBuilder.h"
#include "userparser.h"

#include <QCryptographicHash>
#include <QDebug>
#include <QStyle>
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
    signUpWindow = new SignUpWindow(manager);

    connect(signUpWindow, &SignUpWindow::loginWindow, this, &LoginWindow::show);
    connect(ui->email_line, &QLineEdit::textChanged, [=]{ style()->polish(ui->email_line); });
    connect(ui->password_line, &QLineEdit::textChanged, [=]{ style()->polish(ui->password_line); });
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_loginButton_clicked()
{   
    QByteArray passwordHash = QCryptographicHash::hash(ui->password_line->text().toLocal8Bit(), QCryptographicHash::Sha224);
    User user(ui->email_line->text(), passwordHash.toHex().data());

    QNetworkReply *getUserReply = manager->get(QNetworkRequest(QUrl(jsonbuilder::USERURL + "?" + jsonbuilder::EMAIL +
                                                                    "=" + user.getEmail() + "&" + jsonbuilder::PASSWORD +
                                                                    "=" + user.getPassword())));

    connect(getUserReply, &QIODevice::readChannelFinished, this, &LoginWindow::onResult);
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
        QScopedPointer<IJsonParser<User>> parser (new UserParser);
        user = parser->parse(jUser);
        if(user.getName().length())
        {
            qDebug()<<user.getName();
            mainWindow = new MainWindow(user, manager);
            mainWindow->show();
            this->close();
        }
        else
        {
            QMessageBox::critical(this, "Failed", "Не правильний Email чи пароль");
        }
    }
    else
    {
        qDebug()<<getUserReply->error();
        QMessageBox::critical(this, "Failed", "Не правильний Email чи пароль");
    }

    getUserReply->close();
    getUserReply->deleteLater();
}
