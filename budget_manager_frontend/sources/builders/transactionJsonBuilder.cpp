#include "transactionJsonBuilder.h"
#include "constants.h"


QJsonObject TransactionJsonBuilder::buildJson(Transaction transaction){
    QJsonObject jObj;
    jObj.insert(models::ID, QJsonValue::fromVariant(transaction.getId()));
    jObj.insert(models::AMOUNT, QJsonValue::fromVariant(transaction.getAmount()));
    jObj.insert(models::DATE, QJsonValue::fromVariant(transaction.getDate()));
    jObj.insert(models::DESCRIPTION, QJsonValue::fromVariant(transaction.getDescription()));
    jObj.insert(models::CATEGORY_ID, QJsonValue::fromVariant(transaction.getCategoryId()));

    return jObj;
}
