#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "categoryparser.h"
#include "transactionparser.h"
#include "transactionJsonBuilder.h"
#include "TransactionsListItem.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

void MainWindow::updateList()
{
    QVector<Transaction> test_transactions = {{1,1,"Name1",1},{2,2,"Name2",2},{3,3,"Name3",3},{4,4,"Name1",4},{5,5,"Name2",5},{5,5,"Name3",5}};
    ui->TransactionsList->clear();
    test_transactions[0].setCategoryName("Go to shop");
    test_transactions[1].setCategoryName("Pay for internet");
    test_transactions[2].setCategoryName("Buy juice");
    test_transactions[3].setCategoryName("Go to shop enother time");
    test_transactions[4].setCategoryName("Pay for internet another time");
    test_transactions[5].setCategoryName("Buy juice and be happy");
    test_transactions[0].setAmount(123);
    test_transactions[1].setAmount(34);
    test_transactions[2].setAmount(12);
    test_transactions[3].setAmount(123);
    test_transactions[4].setAmount(34);
    test_transactions[5].setAmount(12);
    test_transactions[0].setColor("#FFCC08");
    test_transactions[1].setColor("#FFFFFF");
    test_transactions[2].setColor("#000000");
    test_transactions[3].setColor("#FF0FF0");
    test_transactions[4].setColor("#FF1235");
    test_transactions[5].setColor("#002133");
    test_transactions[0].setType("expence");
    test_transactions[1].setType("expence");
    test_transactions[2].setType("income");
    test_transactions[3].setType("income");
    test_transactions[4].setType("expence");
    test_transactions[5].setType("income");
    test_transactions[0].setDate(QDate(2001, 10, 11));
    test_transactions[1].setDate(QDate(2002, 10, 11));
    test_transactions[2].setDate(QDate(2003, 10, 11));
    test_transactions[3].setDate(QDate(2004, 10, 11));
    test_transactions[4].setDate(QDate(2005, 10, 11));
    test_transactions[5].setDate(QDate(2005, 10, 11));

    for (Transaction transaction : test_transactions)
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

MainWindow::MainWindow(User user, QSharedPointer<QNetworkAccessManager> manager,  QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->user = user;
    this->manager = manager;

    piechart = ui->pieChartFrame->findChild<Piechart*>("donutPiechart");
    piechart->installEventFilter(this);

    series = new PieSeries();

    piechart->setSeries(series);
    settingPiechart();

    ui->userName->setText(user.getName());

    QPixmap settingsPixMap(":/new/img/settings_icon.png");
    QPixmap userPixMap(":/new/img/user_icon.png");
    int w(40), h(40);
    ui->settingsIcon->setPixmap(settingsPixMap.scaled(w, h, Qt::KeepAspectRatio));
    ui->userIcon->setPixmap(userPixMap.scaled(w, h, Qt::KeepAspectRatio));

    ui->amountInputLine->setValidator(new QIntValidator(0, 10000000, this));

    QString getCategoriesQuery = "http://127.0.0.1:5000/rating/getcategories?u_email=" + user.getEmail();
    QNetworkReply *categoriesReply = manager->get(QNetworkRequest(QUrl(getCategoriesQuery)));
    connect(categoriesReply, &QNetworkReply::readyRead, this, &MainWindow::readCategories);

    QString getTransactionsQuery = "http://127.0.0.1:5000/rating/gettransactions?u_email=" + user.getEmail() + "&lim=10";
    QNetworkReply *transactionsReply = manager->get(QNetworkRequest(QUrl(getTransactionsQuery)));
    connect(transactionsReply, &QNetworkReply::readyRead, this, &MainWindow::readTransactions);

    fromDateTransactions.setDate(0001,1,1);
    toDateTransactions.setDate(9999,12,31);

    updateList();
    updatePiechart();
}

MainWindow::~MainWindow()
{
    delete piechart;
    delete series;
    delete ui;
}

void MainWindow::settingPiechart()
{
    QFont font;
    font.setStyleHint(QFont::Times, QFont::PreferAntialias);

    series->setCentralTitleFont(font);
    series->setHoleSize(0.8);
    series->setHoleColor(QColor("#0a5074"));
}

qreal MainWindow::getCategoryTotalSum(QString categoryName)
{
    qreal totalsum = 0;

    for(Transaction & transac:transactions){
        if(transac.getCategoryName()==categoryName)
            totalsum+= transac.getAmount();
    }

    return totalsum;
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
        QMessageBox::about(this, "info", "Error: "+error);
    }
    postTranasactionReply->close();
    postTranasactionReply->deleteLater();
}

void MainWindow::updatePiechart()
{
    series->clear();

    for(Category& cat: categories){
        series->append(getCategoryTotalSum(cat.getName()),cat.getName(),cat.getColor());
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

        QNetworkRequest request = QNetworkRequest(QUrl("http://127.0.0.1:5000/rating/posttransaction"));
        request.setRawHeader("Content-Type", "application/json");
        QNetworkReply* postTranasactionReply = manager->post(request, byteData);
        connect(postTranasactionReply, &QNetworkReply::finished, this, &MainWindow::finishedPostTransactions);

        ui->amountInputLine->clear();
        ui->descriptionInputLine->clear();
    }
    updatePiechart();
}

void MainWindow::on_incomeRadioButton_clicked()
{
    ui->categoryComboBox->clear();
    for (Category& cat: categories){
        if(cat.getType())
            ui->categoryComboBox->addItem(cat.getName(), cat.getId());
    }
    updatePiechart();
}

void MainWindow::on_expenceRadioButton_clicked()
{
    ui->categoryComboBox->clear();
    for (Category& cat: categories){
        if(!cat.getType())
            ui->categoryComboBox->addItem(cat.getName(), cat.getId());
    }
    updatePiechart();
}

void MainWindow::on_fromDateEdit_dateChanged(const QDate &date)
{
    fromDateTransactions = date;
    updateList();
}

void MainWindow::on_toDateEdit_dateChanged(const QDate &date)
{
    toDateTransactions = date;
    updateList();
}
