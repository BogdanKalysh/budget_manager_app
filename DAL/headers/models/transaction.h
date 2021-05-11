#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QString>
#include <QColor>
#include "category.h"

class Transaction
{
    int id;
    int amount;
    QDate date;
    QString description;
    int categoryId;

    QString categoryName;
    QColor color;
    QString type;

public:

    Transaction(const int id, const int amount, const QDate &date, const QString &description, const int categoryId);
    Transaction(const int id, const int amount, const QDate &date, const QString &description, const int categoryId,  QString categoryName, QColor color, QString type);

    int getId() const;
    int getAmount() const;
    int getCategoryId() const;
    QDate getDate() const;
    QString getDescription() const;
    QString getCategoryName();
    QColor getColor();
    QString getType();

    QString setId(const int id);
    QString setAmount(const int amount);
    QString setDate(const QDate &date);
    QString setDescription(const QString &description);
    QString setCategoryId(const int categoryId);
    QString setCategoryName(const QString &categoryName);
    QString setColor(const QColor &color);
    QString setType(const QString type);
};

#endif // TRANSACTION_H
