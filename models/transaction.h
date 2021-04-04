#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QString>
#include "category.h"

class Transaction
{
    int amount;
    QDate date;
    QString description;
    Category category;

public:
    Transaction(int amount, QDate date, QString description, Category category);

    int getAmount();
    QDate getDate();
    QString getDescription();

    QString setAmount(int amount);
    QString setDate(QDate date);
    QString setDescription(QString description);
    QString setCategory(Category category);
};

#endif // TRANSACTION_H
