#ifndef CATEGORY_H
#define CATEGORY_H
#include <QString>
#include <QColor>

class Category
{
    int id;
    QString name;
    QString type;
    QColor color;
public:
    Category();
    Category(int id, QString name, QString type, QColor color);
    Category (const Category &other);

    int getId();
    QString getName();
    QString getType();
    QColor getColor();

    QString setId(int id);
    QString setName(QString name);
    QString setType(QString type);
    QString setColor(QColor color);
};

#endif // CATEGORY_H
