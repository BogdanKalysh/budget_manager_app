#ifndef TESTCATEGORYJSONBUILDER_H
#define TESTCATEGORYJSONBUILDER_H

#include "categoryjsonbuilder.h"
#include <QTest>

class TestCategoryJsonBulder: public QObject
{
    Q_OBJECT
private slots:
    void testBuildJson();

private:
    CategoryJsonBuilder categoryJsonBuilder;
};

#endif // TESTCATEGORYJSONBUILDER_H
