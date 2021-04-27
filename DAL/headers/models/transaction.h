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

    QString setId(int id);
    QString setAmount(int amount);
    QString setDate(QDate date);
    QString setDescription(QString description);
    QString setCategoryId(int categoryId);
};

#endif // TRANSACTION_H
