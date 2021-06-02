#include "transactionjsonbuilder.h"
#include "constants.h"
#include <QJsonValue>

using namespace models;

QJsonObject TransactionJsonBuilder::buildJson(Transaction transaction){
    QJsonObject jObj;

    jObj.insert(ID, QJsonValue::fromVariant(transaction.getId()));
    jObj.insert(AMOUNT, QJsonValue::fromVariant(transaction.getAmount()));
    jObj.insert(DATE, QJsonValue::fromVariant(transaction.getDate()));
    jObj.insert(DESCRIPTION, QJsonValue::fromVariant(transaction.getDescription()));
    jObj.insert(CATEGORY_ID, QJsonValue::fromVariant(transaction.getCategoryId()));
    jObj.insert(CATEGORY_NAME, QJsonValue::fromVariant(transaction.getCategoryName()));
    jObj.insert(COLOR, QJsonValue::fromVariant(transaction.getColor()));
    jObj.insert(TYPE, QJsonValue::fromVariant(transaction.getType()));

    return jObj;
}
