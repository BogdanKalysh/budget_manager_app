#include "usersettingsdialog.h"
#include "ui_usersettingsdialog.h"
#include "IJsonBuilder.h"
#include "userJsonBuilder.h"
#include <QCryptographicHash>

#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>
#include <categoryparser.h>

UserSettingsDialog::UserSettingsDialog(User& user, QSharedPointer<QNetworkAccessManager> manager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSettingsDialog)
{
    ui->setupUi(this);

    this->user = user;
    this->manager = manager;

    this->ui->nameInputField->setText(user.getName());
    this->ui->emailInputField->setText(user.getEmail());

    connect(ui->emailInputField, &QLineEdit::textChanged, [=]{ style()->polish(ui->emailInputField); });
    connect(ui->nameInputField, &QLineEdit::textChanged, [=]{ style()->polish(ui->nameInputField); });
    connect(ui->oldPasswordInput, &QLineEdit::textChanged, [=]{ style()->polish(ui->oldPasswordInput); });
    connect(ui->newPasswordInput, &QLineEdit::textChanged, [=]{ style()->polish(ui->newPasswordInput); });

    updateCategories();
}

UserSettingsDialog::~UserSettingsDialog()
{
    delete ui;
}

User UserSettingsDialog::getUser()
{
    return user;
}

void UserSettingsDialog::updateCategories()
{
    QString getCategoriesQuery = jsonbuilder::CATEGORYURL + "?" + jsonbuilder::USER_ID + "=" + QString::number(user.getId());
    QNetworkReply *categoriesReply = manager->get(QNetworkRequest(QUrl(getCategoriesQuery)));
    connect(categoriesReply, &QNetworkReply::readyRead, this, &UserSettingsDialog::readCategories);
}

void UserSettingsDialog::readCategories()
{
    QNetworkReply *categoriesReply = qobject_cast<QNetworkReply*>(sender());

    if(categoriesReply){
        QString categoriesStr = categoriesReply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(categoriesStr.toUtf8());
        QJsonArray json_array = jsonResponse.array();

        QSharedPointer<IJsonParser<Category>> parser (new CategoryParser);
        categories = parser->parseVector(json_array);
    }

    ui->categoriesComboBox->clear();

    for (Category& cat: categories){
        ui->categoriesComboBox->addItem(cat.getName(), cat.getId());
    }

    categoriesReply->close();
    categoriesReply->deleteLater();
}

void UserSettingsDialog::on_saveButton_clicked()
{
    if(!ui->oldPasswordInput->text().isEmpty() || !ui->newPasswordInput->text().isEmpty() ){
        QString oldPasswordHash = QCryptographicHash::hash(ui->oldPasswordInput->text().toLocal8Bit(), QCryptographicHash::Sha224).toHex().data();

        QNetworkRequest request = QNetworkRequest(QUrl(jsonbuilder::USERURL + "?" + jsonbuilder::EMAIL + "="
            + user.getEmail() + "&" + jsonbuilder::PASSWORD + "=" + oldPasswordHash));

        QNetworkReply* getUserReply = manager->get(request);
        connect(getUserReply, &QIODevice::readChannelFinished, this, &UserSettingsDialog::updatePassword);
    }else{
        QString newName = ui->nameInputField->text();
        QString newEmail = ui->emailInputField->text();

        User newuser(user.getId(), newName, newEmail, user.getPassword());

        updateUser(newuser);
    }
}

void UserSettingsDialog::updatePassword()
{
    QNetworkReply *getUserReply = qobject_cast<QNetworkReply*>(sender());
    QString contents = QString::fromUtf8(getUserReply->readAll());

    if(contents.isEmpty()){
        QRegularExpression passwordRegExp("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{8,}$");

        QString newName = ui->nameInputField->text();
        QString newEmail = ui->emailInputField->text();
        QString newPassword = QCryptographicHash::hash(ui->newPasswordInput->text().toLocal8Bit(), QCryptographicHash::Sha224).toHex().data();

        if(!passwordRegExp.match(ui->newPasswordInput->text()).hasMatch())
        {
            QMessageBox::about(this, "info", "Введено некоректний новий пароль.");
        }else{
            User newuser(user.getId(), newName, newEmail, newPassword);

            updateUser(newuser);
        }
    }else if(getUserReply->error() == QNetworkReply::ConnectionRefusedError){
        QMessageBox::about(this, "info", "Немає зв'язку з сервером");
    }else{
        QMessageBox::about(this, "info", "Неправильний старий пароль");
    }


    getUserReply->close();
    getUserReply->deleteLater();
}

