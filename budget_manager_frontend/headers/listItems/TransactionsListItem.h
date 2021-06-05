#ifndef TRANSACTIONSLISTITEM_H
#define TRANSACTIONSLISTITEM_H

#include <QDialog>
#include <QEvent>
#include <QHoverEvent>
#include <QLabel>
#include <QWidget>
#include "transaction.h"
#include <QFrame>
#include <QNetworkAccessManager>
#include <QPushButton>

class TransactionsItem : public QDialog
{
    Q_OBJECT

public:
    TransactionsItem(const Transaction &transaction, const QSharedPointer<QNetworkAccessManager> &manager, QWidget *parent = nullptr);
private:
    int id;
    QLabel *Description;
    QFrame *line;
    QLabel *sum;
    QPushButton *delButton;
    QSharedPointer<QNetworkAccessManager> manager;

    bool event(QEvent *e);
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);

    void emitTransactionDeleted();
private slots:
    void on_delButton_clicked();


signals:
    void transactionDeleted();
};

#endif // TRANSACTIONSLISTITEM_H
