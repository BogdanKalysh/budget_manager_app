#include "piechart.h"
#include"ui_piechart.h"
#include<iostream>

Piechart::Piechart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Piechart)
{
    ui->setupUi(this);
    standartSetting();
}

Piechart::Piechart(PieSeries *series,QWidget *parent):
    QWidget(parent),
    ui(new Ui::Piechart)
{
    ui->setupUi(this);
    standartSetting();

    this->series = series;
    this->series->setParent(this);
    this->series->installEventFilter(this);

}

Piechart::~Piechart()
{
    delete ui;
}

void Piechart::paintEvent(QPaintEvent *e)
{
    if (series==nullptr)
        return;

    QPainter painter(this);
    QMap<QString,QColor> piesliceLabelColor=series->getPiesliceLabelColor();
    QFontMetrics fontMetrics(font);

    font.setPointSize(qMin(width(),height())*fontRelativeSize);
    painter.setFont(font);
    painter.setRenderHint(QPainter::Antialiasing, true);

    qreal y = height()*marginY;
    qreal x = width()*marginX;
    qreal totalWidth = 0;
    qreal radius = fontMetrics.horizontalAdvance("X")/2;

    //it is special algorithm to calculate the position of text
    //this algorithm place our text int row with limited width
    //and when there is no place ,it add the new row
    for(auto iter = piesliceLabelColor.constBegin();iter!=piesliceLabelColor.constEnd();iter++){

        qreal textPixelSize = fontMetrics.horizontalAdvance(iter.key());

        if(x+totalWidth+textPixelSize>width()*(1-marginX)){
           totalWidth = 0;
           y+= rowInterval*qMin(width(),height());
        }

        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(iter.value()));
        painter.drawEllipse(x-radius*2+totalWidth,y-radius*2,radius*2,radius*2);

        painter.setPen(textColor);
        painter.drawText(x+totalWidth+radius,y,iter.key());

        totalWidth+= textPixelSize+width()*spacing;
    }

}

void Piechart::resizeEvent(QResizeEvent *event)
{
    if (series!=nullptr)
        series->setGeometry(rect());

}

qreal Piechart::getFontRelativeSize() const
{
    return fontRelativeSize;
}

void Piechart::setFontRelativeSize(const qreal &value)
{
    fontRelativeSize = qBound(minSize,value,maxSize);
}

void Piechart::setTextColor(const QColor &value)
{
    textColor = value;
}

//its some standarts settings for our piechart but they can be changed
void Piechart::standartSetting()
{
    textColor = QColor(0,0,0);
    rowInterval = 0.05;
    spacing = 0.1 ;
    marginX = 0.1;
    marginY = 0.9;
    fontRelativeSize=0.03;

    font.setStyleHint(QFont::Times, QFont::PreferAntialias);
}

PieSeries *Piechart::getSeries() const
{
    return series;
}

void Piechart::setSeries(PieSeries *value)
{
    series = value;
    series->setParent(this);
    series->installEventFilter(this);
}

void Piechart::setFont(const QFont &value)
{
    font = value;
}

qreal Piechart::getMargin() const
{
    return marginX;
}

void Piechart::setMargin(const qreal &x, const qreal &y)
{
    marginX = qBound(minSize,x,maxSize);
    marginY = qBound(minSize,y,maxSize);
}

qreal Piechart::getSpacing() const
{
    return spacing;
}

void Piechart::setSpacing(const qreal &value)
{
    spacing = qBound(minSize,value,maxSize);
}

qreal Piechart::getRowInterval() const
{
    return rowInterval;
}

void Piechart::setRowInterval(const qreal &value)
{
    rowInterval = qBound(minSize,value,maxSize);
}

const qreal Piechart::minSize = 0;
const qreal Piechart::maxSize = 1;
