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

    QString setId(int id);
    QString setName(QString name);
    QString setType(Type type);
    QString setColor(QColor color);
    QString setUserId(int userId);
};

#endif // CATEGORY_H
