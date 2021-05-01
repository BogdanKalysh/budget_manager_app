#include "pieslicedata.h"

PieSliceData::PieSliceData()
{
    value=0;
    label=0;
    startAngle=0;
    spanAngle=0;
}

PieSliceData::PieSliceData(qreal value, QString label)
{
    this->value=value;
    this->label=label;
}

PieSliceData::PieSliceData(qreal value, QString label, qreal startAngle, qreal spanAngle)
{
    this->value=value;
    this->label=label;
    this->startAngle=startAngle;
}

PieSliceData::~PieSliceData()
{

}
