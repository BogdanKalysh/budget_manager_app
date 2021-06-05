#include "category.h"

Category::Category()
{
    // Attention! Not valid data!
    this->id = -1;
    this->name = QString();
    this->type = models::INCOME;
    this->color = QColor();
    this->userId = -1;
}

Category::Category(const int id, const QString &name, const QString &type, const QColor &color, const int userId)
{
    this->setId(id);
    this->setName(name);
    this->setType(type);
    this->setColor(color);
    this->setUserId(userId);
}

Category::Category(const Category &other)
{
    this->id = other.id;
    this->name = other.name;
    this->type = other.type;
    this->color = other.color;
}

int Category::getId() const
{
    return this->id;
}

int Category::getUserId() const
{
    return this->userId;
}

QString Category::getName() const
{
    return this->name;
}

QString Category::getType() const
{
    return this->type;
}

QColor Category::getColor() const
{
    return this->color;
}

void Category::setId(const int id)
{
    this->id = id;
}

void Category::setName(const QString &name)
{
    this->name = name;
}

void Category::setType(const QString &type)
{
    this->type = type;
}

void Category::setColor(const QColor &color)
{
    this->color = color;
}

void Category::setUserId(const int userId)
{
    this->userId = userId;
}
