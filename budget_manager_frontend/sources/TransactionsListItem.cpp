#include "TransactionsListItem.h"
#include "constants.h"
#include <QHBoxLayout>

TransactionsItem::TransactionsItem(Transaction transaction, QWidget *parent) : QDialog(parent)
{
    Description = new QLabel(transaction.getDescription());
    Description->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFixedHeight(6);
    line->setLineWidth(10);
    if (transaction.getType() == jsonbuilder::INCOME)
        line->setStyleSheet("*{background-color: green;\n border-radius: 3px;}");
    else
        line->setStyleSheet("*{background-color: tomato;\n border-radius: 3px;}");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sum = new QLabel(QString::number(transaction.getAmount())+"₴");
    sum->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(Description);
    layout->addWidget(line);
    layout->addWidget(sum);

    setLayout(layout);
}
