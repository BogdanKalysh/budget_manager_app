#include "legendlistitem.h"
#include "constants.h"
#include <QHBoxLayout>


LegendListItem::LegendListItem(const Category &category, QWidget *parent) : QDialog(parent)
{
    colorCircle = new QFrame;
    colorCircle->setFrameShape(QFrame::HLine);
    colorCircle->setStyleSheet("*{background-color:" + category.getColor().name() + ";\nborder-radius:7px;}");
    colorCircle->setFixedSize(14,14);

    name = new QLabel(category.getName());
    name->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    name->setStyleSheet("font-size: 15px;");


    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(colorCircle);
    layout->addWidget(name);

    setLayout(layout);
}
