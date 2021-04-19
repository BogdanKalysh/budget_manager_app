#ifndef PIESLICEDATA_H
#define PIESLICEDATA_H

#include<QString>

#include<QWidget>
#include<QPainter>



class PieSliceData
{
public:
    qreal value;
    QString label;
    qreal startAngle;
    qreal spanAngle;



public:
    PieSliceData();
    PieSliceData(qreal value,QString label);
    PieSliceData(qreal value,QString label,qreal startAngle,qreal spanAngle);

    ~PieSliceData();

private:

    friend class PieSeries;

};

#endif // PIESLICEDATA_H
