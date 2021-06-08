#include "testtransactionparser.h"
#include "constants.h"

using namespace models;


void TestTransactionParser::parseTransaction()
{
    QJsonObject correctJson
    {
        {ID, 1},
        {AMOUNT, 120},
        {DATE, QJsonValue::fromVariant(QDate(2020,10,20))},
        {DESCRIPTION,"abc"},
        {CATEGORY_ID, 3}
    };
    Transaction result(1, 120, QDate(2020,10,20), "abc", 3);
    Transaction parsed = transactionParser.parse(correctJson);

    QCOMPARE(result.getId(), parsed.getId());
    QCOMPARE(result.getAmount(), parsed.getAmount());
    QCOMPARE(result.getDate(), parsed.getDate());
    QCOMPARE(result.getDescription(), parsed.getDescription());
    QCOMPARE(result.getCategoryId(), parsed.getCategoryId());
}

void TestTransactionParser::parseTransactionArray()
{
    QVector<Transaction> correctTransactions = {{1, 120, QDate(2020,10,20), "abc", 3},
                                           {2, 140, QDate(2020,10,30), "cba", 2},
                                           {1, 120, QDate(2020,10,20), "abc", 3}};

    QJsonObject correctJson1 {{ID, 1}, {AMOUNT, 120}, {DATE, QJsonValue::fromVariant(QDate(2020,10,20))}, {DESCRIPTION,"abc"}, {CATEGORY_ID, 3}};
    QJsonObject correctJson2 {{ID, 2}, {AMOUNT, 140}, {DATE, QJsonValue::fromVariant(QDate(2020,10,30))}, {DESCRIPTION,"cba"}, {CATEGORY_ID, 2}};

    QJsonArray correctJsonArray = {
        correctJson1, correctJson2, correctJson1,
    };

    QVector<Transaction> parsedArray = transactionParser.parseVector(correctJsonArray);

    for(int i=0; i < correctTransactions.size(); i++) {
        QCOMPARE(correctTransactions[i].getId(), parsedArray[i].getId());
        QCOMPARE(correctTransactions[i].getAmount(), parsedArray[i].getAmount());
        QCOMPARE(correctTransactions[i].getDate(), parsedArray[i].getDate());
        QCOMPARE(correctTransactions[i].getDescription(), parsedArray[i].getDescription());
        QCOMPARE(correctTransactions[i].getCategoryId(), parsedArray[i].getCategoryId());
    }
}
