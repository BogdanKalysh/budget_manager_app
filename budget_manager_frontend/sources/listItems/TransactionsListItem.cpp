#include "TransactionsListItem.h"
#include "constants.h"
#include <IJsonBuilder.h>
#include <QHBoxLayout>
#include <QJsonDocument>
#include <QNetworkReply>
#include "transactionJsonBuilder.h"

TransactionsItem::TransactionsItem(const Transaction &transaction, const QSharedPointer<QNetworkAccessManager> &manager, QWidget *parent) : QDialog(parent)
{
    this->id = transaction.getId();
    this->manager = manager;

    Description = new QLabel(transaction.getDescription());
    Description->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFixedHeight(6);
    line->setLineWidth(10);
    if (transaction.getType() == models::INCOME)
        line->setStyleSheet("*{background-color: green;\n border-radius: 3px;}");
    else
        line->setStyleSheet("*{background-color: tomato;\n border-radius: 3px;}");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sum = new QLabel(QString::number(transaction.getAmount())+"₴");
    sum->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    delButton = new QPushButton("×");
    delButton->setVisible(false);
    delButton->setStyleSheet("*::hover{background:rgb(237, 106, 94);}\n*{background:rgba(50,50,50,0.5); padding-bottom:3px;font-size: 20px; border-style: none; height:30px; width:30px; border-radius: 14px;}");

    connect(delButton, &QPushButton::clicked, this, &TransactionsItem::on_delButton_clicked);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(Description);
    layout->addWidget(line);
    layout->addWidget(sum);
    layout->addWidget(delButton);

    setLayout(layout);

    this->setAttribute(Qt::WA_Hover);
}

void TransactionsItem::emitTransactionDeleted()
{
    emit transactionDeleted();
}

void TransactionsItem::on_delButton_clicked()
{
    QNetworkRequest request = QNetworkRequest(QUrl(urls::TRANSACTIONURL + "?" + models::ID + "=" + QString::number(id)));
    QNetworkReply* delTranasactionReply = manager->deleteResource(request);

    connect(delTranasactionReply, &QNetworkReply::finished, this, &TransactionsItem::emitTransactionDeleted);
}

bool TransactionsItem::event(QEvent *e)
{
    if (e->type() == QEvent::HoverEnter) {
        hoverEnter(static_cast<QHoverEvent*>(e));
        return true;
    } else if (e->type() == QEvent::HoverLeave) {
        hoverLeave(static_cast<QHoverEvent*>(e));
        return true;
    }

    return QWidget::event(e);
}

void TransactionsItem::hoverEnter(QHoverEvent *event)
{
    delButton->setVisible(true);
}

void TransactionsItem::hoverLeave(QHoverEvent *event)
{
    delButton->setVisible(false);
}
