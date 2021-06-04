#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDate>
#include <QColor>
#include <constants.h>

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
    Transaction(const int id, const int amount, const QDate &date, const QString &description, const int categoryId,  const QString &categoryName, const QColor &color, const QString &type);

    int getId() const;
    int getAmount() const;
    int getCategoryId() const;
    QDate getDate() const;
    QString getDescription() const;
    QString getCategoryName() const;
    QColor getColor() const;
    QString getType() const;

    void setId(const int id);
    void setAmount(const int amount);
    void setDate(const QDate &date);
    void setDescription(const QString &description);
    void setCategoryId(const int categoryId);
    void setCategoryName(const QString &categoryName);
    void setColor(const QColor &color);
    void setType(const QString &type);
};

#endif // TRANSACTION_H
