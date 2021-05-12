#include "transaction.h"




Transaction::Transaction(const int id, const int amount, const QDate &date, const QString &description, const int categoryId)
{
    this->setId(id);
    this->setAmount(amount);
    this->setDate(date);
    this->setDescription(description);
    this->setCategoryId(categoryId);
}

Transaction::Transaction(const int id, const int amount, const QDate &date, const QString &description, const int categoryId, QString categoryName, QColor color, QString type)
    :Transaction(id, amount, date, description, categoryId)
{
    this->setCategoryName(categoryName);
    this->setColor(color);
    this->setType(type);
}


int Transaction::getId() const
{
    return this->id;
}

int Transaction::getAmount() const
{
    return this->amount;
}

int Transaction::getCategoryId() const
{
    return this->categoryId;
}

QDate Transaction::getDate() const
{
    return this->date;
}

QString Transaction::getDescription() const
{
    return this->description;
}

QString Transaction::getCategoryName()
{
    return this->categoryName;
}

QColor Transaction::getColor()
{
    return this->color;
}

QString Transaction::getType()
{
    return this->type;
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

QString Transaction::setCategoryName(const QString &categoryName)
{
    this->categoryName = categoryName;
    return "Success";
}

QString Transaction::setColor(const QColor &color)
{
    this->color = color;
    return "Success";
}

QString Transaction::setType(const QString type)
{
    this->type = type;
    return "Success";
}
