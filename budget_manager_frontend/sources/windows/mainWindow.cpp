#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "categoryparser.h"
#include "transactionparser.h"
#include "transactionJsonBuilder.h"
#include "TransactionsListItem.h"
#include "legendlistitem.h"
#include "constants.h"
#include "addcategorydialog.h"
#include "usersettingsdialog.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

using namespace messagebox;

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

    sumAmountLabel = new QLabel("0", chartView);
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
    QString getTransactionsQuery = urls::TRANSACTIONURL + "?" + models::USER_ID + "=" +
            QString::number(user.getId()) + "&" + models::START_DATE + "=" + fromDateTransactions.toString("yyyy-MM-dd") +
            "&" + models::END_DATE + "=" + toDateTransactions.toString("yyyy-MM-dd");
    QNetworkReply *transactionsReply = manager->get(QNetworkRequest(QUrl(getTransactionsQuery)));

    connect(transactionsReply, &QNetworkReply::readyRead, this, &MainWindow::readTransactions);
}

void MainWindow::updateCategories()
{
    QString getCategoriesQuery = urls::CATEGORYURL + "?" + models::USER_ID + "=" + QString::number(user.getId());
    QNetworkReply *categoriesReply = manager->get(QNetworkRequest(QUrl(getCategoriesQuery)));

    connect(categoriesReply, &QNetworkReply::readyRead, this, &MainWindow::readCategories);
}


