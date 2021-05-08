#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "category.h"
#include "transaction.h"
#include <QDateEdit>
#include <QDateEdit>
#include <QListWidgetItem>
#include <QNetworkAccessManager>
#include <QSharedPointer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(User user, QSharedPointer<QNetworkAccessManager> manager,  QWidget *parent=nullptr);

    ~MainWindow();

public slots:
    void readCategories();
    void readTransactions();
    void finishedPostTransactions();
    void updateList();

private slots:
    void on_addTransactionButton_clicked();
    void on_incomeRadioButton_clicked();
    void on_expenceRadioButton_clicked();

    void on_fromDateEdit_dateChanged(const QDate &date);

    void on_toDateEdit_dateChanged(const QDate &date);

private:
    Ui::MainWindow *ui;
    User user;
    QVector<Category> categories;
    QVector<Transaction> transactions;
    QSharedPointer<QNetworkAccessManager> manager;
    QDate fromDateTransactions;
    QDate toDateTransactions;
};
#endif // MAINWINDOW_H
