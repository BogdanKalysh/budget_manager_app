#include "transactionparser.h"
#include "constants.h"


Transaction TransactionParser::parse(const QJsonObject &json)
{
    int id = json.value(models::ID).toInt();
    int amount = json.value(models::AMOUNT).toInt();
    QDate date = json.value(models::DATE).toVariant().toDate();
    QString description = json.value(models::DESCRIPTION).toString();

    int categoryId = json.value(models::CATEGORY_ID).toInt();
    QString categoryName = json.value(models::CATEGORYNAME).toString();
    QColor color(json.value(models::COLOR).toString());
    QString type = json.value(models::TYPE).toString();

    return Transaction(id, amount, date, description, categoryId, categoryName, color, type);
}

QVector<Transaction> TransactionParser::parseVector(const QJsonArray &jsonArray)
{
    QVector<Transaction> transactions;
    for (const QJsonValue& json: jsonArray)
        transactions.append(this->parse(json.toObject()));

    return transactions;
}
