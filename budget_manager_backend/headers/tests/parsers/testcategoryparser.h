#ifndef TESTCATEGORYPARSER_H
#define TESTCATEGORYPARSER_H
#include "categoryparser.h"
#include <QTest>
class TestCategoryParser: public QObject
{
    Q_OBJECT
private slots:
    void parseCategory();
    void parseCategoryArray();

private:
    CategoryParser categoryParser;
};

#endif // TESTCATEGORYPARSER_H