void UserSettingsDialog::updateUser(User& newuser)
{
    QRegularExpression emailRegExp("^[a-z0-9]([a-z0-9.]+[a-z0-9])?\\@[a-z0-9.-]+$");

    if(newuser.getName().isEmpty())
    {
        QMessageBox::about(this, "info", "Введіть ім'я");
    }
    else if(!emailRegExp.match(newuser.getEmail()).hasMatch())
    {
        QMessageBox::about(this, "info", "Введено некоректний Email");
    }
    else
    {
        QScopedPointer<IJsonBuilder<User>> builder (new UserJsonBuilder);
        QJsonObject jsonData =  builder->buildJson(newuser);
        QJsonDocument jsonDoc(jsonData);
        QByteArray byteData = jsonDoc.toJson();
        QNetworkRequest request = QNetworkRequest(QUrl(jsonbuilder::USERURL));
        request.setRawHeader("Content-Type", "application/json");
        QNetworkReply *updateUserReply = manager->put(request, byteData);

        connect(updateUserReply, &QNetworkReply::finished, this, &UserSettingsDialog::finishedUpdateUser);
    }
}

void UserSettingsDialog::finishedUpdateUser()
{
    QNetworkReply *getUserReply = qobject_cast<QNetworkReply*>(sender());

    if(getUserReply->error() == QNetworkReply::NoError)
    {
        user.setEmail(ui->emailInputField->text());
        user.setName(ui->nameInputField->text());
        if(ui->newPasswordInput->text() != ""){
            user.setPassword(QCryptographicHash::hash(ui->newPasswordInput->text().toLocal8Bit(), QCryptographicHash::Sha224).toHex().data());
        }
        ui->oldPasswordInput->clear();
        ui->newPasswordInput->clear();
        QMessageBox::about(this, "info", "Дані змінено");
    }
    else if(getUserReply->error() == QNetworkReply::ContentAccessDenied){
        QMessageBox::about(this, "info", "Така пошта вже зайнята");
    }
    else if(getUserReply->error() == QNetworkReply::ConnectionRefusedError)
    {
        QMessageBox::about(this, "info", "Немає зв'язку з сервером");
    }
    else
    {
        qDebug() << getUserReply->error();
        QMessageBox::about(this, "info", getUserReply->errorString());
    }
}

void UserSettingsDialog::finishedDeleteCategory()
{
    QNetworkReply *getUserReply = qobject_cast<QNetworkReply*>(sender());

    if(getUserReply->error() == QNetworkReply::NoError){
        updateCategories();
        QMessageBox::about(this, "info", "Категорію видалено");
    }else if(getUserReply->error() == QNetworkReply::ConnectionRefusedError)
    {
        QMessageBox::about(this, "info", "Немає зв'язку з сервером");
    }
    else
    {
        qDebug() << getUserReply->error();
        QMessageBox::about(this, "info", getUserReply->errorString());
    }

}

void UserSettingsDialog::on_deleteCategoryButton_clicked()
{
    if(ui->categoriesComboBox->currentData().isNull()){
        QMessageBox::about(this, "info", "Не обрано категорії");
    }else {
        QNetworkRequest request = QNetworkRequest(QUrl(jsonbuilder::CATEGORYURL + "?"
            + jsonbuilder::ID + "=" + ui->categoriesComboBox->currentData().toString()));
        QNetworkReply* delTranasactionReply = manager->deleteResource(request);

        connect(delTranasactionReply, &QNetworkReply::finished, this, &UserSettingsDialog::finishedDeleteCategory);
    }
}
