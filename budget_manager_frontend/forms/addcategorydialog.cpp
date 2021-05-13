#include "addcategorydialog.h"
#include "ui_addcategorydialog.h"
#include "IJsonBuilder.h"
#include "categoryJsonBuilder.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QColorDialog>
#include <category.h>

AddCategoryDialog::AddCategoryDialog(int userId, Type type, QSharedPointer<QNetworkAccessManager> manager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCategoryDialog)
{
    this->userId = userId;
    this->type = type;
    this->manager = manager;
    this->color = "white";

    ui->setupUi(this);
}

AddCategoryDialog::~AddCategoryDialog()
{
    delete ui;
}

void AddCategoryDialog::on_addCategoryButton_clicked()
{
    name = ui->categoryNameInput->text();

    if(name == ""){
        QMessageBox::about(this, "info", "Заповніть назву");
    }
    else
    {

        QSharedPointer<IJsonBuilder<Category>> builder (new CategoryJsonBuilder);
        QJsonDocument jsonDoc(builder->buildJson(Category (0, name, type, QColor(color), userId)));
        QByteArray byteData = jsonDoc.toJson();

        QNetworkRequest request = QNetworkRequest(QUrl(jsonbuilder::CATEGORYURL));
        request.setRawHeader("Content-Type", "application/json");
        QNetworkReply* postCategoryReply = manager->post(request, byteData);
        connect(postCategoryReply, &QNetworkReply::finished, this, &AddCategoryDialog::finishedPostCategory);

        ui->categoryNameInput->clear();
    }
}

void AddCategoryDialog::finishedPostCategory()
{
    QNetworkReply *postCategoryReply = qobject_cast<QNetworkReply*>(sender());

    if(postCategoryReply->error() == QNetworkReply::NoError){
        QString contents = QString::fromUtf8(postCategoryReply->readAll());
        qDebug() << contents;
    }
    else
    {
        QString error = postCategoryReply->errorString();
        qDebug() << error;
        QMessageBox::about(this, "info", "Error: " + error);
    }

    postCategoryReply->close();
    postCategoryReply->deleteLater();
}

void AddCategoryDialog::on_colorPicker_clicked()
{
    QColorDialog *dialog = new QColorDialog;
    color = dialog->getColor().name();
    ui->colorPicker->setStyleSheet("background: " + color);

    delete dialog;
}
