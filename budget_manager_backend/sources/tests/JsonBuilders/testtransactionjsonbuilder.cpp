#include "testtransactionjsonbuilder.h"
#include "constants.h"
using namespace models;

#include <QJsonDocument>

void TestTransactionJsonBulder::testBuildJson() {
    Transaction transacion(1, 120, QDate(2020,10,20), "abc", 3);

    QJsonObject result
    {
        {ID, 1},
        {AMOUNT, 120},
        {DATE, QJsonValue::fromVariant(QDate(2020,10,20))},
        {DESCRIPTION,"abc"},
        {CATEGORY_ID, 3}
    };
    QJsonObject built = transactionJsonBuilder.buildJson(transacion);
    QJsonDocument builtdoc(built);
    QJsonDocument resultdoc(result);

    QCOMPARE(builtdoc.object()[ID], resultdoc.object()[ID]);
    QCOMPARE(builtdoc.object()[AMOUNT], resultdoc.object()[AMOUNT]);
    QCOMPARE(builtdoc.object()[DATE].toString(), resultdoc.object()[DATE].toString());
    QCOMPARE(builtdoc.object()[DESCRIPTION], resultdoc.object()[DESCRIPTION]);
    QCOMPARE(builtdoc.object()[CATEGORY_ID], resultdoc.object()[CATEGORY_ID]);

}
