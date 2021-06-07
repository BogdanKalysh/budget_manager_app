#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "category.h"
#include "transaction.h"
#include <QNetworkAccessManager>
#include <QSharedPointer>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const User &user, const QSharedPointer<QNetworkAccessManager> &manager,  QWidget *parent=nullptr);
    ~MainWindow();

protected:
    void configWindowItems();
    qreal getCategoryTotalSum(const QString &categoryName, const QString &type);
    void setUpUrls();

public slots:
    void updateTransactions();
    void updateCategories();
    void readCategories();
    void readTransactions();
    void finishedPostTransactions();
    void updatePiechart();
    void updateList();
    void updateLegend();

private slots:
    void on_addTransactionButton_clicked();
    void on_incomeRadioButton_clicked();
    void on_expenceRadioButton_clicked();
    void on_fromDateEdit_dateChanged(const QDate &date);
    void on_toDateEdit_dateChanged(const QDate &date);
    void resizeEvent(QResizeEvent *event);
    void on_addCategoryButton_clicked();
    void on_incomesLegendRadioButton_clicked();
    void on_expencesLegendRadioButton_clicked();
    void on_userName_clicked();

private:
    Ui::MainWindow *ui;
    QPieSeries *series;
    QChartView *chartView;
    User user;
    QVector<Category> categories;
    QVector<Transaction> transactions;
    QSharedPointer<QNetworkAccessManager> manager;
    QDate fromDateTransactions;
    QDate toDateTransactions;
    QLabel *sumAmountLabel;
};
#endif // MAINWINDOW_H
