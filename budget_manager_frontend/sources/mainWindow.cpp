#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "categoryparser.h"
#include "transactionparser.h"
#include "transactionJsonBuilder.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(User user, QNetworkAccessManager* manager,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->user = user;
    this->manager = manager;

    QString getCategoriesQuery = "http://127.0.0.1:5000/rating/getcategories?u_email=" + user.getEmail();
    QNetworkReply *categoriesReply = manager->get(QNetworkRequest(QUrl(getCategoriesQuery)));
    connect(categoriesReply, &QIODevice::readyRead, this, &MainWindow::readCategories);

    QString getTransactionsQuery = "http://127.0.0.1:5000/rating/gettransactions?u_email=" + user.getEmail() + "&lim=10";
    QNetworkReply *transactionsReply = manager->get(QNetworkRequest(QUrl(getTransactionsQuery)));
    connect(transactionsReply, &QIODevice::readyRead, this, &MainWindow::readTransactions);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::readCategories()
{
    QNetworkReply *categoriesReply = qobject_cast<QNetworkReply*>(sender());

    if(categoriesReply){
        QString categoriesStr = categoriesReply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(categoriesStr.toUtf8());
        QJsonArray json_array = jsonResponse.array();

        CategoryParser parser;
        categories = parser.parseVector(json_array);
    }

    ui->cetegoryComboBox->clear();

    if(ui->expenceRadioButton->isChecked()){
        foreach(Category cat, categories){
            if(!cat.getType())
                ui->cetegoryComboBox->addItem(cat.getName());
        }
    }else{
        foreach(Category cat, categories){
            if(cat.getType())
                ui->cetegoryComboBox->addItem(cat.getName());
        }
    }


    categoriesReply->close();
    categoriesReply->deleteLater();
}

void MainWindow::readTransactions()
{
    QNetworkReply *transactionsReply = qobject_cast<QNetworkReply*>(sender());

    if(transactionsReply){
        QString transactionsStr = transactionsReply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(transactionsStr.toUtf8());
        QJsonArray json_array = jsonResponse.array();

        TransactionParser parser;
        transactions = parser.parseVector(json_array);
    }

    transactionsReply->close();
    transactionsReply->deleteLater();
}

void MainWindow::finishedPostTransactions()
{
    QNetworkReply *postTranasactionReply = qobject_cast<QNetworkReply*>(sender());

    if(postTranasactionReply->error() == QNetworkReply::NoError){
        QString contents = QString::fromUtf8(postTranasactionReply->readAll());
        qDebug() << contents;
    }
    else{
        QString error = postTranasactionReply->errorString();
        qDebug() << error;
    }
    postTranasactionReply->close();
    postTranasactionReply->deleteLater();
}


void MainWindow::on_addTransactionButton_clicked()
{

    int amount;
    if (ui->incomeRadioButton->isChecked())
        amount = ui->amountInputLine->text().toInt();
    else
        amount = -ui->amountInputLine->text().toInt();

    QString description = ui->descriptionInputLine->text();
    QString category = ui->cetegoryComboBox->currentText();
    int categoryId(0);

    foreach(Category cat, categories){
        if(cat.getType() == ui->incomeRadioButton->isChecked() && cat.getName() == category){
            categoryId = cat.getId();
            break;
        }
    }

    Transaction transaction(0, amount, description, categoryId);
    TransactionJsonBuilder builder;
    QJsonObject jsonData =  builder.buildJson(transaction);
    QJsonDocument jsonDoc(jsonData);
    QByteArray byteData = jsonDoc.toJson();


    QNetworkRequest request = QNetworkRequest(QUrl("http://127.0.0.1:5000/rating/posttransaction"));
    request.setRawHeader("Content-Type", "application/json");
    QNetworkReply* postTranasactionReply = manager->post(request, byteData);
    connect(postTranasactionReply, &QNetworkReply::finished, this, &MainWindow::finishedPostTransactions);

}

void MainWindow::on_incomeRadioButton_clicked()
{
    ui->cetegoryComboBox->clear();
    foreach(Category cat, categories){
        if(cat.getType())
            ui->cetegoryComboBox->addItem(cat.getName());
    }

}

void MainWindow::on_expenceRadioButton_clicked()
{
    ui->cetegoryComboBox->clear();
    foreach(Category cat, categories){
        if(!cat.getType())
            ui->cetegoryComboBox->addItem(cat.getName());
    }
}
