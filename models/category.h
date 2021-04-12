#ifndef CATEGORY_H
#define CATEGORY_H
#include <QString>
#include <QColor>
#include <constants.h>

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

    QString setId(int id);
    QString setName(QString name);
    QString setType(Type type);
    QString setColor(QColor color);
};

#endif // CATEGORY_H
