#ifndef CATEGORY_H
#define CATEGORY_H

#include <constants.h>
#include <QString>
#include <QColor>

class Category
{
    int id;
    QString name;
    QString type;
    QColor color;
    int userId;
public:
    Category();
    Category(const int id, const QString &name, const QString &type, const QColor &color, const int userId);
    Category (const Category &other);

    int getId() const;
    int getUserId() const;
    QString getName() const;
    QString getType() const;
    QColor getColor() const;

    void setId(const int id);
    void setName(const QString &name);
    void setType(const QString &type);
    void setColor(const QColor &color);
    void setUserId(const int userId);
};

#endif // CATEGORY_H
