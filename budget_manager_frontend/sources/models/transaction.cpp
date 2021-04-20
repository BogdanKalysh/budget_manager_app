#include "transaction.h"


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


void Transaction::setId(int id)
{
    this->id = id;
}

void Transaction::setAmount(int amount)
{
    this->amount = amount;
}

void Transaction::setDate(QDate date)
{
    this->date = date;
}

void Transaction::setDescription(QString description)
{
    this->description = description;
}

void Transaction::setCategoryId(int categoryId)
{
    this->categoryId = categoryId;
}
