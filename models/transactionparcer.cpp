#include "transactionparcer.h"

template<typename T>
Transaction TransactionParcer<T>::parce(QJsonObject json)
{
    int amount = json.value("amount").toInt();
    QDate date = json.value("date").toVariant().toDate();
    QString description = json.value("description").toString();

    return Transaction(amount, date, description);
}
