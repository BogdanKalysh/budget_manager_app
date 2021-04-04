#include "transaction.h"

Transaction::Transaction(int amount, QDate date, QString description, Category category)
{
    this->setAmount(amount);
    this->setDate(date);
    this->setDescription(description);
    this->setCategory(category);
}

int Transaction::getAmount()
{
    return this->amount;
}

QDate Transaction::getDate()
{
    return this->date;
}

QString Transaction::getDescription()
{
    return this->description;
}

QString Transaction::setAmount(int amount)
{
    // TODO: Validation logic; It may be realized with the help of QIntValidator
    this->amount = amount;
    return "Success";
}

QString Transaction::setDate(QDate date)
{
    // TODO: Validation logic; It may be realized with the help of QDate::isValid
    this->date = date;
    return "Success";
}

QString Transaction::setDescription(QString description)
{
    // TODO: Validation logic
    this->description = description;
    return "Success";
}

QString Transaction::setCategory(Category category)
{
    // TODO: Validation logic
    this->category = category;
    return "Success";
}
