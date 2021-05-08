#include "TransactionsListItem.h"

#include <QHBoxLayout>

TransactionsItem::TransactionsItem(Transaction transaction, QWidget *parent) : QDialog(parent)
{
    categoryName = new QLabel(transaction.getCategoryName());
    categoryName->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setFixedHeight(6);
    line->setLineWidth(10);
    if (transaction.getType() == "incomes")
        line->setStyleSheet("*{background-color: green;\n border-radius: 3px;}");
    else
        line->setStyleSheet("*{background-color: tomato;\n border-radius: 3px;}");
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    sum = new QLabel(QString::number(transaction.getAmount())+"₴");
    sum->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(categoryName);
    layout->addWidget(line);
    layout->addWidget(sum);

    setLayout(layout);
}
