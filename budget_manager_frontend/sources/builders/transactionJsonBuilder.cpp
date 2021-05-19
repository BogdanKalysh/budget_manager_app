#include "transactionJsonBuilder.h"
#include "constants.h"

QJsonObject TransactionJsonBuilder::buildJson(Transaction transaction){
    QJsonObject jObj;
    jObj.insert(jsonbuilder::ID, QJsonValue::fromVariant(transaction.getId()));
    jObj.insert(jsonbuilder::AMOUNT, QJsonValue::fromVariant(transaction.getAmount()));
    jObj.insert(jsonbuilder::DATE, QJsonValue::fromVariant(transaction.getDate()));
    jObj.insert(jsonbuilder::DESCRIPTION, QJsonValue::fromVariant(transaction.getDescription()));
    jObj.insert(jsonbuilder::CATEGORY_ID, QJsonValue::fromVariant(transaction.getCategoryId()));

    return jObj;
}
