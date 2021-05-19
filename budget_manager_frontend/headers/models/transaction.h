#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include <QString>
#include <QColor>

class Transaction
{
    int id;
    int amount;
    QDate date;
    QString description;
    int categoryId;
    QString type;

    QString categoryName;
    QColor color;

public:

    Transaction(int id, int amount, QString description, int categoryId); //creating new
    Transaction(int id, int amount, QDate date, QString description, int categoryId); //updating old
    Transaction(int id, int amount, QDate date, QString description, int categoryId, QString categoryName, QColor color, QString type); //getting from db

    int getId();
    int getAmount();
    int getCategoryId();
    QDate getDate();
    QString getDescription();
    QString getCategoryName();
    QColor getColor();
    QString getType();

    void setId(int id);
    void setAmount(int amount);
    void setDate(QDate date);
    void setDescription(QString description);
    void setCategoryId(int categoryId);
    void setCategoryName(QString categoryName);
    void setColor(QColor color);
    void setType(QString type);
};

#endif // TRANSACTION_H
