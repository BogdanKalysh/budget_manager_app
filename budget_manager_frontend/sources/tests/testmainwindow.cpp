#include "testmainwindow.h"
#include "user.h"
#include "ui_mainwindow.h"
#include<vector>
void TestMainWindow::init()
{

}

void TestMainWindow::testConstructor()
{
    User user = User(1,"bob","bob@gmail.com","passpass");
    QSharedPointer<QNetworkAccessManager> manager{new QNetworkAccessManager} ;

    MainWindow mainwindow = MainWindow(user,manager);

    QVERIFY2(dynamic_cast<Ui::MainWindow*>(mainwindow.ui)->userName->text()==QString("bob"),"bad name");

    QVERIFY2(mainwindow.series!=nullptr,"series null pointer");
    QVERIFY2(mainwindow.chartView!=nullptr,"chart null pointer");

}

void TestMainWindow::testGetCategoryTotalSum()
{
    _mainwindow.updateCategories();
    _mainwindow.updateTransactions();


    for (Category &category : _mainwindow.categories){
        if(category.getId()!=1){
            QCOMPARE(_mainwindow.getCategoryTotalSum(category.getName(),category.getType()),0);
        }
        else {
            QCOMPARE(_mainwindow.getCategoryTotalSum(category.getName(),category.getType()),1000);
        }
    }

}

void TestMainWindow::testReadTransactions()
{
    _mainwindow.readTransactions();


    QVERIFY2(_mainwindow.transactions.size()==TEST_DATA_OBJECT_AMOUNT,"not all transactions");
    QVERIFY2(_mainwindow.series->children().size()!=TEST_DATA_OBJECT_AMOUNT,"not all pieslice");



}

void TestMainWindow::testReadCategories()
{
    _mainwindow.readCategories();

    QVERIFY2(_mainwindow.categories.size()==TEST_DATA_OBJECT_AMOUNT,"not all categories");


}

void TestMainWindow::testUpdateLegend()
{
    _mainwindow.readCategories();
}

void TestMainWindow::testUpdateList()
{

}

void TestMainWindow::testUpdateCategories()
{
     _mainwindow.updateCategories();

     QVERIFY2(_mainwindow.categories.size()==TEST_DATA_OBJECT_AMOUNT,"not all categories");
}

void TestMainWindow::testUpdateTransactions()
{
     _mainwindow.updateTransactions();

    QVERIFY2(_mainwindow.transactions.size()==TEST_DATA_OBJECT_AMOUNT,"not all transactions");
    QVERIFY2(_mainwindow.series->children().size()!=TEST_DATA_OBJECT_AMOUNT,"not all pieslice");
}

void TestMainWindow::testConfigWindowItems()
{
    _mainwindow.configWindowItems();

    QVERIFY(_mainwindow.series->holeSize()==0.77);
    QVERIFY(_mainwindow.series->pieSize()==1);


}

void TestMainWindow::testAddTransactions()
{
    QLineEdit *inputLine = &dynamic_cast<Ui::MainWindow*>(mainwindow.ui)->amountInputLine;

    QTest::keyClicks(inputLine, "new transaction");

    QCOMPARE(lineEdit.text(), QString("new transaction"));
}
