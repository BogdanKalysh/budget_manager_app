#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QString>
#include "category.h"

class Transaction
{
    int id;
    int amount;
    QDate date;
    QString description;
    int categoryId;
public:

    Transaction(int id, int amount, QDate date, QString description, int categoryId);

    int getId();
    int getAmount();
    int getCategoryId();
    QDate getDate();
    QString getDescription();

    void setId(int id);
    void setAmount(int amount);
    void setDate(QDate date);
    void setDescription(QString description);
    void setCategoryId(int categoryId);
};

#endif // TRANSACTION_H
