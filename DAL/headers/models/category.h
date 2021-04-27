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
    Category(const int id, const QString name, const Type type, const QColor color, const int userId);
    Category (const Category &other);

    int getId() const;
    int getUserId() const;
    QString getName() const;
    Type getType() const;
    QColor getColor() const;

    QString setId(const int id);
    QString setName(const QString name);
    QString setType(const Type type);
    QString setColor(const QColor color);
    QString setUserId(const int userId);
};

#endif // CATEGORY_H
