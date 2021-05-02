#include "category.h"

Category::Category()
{
    // Attention! Not valid data!
    this->id = -1;
    this->name = QString();
    this->type = income;
    this->color = QColor();
    this->userId = -1;
}

Category::Category(const int &id, const QString &name, const Type &type, const QColor &color, const int &userId)
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

Type Category::getType() const
{
    return this->type;
}

QColor Category::getColor() const
{
    return this->color;
}

QString Category::setId(const int &id)
{
    // TODO: Int validation logic
    this->id = id;
    return "Success";
}

QString Category::setName(const QString &name)
{
    // TODO: Validation logic
    this->name = name;
    return "Success";
}

QString Category::setType(const Type &type)
{
    // TODO: Validation logic
    this->type = type;
    return "Success";
}

QString Category::setColor(const QColor &color)
{
    // TODO: Validation logic; Tt may be realizet with the help of QColor::isValid
    this->color = color;
    return "Success";
}

QString Category::setUserId(const int &userId)
{
    this->userId = userId;
    return "Success";
}
