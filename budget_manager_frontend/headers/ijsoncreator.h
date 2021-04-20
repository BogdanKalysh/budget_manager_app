#ifndef IJSONCREATOR_H
#define IJSONCREATOR_H

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>


template <typename  T>
class IJsonCreator
{
public:
    virtual QJsonObject create( json) = 0;
};
#endif // IJSONCREATOR_H
