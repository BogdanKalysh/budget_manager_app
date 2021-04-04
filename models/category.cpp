#include "category.h"

Category::Category()
{
    this->name = QString();
    this->type = QString();
    this->color = QColor();
}

Category::Category(QString name, QString type, QColor color)
{
    this->setName(name);
    this->setType(type);
    this->setColor(color);
}

Category::Category(const Category &other)
{
    this->name = other.name;
    this->type = other.type;
    this->color = other.color;
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

QString Category::setName(QString name)
{
    // TODO: Validation logic
    this->name = name;
    return "Success";
}

QString Category::setType(QString type)
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
