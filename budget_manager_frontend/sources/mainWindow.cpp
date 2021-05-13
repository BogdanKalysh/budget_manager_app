#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "categoryparser.h"
#include "transactionparser.h"
#include "transactionJsonBuilder.h"
#include "TransactionsListItem.h"
#include "constants.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

MainWindow::MainWindow(User user, QSharedPointer<QNetworkAccessManager> manager,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->user = user;
    this->manager = manager;

    series = new QPieSeries();
    chartView = new QChartView();
    ui->pieChart->addWidget(chartView, 0);

    sumAmountLabel = new QLabel("", chartView);
    ui->userName->setText(user.getName());

    configWindowItems();
}

MainWindow::~MainWindow()
{
    delete sumAmountLabel;
    delete series;
    delete chartView;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    sumAmountLabel->move((ui->pieChartDonut->width()-sumAmountLabel->width())/2,
                        (ui->pieChartDonut->height()-sumAmountLabel->height())/2);
}


void MainWindow::updateTransactions()
{
    QString getTransactionsQuery = "http://localhost:5000/transaction?" + jsonbuilder::USER_ID + "=" +
            QString::number(user.getId()) + "&" + jsonbuilder::START_DATE + "=" + fromDateTransactions.toString("yyyy-MM-dd") +
            "&" + jsonbuilder::END_DATE + "=" + toDateTransactions.toString("yyyy-MM-dd");
    QNetworkReply *transactionsReply = manager->get(QNetworkRequest(QUrl(getTransactionsQuery)));
    connect(transactionsReply, &QNetworkReply::readyRead, this, &MainWindow::readTransactions);
}

void MainWindow::updateCategories()
{
    QString getCategoriesQuery = "http://localhost:5000/category?" + jsonbuilder::USER_ID + "=" + QString::number(user.getId());
    QNetworkReply *categoriesReply = manager->get(QNetworkRequest(QUrl(getCategoriesQuery)));
    connect(categoriesReply, &QNetworkReply::readyRead, this, &MainWindow::readCategories);
}


void MainWindow::readCategories()
{
    QNetworkReply *categoriesReply = qobject_cast<QNetworkReply*>(sender());

    if(categoriesReply){
        QString categoriesStr = categoriesReply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(categoriesStr.toUtf8());
        QJsonArray json_array = jsonResponse.array();

        QSharedPointer<IJsonParser<Category>> parser (new CategoryParser);
        categories = parser->parseVector(json_array);
    }

    ui->categoryComboBox->clear();

    for (Category& cat: categories){
        if(cat.getType() == ui->incomeRadioButton->isChecked()){
            ui->categoryComboBox->addItem(cat.getName(), cat.getId());
        }else if(!cat.getType() == ui->expenceRadioButton->isChecked()){
            ui->categoryComboBox->addItem(cat.getName(), cat.getId());
        }
    }

    updateList();
    updatePiechart();

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

        QSharedPointer<IJsonParser<Transaction>> parser (new TransactionParser);
        transactions = parser->parseVector(json_array);
    }

    updateList();
    updatePiechart();

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
    else
    {
        QString error = postTranasactionReply->errorString();
        qDebug() << error;
        QMessageBox::about(this, "info", "Error: " + error);
    }

    updateTransactions();

    postTranasactionReply->close();
    postTranasactionReply->deleteLater();
}


void MainWindow::configWindowItems()
{
    series->setHoleSize(0.77);
    series->setPieSize(1);
    chartView->chart()->addSeries(series);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->legend()->setVisible(false);
    chartView->chart()->setBackgroundVisible(false);

    sumAmountLabel->setStyleSheet("font-size: 33px; color:white;");

    QPixmap settingsPixMap(":/new/img/settings_icon.png");
    QPixmap userPixMap(":/new/img/user_icon.png");
    int w(40), h(40);
    ui->settingsIcon->setPixmap(settingsPixMap.scaled(w, h, Qt::KeepAspectRatio));
    ui->userIcon->setPixmap(userPixMap.scaled(w, h, Qt::KeepAspectRatio));

    ui->amountInputLine->setValidator(new QIntValidator(0, 1000000000, this));

    QDate dateNow(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day());
    QDate dateMountAgo = dateNow.addMonths(-1);

    fromDateTransactions.setDate(dateMountAgo.year(), dateMountAgo.month(), dateMountAgo.day());
    toDateTransactions.setDate(dateNow.year(), dateNow.month(), dateNow.day());

    ui->fromDateEdit->setDate(fromDateTransactions);
    ui->toDateEdit->setDate(toDateTransactions);

    updateTransactions();
    updateCategories();
}


