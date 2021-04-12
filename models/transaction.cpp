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


Transaction::Transaction(int id, int amount, QDate date, QString description, int categoryId)
{
    this->setId(id);
    this->setAmount(amount);
    this->setDate(date);
    this->setDescription(description);
    this->setCategoryId(categoryId);
}

int Transaction::getId()
{
    return this->id;
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

QString Transaction::setId(int id)
{
    // TODO: Int validation logic
    this->id = id;
    return "Success";
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

QString Transaction::setCategoryId(int categoryId)
{
    // TODO: Validation logic; It may be realized with the help of QIntValidator
    this->categoryId = categoryId;
    return "Success";
}

//QString Transaction::setCategory(Category category)
//{
//    // TODO: Validation logic
//    this->category = category;
//    return "Success";
//}
