#include "transaction.h"


Transaction::Transaction(int id, int amount, QString description, int categoryId)
{
    this->id = id;
    this->amount = amount;
    this->description = description;
    this->categoryId = categoryId;
}

Transaction::Transaction(int id, int amount, QDate date, QString description, int categoryId):Transaction(id, amount, description, categoryId)
{
    this->date = date;
}

Transaction::Transaction(int id, int amount, QDate date, QString description, int categoryId, QString categoryName, QColor color):Transaction(id, amount, date, description, categoryId)
{
    this->categoryName = categoryName;
    this->color = color;
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

int Transaction::getCategoryId()
{
    return this->categoryId;
}

QString Transaction::getCategoryName()
{
    return this->categoryName;
}

QColor Transaction::getColor()
{
    return this->color;
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

void Transaction::setCategoryName(QString categoryName)
{
    this->categoryName = categoryName;
}

void Transaction::setColor(QColor color){
    this->color = color;
}
