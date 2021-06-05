#include "category.h"

using namespace models;

Category::Category()
{
    // Attention! Not valid data!
    this->id = -1;
    this->name = QString();
    this->type = INCOME;
    this->color = QColor();
}

Category::Category(const int id, const QString &name, const QString &type, const QColor &color, const int userId)
{
    this->id = id;
    this->name = name;
    this->type = type;
    this->color = color;
    this->userId = userId;
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
