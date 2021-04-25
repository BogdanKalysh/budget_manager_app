#include "transactionparser.h"
#include "constants.h"

Transaction TransactionParser::parse(QJsonObject json)
{
    int id = json.value(jsonbuilder::ID).toInt();
    int amount = json.value(jsonbuilder::AMOUNT).toInt();
    QDate date = json.value(jsonbuilder::DATE).toVariant().toDate();
    QString description = json.value(jsonbuilder::DESCRIPTION).toString();

    QString categoryName = json.value(jsonbuilder::CATEGORYNAME).toString();
    QJsonArray jRGB = json.value(jsonbuilder::COLOR).toArray();
    QColor color(jRGB[0].toInt(), jRGB[1].toInt(), jRGB[2].toInt());


    return Transaction(id, amount, date, description, categoryName, color);
}



QVector<Transaction> TransactionParser::parseVector(QJsonArray jsonArray)
{
    QVector<Transaction> transactions;
    foreach(QJsonValue json, jsonArray)
        transactions.append(this->parse(json.toObject()));

    return transactions;
}
