#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDate>
#include <QString>

class Transaction
{
    int amount;
    QDate date;
    QString description;
    // TODO: add field "category"; but for now it is`t clear of what type it should be (Category or QString)
public:
    Transaction(int amount, QDate date, QString description);

    int getAmount();
    QDate getDate();
    QString getDescription();

    QString setAmount(int amount);
    QString setDate(QDate date);
    QString setDescription(QString description);
};

#endif // TRANSACTION_H
