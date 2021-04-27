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

    Transaction(const int id, const int amount, const QDate date, const QString description, const int categoryId);

    int getId() const;
    int getAmount() const;
    int getCategoryId() const;
    QDate getDate() const;
    QString getDescription() const;

    QString setId(const int id);
    QString setAmount(const int amount);
    QString setDate(const QDate date);
    QString setDescription(const QString description);
    QString setCategoryId(const int categoryId);
};

#endif // TRANSACTION_H
