#ifndef CATEGORY_H
#define CATEGORY_H
#include <QString>
#include <QColor>

class Category
{
    QString name;
    QString type;
    QColor color;
public:
    Category(QString name, QString type, QColor color);

    QString getName();
    QString getType();
    QColor getColor();

    QString setName(QString name);
    QString setType(QString type);
    QString setColor(QColor color);
};

#endif // CATEGORY_H
