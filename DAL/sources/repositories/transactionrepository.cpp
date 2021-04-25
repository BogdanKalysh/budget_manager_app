#include "transactionrepository.h"
using namespace dal;

QVector<Transaction> TransactionRepository::select(QString query)
{
    //No realization yet
    //it's pseudo result
    QVector<Transaction> transactions;
    transactions.push_back(Transaction(1, 300, QDate(2020, 04, 27), "going to a restaurant", 2));
    return transactions;
}

bool TransactionRepository::update(Transaction &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        QVector<QString> fields;
        fields << CATEGORY_ID << AMOUNT << DESCRIPTION << DATE;
        QVector<QString> values;
        values << QString::number(object.getCategoryId()) << QString::number(object.getAmount()) << object.getDescription() << object.getDate().toString();

        query.exec(updateQueryBuilder(qMakePair(TRANSACTION, object.getId()), fields, values));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool TransactionRepository::add(Transaction &object)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        QVector<QString> fields;
        fields << CATEGORY_ID << AMOUNT << DESCRIPTION << DATE;
        QVector<QString> values;
        values << QString::number(object.getCategoryId()) << QString::number(object.getAmount()) << object.getDescription() << object.getDate().toString();

        query.exec(insertQueryBuilder(TRANSACTION, fields, values));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}

bool TransactionRepository::deleteObject(int id)
{
    QSqlDatabase db = setUpDatabase();

    if(db.open())
    {
        QSqlQuery query;
        query.exec(deleteQueryBuilder(qMakePair(TRANSACTION, id)));
        db.close();
        return true;
    } else {
        qDebug() << db.lastError();
    }

    return false;
}
