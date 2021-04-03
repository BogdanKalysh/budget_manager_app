#include "categoryparcer.h"
#include <QJsonArray>

template<typename T>
Category CategoryParcer<T>::parce(QJsonObject json)
{
    QString name = json.value("name").toString();
    QString type = json.value("type").toString();

    QJsonArray jRGB = json.value("color").toArray();
    QColor color(jRGB[0].toInt(), jRGB[1].toInt(), jRGB[2].toInt());

    return Category(name, type, color);
}