void MainWindow::readCategories()
{
    QNetworkReply *categoriesReply = qobject_cast<QNetworkReply*>(sender());

    if (categoriesReply) {
        QString categoriesStr = categoriesReply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(categoriesStr.toUtf8());
        QJsonArray json_array = jsonResponse.array();

        QSharedPointer<IJsonParser<Category>> parser (new CategoryParser);
        categories = parser->parseVector(json_array);
    }

    ui->categoryComboBox->clear();

    for (Category &category: categories) {
        if (category.getType() == models::INCOME && ui->incomeRadioButton->isChecked()) {
            ui->categoryComboBox->addItem(category.getName(), category.getId());
        } else if (category.getType() == models::EXPENSE && ui->expenceRadioButton->isChecked()) {
            ui->categoryComboBox->addItem(category.getName(), category.getId());
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

    if (transactionsReply) {
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

    if (postTranasactionReply->error() != QNetworkReply::NoError) {
        QString error = postTranasactionReply->errorString();
        qDebug() << error;
        QMessageBox::about(this, "info", "Error: " + error);
    } else {
        updateTransactions();
    }

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

    QPixmap userPixMap(resourcepath::USERICONPATH);
    int w(40), h(40);
    ui->userIcon->setPixmap(userPixMap.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->amountInputLine->setValidator(new QIntValidator(0, 1000000000, this));

    QDate dateNow(QDate::currentDate().year(), QDate::currentDate().month(), QDate::currentDate().day());
    QDate dateMountAgo = dateNow.addMonths(-1);

    fromDateTransactions.setDate(dateMountAgo.year(), dateMountAgo.month(), dateMountAgo.day());
    toDateTransactions.setDate(dateNow.year(), dateNow.month(), dateNow.day());

    ui->fromDateEdit->setDate(fromDateTransactions);
    ui->toDateEdit->setDate(toDateTransactions);

    connect(ui->amountInputLine, &QLineEdit::textChanged, [=]{ style()->polish(ui->amountInputLine); });
    connect(ui->descriptionInputLine, &QLineEdit::textChanged, [=]{ style()->polish(ui->descriptionInputLine); });

    updateTransactions();
    updateCategories();
}


qreal MainWindow::getCategoryTotalSum(QString categoryName, QString type)
{
    qreal totalsum = 0;

    for (Transaction &transac : transactions) {
        if (transac.getCategoryName() == categoryName && transac.getType() == type)
            totalsum += transac.getAmount();
    }

    return totalsum;
}

void MainWindow::updatePiechart()
{
    int amountSum(0);
    series->clear();

    if (transactions.size() != 0) {
        for (Category &category : categories) {
            if ((category.getType() == models::INCOME) == ui->incomesLegendRadioButton->isChecked()) {
                amountSum += getCategoryTotalSum(category.getName(), category.getType());
                QPieSlice *slice = series->append(category.getName(), getCategoryTotalSum(category.getName(),category.getType()));
                slice->setBorderWidth(0);
                slice->setPen(Qt::NoPen);
                slice->setColor(QColor(category.getColor()));
            }
        }
    }

    if (amountSum == 0) {
        QPieSlice *slice = series->append("0", 1);
        slice->setBorderWidth(0);
        slice->setPen(Qt::NoPen);
        slice->setColor(QColor(colors::PIECHARTCOLOR));
    }

    if (ui->expencesLegendRadioButton->isChecked() && amountSum != 0)
        sumAmountLabel->setText("-" + QString::number(amountSum) + " ₴");
    else
        sumAmountLabel->setText(QString::number(amountSum) + " ₴");

    sumAmountLabel->adjustSize();

    sumAmountLabel->move((ui->pieChartDonut->width()-sumAmountLabel->width())/2,
                        (ui->pieChartDonut->height()-sumAmountLabel->height())/2);

    updateLegend();
}

void MainWindow::updateList()
{
    ui->TransactionsList->clear();

    for (Transaction &transaction : transactions) {
        QListWidgetItem *item = new QListWidgetItem( ui->TransactionsList );
        TransactionsItem *transactionsItem = new TransactionsItem(transaction, manager);

        item->setSizeHint(QSize(0, 55));
        ui->TransactionsList->setItemWidget(item, transactionsItem);

        connect(transactionsItem, &TransactionsItem::transactionDeleted, this, &MainWindow::updateTransactions);
    }
}

void MainWindow::updateLegend()
{
    ui->legendList->clear();

    for (Category &category : categories) {
        if ((category.getType() == models::INCOME) == ui->incomesLegendRadioButton->isChecked()) {
            QListWidgetItem* item = new QListWidgetItem( ui->legendList );
            LegendListItem *categoryItem = new LegendListItem(category);

            item->setSizeHint(QSize(1,37));
            ui->legendList->setItemWidget(item, categoryItem);
        }
    }
}

void MainWindow::on_addTransactionButton_clicked()
{
    int amount = ui->amountInputLine->text().toInt();
    QString description = ui->descriptionInputLine->text();
    int categoryId = ui->categoryComboBox->currentData().toInt();

    if (amount == 0 || description == "" || categoryId == 0) {
        QMessageBox::about(this, INFO, FILLIN);
    } else {
        QSharedPointer<IJsonBuilder<Transaction>> builder (new TransactionJsonBuilder);
        QJsonDocument jsonDoc(builder->buildJson(Transaction (0, amount, description, categoryId)));
        QByteArray byteData = jsonDoc.toJson();

        QNetworkRequest request = QNetworkRequest(QUrl(urls::TRANSACTIONURL));
        request.setRawHeader(urls::CONTENTTYPE.toUtf8(), urls::APPLICATIONJSON.toUtf8());
        QNetworkReply* postTranasactionReply = manager->post(request, byteData);
        connect(postTranasactionReply, &QNetworkReply::finished, this, &MainWindow::finishedPostTransactions);

        ui->amountInputLine->clear();
        ui->descriptionInputLine->clear();
    }
}

void MainWindow::on_incomeRadioButton_clicked()
{
    ui->categoryComboBox->clear();

    for (Category& category: categories) {
        if (category.getType() == models::INCOME)
            ui->categoryComboBox->addItem(category.getName(), category.getId());
    }
}

void MainWindow::on_expenceRadioButton_clicked()
{
    ui->categoryComboBox->clear();

    for (Category& category: categories) {
        if (category.getType() == models::EXPENSE)
            ui->categoryComboBox->addItem(category.getName(), category.getId());
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

void MainWindow::on_addCategoryButton_clicked()
{
    AddCategoryDialog categoryDialog(user.getId(), ui->incomeRadioButton->isChecked() ? models::INCOME : models::EXPENSE, manager);
    categoryDialog.setModal(true);
    categoryDialog.exec();
    updateCategories();
}

void MainWindow::on_incomesLegendRadioButton_clicked()
{
    updatePiechart();
    updateLegend();
}

void MainWindow::on_expencesLegendRadioButton_clicked()
{
    updatePiechart();
    updateLegend();
}

void MainWindow::on_userName_clicked()
{
        UserSettingsDialog usersettings(user, manager);
        usersettings.exec();

        user = usersettings.getUser();

        ui->userName->setText(user.getName());

        updateCategories();
        updateTransactions();
}
