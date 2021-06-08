#ifndef TESTUSERJSONBUILDER_H
#define TESTUSERJSONBUILDER_H

#include "userjsonbuilder.h"
#include <QTest>

class TestUserJsonBulder: public QObject
{
    Q_OBJECT
private slots:
    void testBuildJson();

private:
    UserJsonBuilder userJsonBuilder;
};

#endif // TESTUSERJSONBUILDER_H
