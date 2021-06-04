#include "signUpWindow.h"
#include "ui_signupwindow.h"
#include "constants.h"
#include "userJsonBuilder.h"
#include <QCryptographicHash>
#include <QStyle>

#include <QScopedPointer>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>

using namespace messagebox;

SignUpWindow::SignUpWindow(const QSharedPointer<QNetworkAccessManager> &manager, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);

    this->manager = manager;

    connect(ui->nameLine, &QLineEdit::textChanged, [=]{ style()->polish(ui->nameLine); });
    connect(ui->emailLine, &QLineEdit::textChanged, [=]{ style()->polish(ui->emailLine); });
    connect(ui->passwordLine, &QLineEdit::textChanged, [=]{ style()->polish(ui->passwordLine); });
    connect(ui->repeatPasswordLine, &QLineEdit::textChanged, [=]{ style()->polish(ui->repeatPasswordLine); });
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_signUpButton_clicked()
{
    QRegularExpression emailRegExp("^[a-z0-9]([a-z0-9.]+[a-z0-9])?\\@[a-z0-9.-]+$");
    QRegularExpression passwordRegExp("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");


    if (ui->nameLine->text().isEmpty() || ui->emailLine->text().isEmpty() || ui->passwordLine->text().isEmpty()) {
        QMessageBox::information(this, CHECK, FILLIN);
    } else if (ui->passwordLine->text() != ui->repeatPasswordLine->text()) {
        ui->passwordLine->clear();
        ui->repeatPasswordLine->clear();
        QMessageBox::information(this, CHECK, PASSDONTMATCH);
    } else if (!emailRegExp.match(ui->emailLine->text()).hasMatch() ||
           !passwordRegExp.match(ui->passwordLine->text()).hasMatch()) {
         QMessageBox::information(this, CHECK, NOTVALIDMAILPASS);
    } else {
        QByteArray hash = QCryptographicHash::hash(ui->passwordLine->text().toLocal8Bit(), QCryptographicHash::Sha224);
        User user(0, ui->nameLine->text(), ui->emailLine->text(), hash.toHex().data());

        QScopedPointer<IJsonBuilder<User>> builder (new UserJsonBuilder);

        QByteArray byteData = QJsonDocument(builder->buildJson(user)).toJson();
        QNetworkRequest request = QNetworkRequest(QUrl(urls::USERURL));
        request.setRawHeader(urls::CONTENTTYPE.toUtf8(), urls::APPLICATIONJSON.toUtf8());

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

    if (!postUserReply->error()) {
        ui->emailLine->clear();
        ui->nameLine->clear();
        ui->passwordLine->clear();
        ui->repeatPasswordLine->clear();

        this->clearMask();
        this->close();
        emit loginWindow();
    } else {
        qDebug()<<postUserReply->error();
        QMessageBox::information(this, FAILED, ERRCREATEUSER);
    }

    postUserReply->close();
}
