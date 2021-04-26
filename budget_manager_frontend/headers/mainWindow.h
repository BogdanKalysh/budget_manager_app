#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "category.h"
#include "transaction.h"
#include <QNetworkAccessManager>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(User user, QNetworkAccessManager* manager,  QWidget *parent=nullptr);
    ~MainWindow();

public slots:
    void readCategories();
    void readTransactions();
    void finishedPostTransactions();


private slots:
    void on_addTransactionButton_clicked();
    void on_incomeRadioButton_clicked();
    void on_expenceRadioButton_clicked();



private:
    Ui::MainWindow *ui;

    User user;
    QVector<Category> categories;
    QVector<Transaction> transactions;
    QNetworkAccessManager* manager;
};
#endif // MAINWINDOW_H
