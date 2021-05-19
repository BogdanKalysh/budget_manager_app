#ifndef LEGENDLISTITEM_H
#define LEGENDLISTITEM_H

#include <QDialog>
#include <QLabel>
#include <QWidget>
#include "category.h"
#include <QFrame>

class LegendListItem: public QDialog
{
    Q_OBJECT

public:
    LegendListItem(Category category, QWidget *parent = nullptr);
private:
    QLabel *name;
    QFrame *colorCircle;
};

#endif // LEGENDLISTITEM_H
