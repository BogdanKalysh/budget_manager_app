#include "mainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(User user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->user = user;

    //filling combo box(temporary)
    ui->cetegoryComboBox->addItem("Прибуток 1");
    ui->cetegoryComboBox->addItem("Прибуток 2");
    ui->cetegoryComboBox->addItem("Прибуток 3");
    ui->cetegoryComboBox->addItem("Прибуток 4");
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete manager;
}







void MainWindow::on_addTransactionButton_clicked()
{
    int amount = ui->amountInputLine->text().toInt();
    QString description = ui->descriptionInputLine->text();
    QString category = ui->cetegoryComboBox->currentText();

    qDebug() << amount << " " << description << " " << category << "\n";
}






void MainWindow::on_incomeRadioButton_clicked()
{
    ui->cetegoryComboBox->clear();

    ui->cetegoryComboBox->addItem("Прибуток 1");
    ui->cetegoryComboBox->addItem("Прибуток 2");
    ui->cetegoryComboBox->addItem("Прибуток 3");
    ui->cetegoryComboBox->addItem("Прибуток 4");
}

void MainWindow::on_expenceRadioButton_clicked()
{
    ui->cetegoryComboBox->clear();

    ui->cetegoryComboBox->addItem("Витрата 1");
    ui->cetegoryComboBox->addItem("Витрата 2");
    ui->cetegoryComboBox->addItem("Витрата 3");
    ui->cetegoryComboBox->addItem("Витрата 4");
}
