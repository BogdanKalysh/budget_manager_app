#ifndef IJSONPARSER_H
#define IJSONPARSER_H

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>
#include <memory>


template <typename  T>
class IJsonParser
{
public:
    virtual T parse(const QJsonObject &json) = 0;
    virtual QVector<T> parseVector(const QJsonArray &jsonArray) = 0;
};

#endif // IJSONPARSER_H
