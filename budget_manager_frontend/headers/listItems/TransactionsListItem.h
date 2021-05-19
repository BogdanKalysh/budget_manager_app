#ifndef TRANSACTIONSLISTITEM_H
#define TRANSACTIONSLISTITEM_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include "transaction.h"
#include <QFrame>

class TransactionsItem : public QDialog
{
    Q_OBJECT

public:
    TransactionsItem(Transaction transaction, QWidget *parent = nullptr);
private:
    QLabel *Description;
    QFrame *line;
    QLabel *sum;
};

#endif // TRANSACTIONSLISTITEM_H
