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

Category::Category(int id, QString name, QString type, QColor color, int userId)
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


int Category::getId()
{
    return this->id;
}

int Category::getUserId()
{
    return this->userId;
}

QString Category::getName()
{
    return this->name;
}

QString Category::getType()
{
    return this->type;
}

QColor Category::getColor()
{
    return this->color;
}

void Category::setId(int id)
{
    this->id = id;
}

void Category::setName(QString name)
{
    this->name = name;
}

void Category::setType(QString type)
{
    this->type = type;
}

void Category::setColor(QColor color)
{
    this->color = color;
}

void Category::setUserId(int userId)
{
    this->userId = userId;
}
