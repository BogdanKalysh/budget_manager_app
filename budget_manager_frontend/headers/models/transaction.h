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

    QString categoryName;
    QColor color;

public:

    Transaction(int id, int amount, QString description, int categoryId); //creating new
    Transaction(int id, int amount, QDate date, QString description, int categoryId); //updating old
    Transaction(int id, int amount, QDate date, QString description, int categoryId, QString categoryName, QColor color); //getting from db

    int getId();
    int getAmount();
    int getCategoryId();
    QDate getDate();
    QString getDescription();
    QString getCategoryName();
    QColor getColor();

    void setId(int id);
    void setAmount(int amount);
    void setDate(QDate date);
    void setDescription(QString description);
    void setCategoryId(int categoryId);
    void setCategoryName(QString categoryName);
    void setColor(QColor color);
};

#endif // TRANSACTION_H
