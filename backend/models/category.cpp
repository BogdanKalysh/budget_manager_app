#include "category.h"

Category::Category()
{
    // Attention! Not valid data!
    this->id = -1;
    this->name = QString();
    this->type = income;
    this->color = QColor();
}

Category::Category(int id, QString name, Type type, QColor color)
{
    this->setId(id);
    this->setName(name);
    this->setType(type);
    this->setColor(color);
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

QString Category::getName()
{
    return this->name;
}

Type Category::getType()
{
    return this->type;
}

QColor Category::getColor()
{
    return this->color;
}

QString Category::setId(int id)
{
    // TODO: Int validation logic
    this->id = id;
    return "Success";
}

QString Category::setName(QString name)
{
    // TODO: Validation logic
    this->name = name;
    return "Success";
}

QString Category::setType(Type type)
{
    // TODO: Validation logic
    this->type = type;
    return "Success";
}

QString Category::setColor(QColor color)
{
    // TODO: Validation logic; Tt may be realizet with the help of QColor::isValid
    this->color = color;
    return "Success";
}
