#ifndef CATEGORY_H
#define CATEGORY_H
#include <constants.h>
#include <QString>
#include <QColor>

class Category
{
    int id;
    QString name;
    Type type;
    QColor color;
public:
    Category();
    Category(int id, QString name, Type type, QColor color);
    Category (const Category &other);

    int getId();
    QString getName();
    Type getType();
    QColor getColor();

    void setId(int id);
    void setName(QString name);
    void setType(Type type);
    void setColor(QColor color);
};

#endif // CATEGORY_H

