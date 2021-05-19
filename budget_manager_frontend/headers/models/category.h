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
    int userId;
public:
    Category();
    Category(int id, QString name, Type type, QColor color, int userId);
    Category (const Category &other);

    int getId();
    int getUserId();
    QString getName();
    Type getType();
    QColor getColor();

    void setId(int id);
    void setName(QString name);
    void setType(Type type);
    void setColor(QColor color);
    void setUserId(int userId);
};

#endif // CATEGORY_H
