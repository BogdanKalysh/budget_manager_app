#include "transaction.h"

/*
Transaction::Transaction(int amount, QDate date, QString description, Category category)
{
    this->setAmount(amount);
    this->setDate(date);
    this->setDescription(description);
    this->setCategory(category);
}
*/


Transaction::Transaction(const int id, const int amount, const QDate &date, const QString &description, const int categoryId)
{
    this->setId(id);
    this->setAmount(amount);
    this->setDate(date);
    this->setDescription(description);
    this->setCategoryId(categoryId);
}

int Transaction::getId() const
{
    return this->id;
}

int Transaction::getAmount() const
{
    return this->amount;
}

QDate Transaction::getDate() const
{
    return this->date;
}

QString Transaction::getDescription() const
{
    return this->description;
}

QString Transaction::setId(const int id)
{
    // TODO: Int validation logic
    this->id = id;
    return "Success";
}

QString Transaction::setAmount(const int amount)
{
    // TODO: Validation logic; It may be realized with the help of QIntValidator
    this->amount = amount;
    return "Success";
}

QString Transaction::setDate(const QDate &date)
{
    // TODO: Validation logic; It may be realized with the help of QDate::isValid
    this->date = date;
    return "Success";
}

QString Transaction::setDescription(const QString &description)
{
    // TODO: Validation logic
    this->description = description;
    return "Success";
}

QString Transaction::setCategoryId(const int categoryId)
{
    // TODO: Validation logic; It may be realized with the help of QIntValidator
    this->categoryId = categoryId;
    return "Success";
}
