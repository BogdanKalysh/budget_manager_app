#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QtTest/QtTest>
#include "mainWindow.h"
class TestMainWindow :public QObject
{
    Q_OBJECT
private slots:
    void init();
    void testConstructor();
    void testGetCategoryTotalSum();
    void testReadTransactions();
    void testReadCategories();
    void testUpdateLegend();
    void testUpdateList();
    void testUpdateCategories();
    void testUpdateTransactions();
    void testConfigWindowItems();
    void testAddTransactions();

private:
    MainWindow _mainwindow;
    const int TEST_DATA_OBJECT_AMOUNT = 4;
};

#endif // TESTMAINWINDOW_H
