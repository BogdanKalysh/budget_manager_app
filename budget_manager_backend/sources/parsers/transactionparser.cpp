#include "transactionparser.h"
#include "constants.h"

using namespace models;

Transaction TransactionParser::parse(const QJsonObject &json)
{
    int id = json.value(ID).toInt();
    int amount = json.value(AMOUNT).toInt();
    QDate date = json.value(DATE).toVariant().toDate();
    QString description = json.value(DESCRIPTION).toString();
    int categoryId = json.value(CATEGORY_ID).toInt();

    return Transaction(id, amount, date, description, categoryId);
}

QVector<Transaction> TransactionParser::parseVector(const QJsonArray &jsonArray)
{
    QVector<Transaction> transactions;

    for (auto json : jsonArray)
        transactions.append(this->parse(json.toObject()));

    return transactions;
}
