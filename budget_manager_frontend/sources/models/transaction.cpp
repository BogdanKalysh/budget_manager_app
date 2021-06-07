#include "transaction.h"


Transaction::Transaction(const int id, const int amount, const QString &description, const int categoryId)
{
    this->id = id;
    this->amount = amount;
    this->description = description;
    this->categoryId = categoryId;
}

Transaction::Transaction(const int id, const int amount, const QDate &date, const QString &description,
                         const int categoryId):Transaction(id, amount, description, categoryId)
{
    this->date = date;
}

Transaction::Transaction(const int id, const int amount, const QDate &date, const QString &description, const int categoryId,
                         const QString &categoryName, const QColor &color, const QString &type):Transaction(id, amount, date, description, categoryId)
{
    this->categoryName = categoryName;
    this->color = color;
    this->type = type;
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

int Transaction::getCategoryId() const
{
    return this->categoryId;
}

QString Transaction::getCategoryName() const
{
    return this->categoryName;
}

QColor Transaction::getColor() const
{
    return this->color;
}

QString Transaction::getType() const
{
    return this->type;
}

void Transaction::setId(const int id)
{
    this->id = id;
}

void Transaction::setAmount(const int amount)
{
    this->amount = amount;
}

void Transaction::setDate(const QDate &date)
{
    this->date = date;
}

void Transaction::setDescription(const QString &description)
{
    this->description = description;
}

void Transaction::setCategoryId(const int categoryId)
{
    this->categoryId = categoryId;
}

void Transaction::setCategoryName(const QString &categoryName)
{
    this->categoryName = categoryName;
}

void Transaction::setColor(const QColor &color)
{
    this->color = color;
}

void Transaction::setType(const QString &type)
{
    this->type = type;
}
