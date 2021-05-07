#include "transactionrepository.h"

using namespace dal;

QVector<Transaction> TransactionRepository::select(const QString &query)
{
    QVector<Transaction> transactions;
    QSqlDatabase db = setUpDatabase();

    if(db.open()) {
        QSqlQuery result(query);

        while(result.next()) {
            transactions.push_back(Transaction(
                                result.value(ID).toInt(),
                                result.value(AMOUNT).toInt(),
                                result.value(DATE).toDate(),
                                result.value(DESCRIPTION).toString(),
                                result.value(CATEGORY_ID).toInt()
                                ));
        }
    } else {
        qDebug() << db.lastError();
    }

    return transactions;
}

bool TransactionRepository::update(const Transaction &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open()) {
        QSqlQuery query;

        QVector<QString> fields;
        fields << CATEGORY_ID << AMOUNT << DESCRIPTION << DATE;

        QVector<QString> values;
        values << QString::number(object.getCategoryId())
               << QString::number(object.getAmount())
               << object.getDescription()
               << object.getDate().toString();

        query.exec(updateQueryBuilder(qMakePair(TRANSACTION, object.getId()), fields, values));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool TransactionRepository::add(const Transaction &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open()) {
        QSqlQuery query;

        QVector<QString> fields;
        fields << CATEGORY_ID << AMOUNT << DESCRIPTION << DATE;

        QVector<QString> values;
        values << QString::number(object.getCategoryId())
               << QString::number(object.getAmount())
               << object.getDescription()
               << object.getDate().toString();

        query.exec(insertQueryBuilder(TRANSACTION, fields, values));
        db.close();

        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool TransactionRepository::deleteObject(const int id)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open()) {
        QSqlQuery query;

        query.exec(deleteQueryBuilder(qMakePair(TRANSACTION, id)));
        db.close();

        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}
