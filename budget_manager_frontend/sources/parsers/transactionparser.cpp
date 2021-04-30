#include "transactionparser.h"
#include "constants.h"

Transaction TransactionParser::parse(QJsonObject json)
{
    int id = json.value(jsonbuilder::ID).toInt();
    int amount = json.value(jsonbuilder::AMOUNT).toInt();
    QDate date = json.value(jsonbuilder::DATE).toVariant().toDate();
    QString description = json.value(jsonbuilder::DESCRIPTION).toString();

    int categoryId = json.value(jsonbuilder::CATEGORYID).toInt();
    QString categoryName = json.value(jsonbuilder::CATEGORYNAME).toString();
    QColor color(json.value(jsonbuilder::COLOR).toString());

    return Transaction(id, amount, date, description, categoryId, categoryName, color);
}



QVector<Transaction> TransactionParser::parseVector(QJsonArray jsonArray)
{
    QVector<Transaction> transactions;
    for (const QJsonValue& json: jsonArray)
        transactions.append(this->parse(json.toObject()));

    return transactions;
}