qreal MainWindow::getCategoryTotalSum(QString categoryName)
{
    qreal totalsum = 0;

    for(Transaction &transac : transactions){
        if(transac.getCategoryName() == categoryName)
            totalsum += transac.getAmount();
    }

    return totalsum;
}

void MainWindow::updatePiechart()
{
    int amountSum(0);
    series->clear();
    if(transactions.size() != 0){
        for(Category& cat: categories){
            amountSum += getCategoryTotalSum(cat.getName());
            QPieSlice *slice = series->append(cat.getName(), getCategoryTotalSum(cat.getName()));
            slice->setBorderWidth(0);
            slice->setPen(Qt::NoPen);
            slice->setColor(QColor(cat.getColor()));
        }
    }else{
        QPieSlice *slice = series->append("0", 1);
        slice->setBorderWidth(0);
        slice->setPen(Qt::NoPen);
        slice->setColor(QColor("#528bba"));
    }
    sumAmountLabel->setText(QString::number(amountSum) + " ₴");
    sumAmountLabel->adjustSize();

    sumAmountLabel->move((ui->pieChartDonut->width()-sumAmountLabel->width())/2,
                        (ui->pieChartDonut->height()-sumAmountLabel->height())/2);
}

void MainWindow::updateList()
{
    ui->TransactionsList->clear();
    for (Transaction& transaction : transactions)
    {
        if (transaction.getDate() >= fromDateTransactions && transaction.getDate() <= toDateTransactions)
        {
            QListWidgetItem* item = new QListWidgetItem( ui->TransactionsList );
            TransactionsItem *transactionsItem = new TransactionsItem(transaction);

            item->setSizeHint(transactionsItem->sizeHint());
            ui->TransactionsList->setItemWidget(item, transactionsItem);
        }
    }
}


void MainWindow::on_addTransactionButton_clicked()
{
    int amount = ui->amountInputLine->text().toInt();
    QString description = ui->descriptionInputLine->text();
    int categoryId = ui->categoryComboBox->currentData().toInt();

    if(amount == 0 || description == "" || categoryId == 0){
        QMessageBox::about(this, "info", "Заповніть всі поля");
    }
    else
    {
        QSharedPointer<IJsonBuilder<Transaction>> builder (new TransactionJsonBuilder);
        QJsonDocument jsonDoc(builder->buildJson(Transaction (0, amount, description, categoryId)));
        QByteArray byteData = jsonDoc.toJson();

        QNetworkRequest request = QNetworkRequest(QUrl("http://localhost:5000/transaction"));
        request.setRawHeader("Content-Type", "application/json");
        QNetworkReply* postTranasactionReply = manager->post(request, byteData);
        connect(postTranasactionReply, &QNetworkReply::finished, this, &MainWindow::finishedPostTransactions);

        ui->amountInputLine->clear();
        ui->descriptionInputLine->clear();
    }
}


void MainWindow::on_incomeRadioButton_clicked()
{
    ui->categoryComboBox->clear();
    for (Category& cat: categories){
        if(cat.getType())
            ui->categoryComboBox->addItem(cat.getName(), cat.getId());
    }
}

void MainWindow::on_expenceRadioButton_clicked()
{
    ui->categoryComboBox->clear();
    for (Category& cat: categories){
        if(!cat.getType())
            ui->categoryComboBox->addItem(cat.getName(), cat.getId());
    }
}

void MainWindow::on_fromDateEdit_dateChanged(const QDate &date)
{
    fromDateTransactions = date;
    updateTransactions();
}

void MainWindow::on_toDateEdit_dateChanged(const QDate &date)
{
    toDateTransactions = date;
    updateTransactions();
}
