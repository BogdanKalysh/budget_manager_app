#include "transactionparser.h"
#include "categoryparser.h"
#include "constants.h"

template<typename T>
Transaction TransactionParser<T>::parse(QJsonObject json)
{
    int id = json.value(parser::ID).toInt();
    int amount = json.value(parser::AMOUNT).toInt();
    QDate date = json.value(parser::DATE).toVariant().toDate();
    QString description = json.value(parser::DESCRIPTION).toString();
    int categoryId = json.value(parser::CATEGORY_ID).toInt();
//    CategoryParcer<Category> parcer;
//    Category category = parcer.parce(json.value("category").toObject());

    return Transaction(id, amount, date, description, categoryId);
}

template<typename T>
QVector<Transaction> TransactionParser<T>::parseVector(QJsonArray jsonArray)
{
    QVector<Transaction> transactions;
    foreach(QJsonValue json, jsonArray)
        transactions.append(this->parse(json));

    return transactions;
}
