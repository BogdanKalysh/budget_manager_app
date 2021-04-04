#include "transactionparcer.h"
#include "categoryparcer.h"


template<typename T>
Transaction TransactionParcer<T>::parce(QJsonObject json)
{
    int amount = json.value("amount").toInt();
    QDate date = json.value("date").toVariant().toDate();
    QString description = json.value("description").toString();

    CategoryParcer<Category> parcer;
    Category category = parcer.parce(json.value("category").toObject());

    return Transaction(amount, date, description, category);
}

template<typename T>
QVector<Transaction> TransactionParcer<T>::parceVector(QJsonArray jsonArray)
{
    QVector<Transaction> transactions;
    foreach(QJsonValue json, jsonArray)
        transactions.append(this->parce(json));

    return transactions;
}
