#include<pieseries.h>
#include<iostream>

QMap<QString, QColor> PieSeries::getCategoryColor() const
{
    return categoryColor;
}

void PieSeries::setCategoryColor(const QMap<QString, QColor> &value)
{
    categoryColor = value;
}

PieSeries::PieSeries(QWidget *parent)
    :QWidget(parent)
{
    srand (time(NULL));

    hole=new Hole();

    hole->setParent(this);
    hole->setRect(this->rectangle);
    hole->installEventFilter(this);
}

PieSeries::PieSeries(QList<PieSlice *> slices, QWidget *parent)
    :QWidget(parent)
{
    srand (time(NULL));

    this->slices=slices;

    hole=new Hole();

    hole->setParent(this);
    hole->setRect(this->rectangle);
    hole->installEventFilter(this);
}

PieSeries::~PieSeries()
{

}

PieSlice* PieSeries::append(qreal value, QString label)
{
    PieSlice *slice = new PieSlice(value,label,rectangle);
    append(slice);
    return slice;
}

void PieSeries::append(PieSlice *slice)
{
    qreal totalSum=0;

    if(slice->parentWidget()!=nullptr) // already added to some series
        return;
    slice->setParent(this);

    slices.append(slice);

    //calculating geometry for all slices
    //this algorithm calculates start and span angle for sector(geometry of pieslice widget is circle sector)
    foreach (PieSlice *s, slices) {
        totalSum+=s->getData()->value;
    }

    angle=(qreal)360/totalSum;
    qreal startAngle = 0;

    foreach (PieSlice *s, slices) {
        qreal spanAngle=s->getData()->value*angle;

        s->setStartAngle(startAngle);
        s->setSpanAngle(spanAngle);
        startAngle+=spanAngle;

        //set all atributtes of pieslice
        if(categoryColor.find(s->getData()->label)==categoryColor.end()){
            QColor color =randomColor();                           //if category has no user color we just random color
            categoryColor.insert(s->getData()->label,color);
        }

        s->setColor(categoryColor.find(s->getData()->label).value());
        s->setPen(Qt::NoPen);                   // it sets the border of pislice to none
        s->installEventFilter(this);
    }

    hole->setLabelText(QString::number(totalSum));//Label in the center of our widget is total sum of pieslices value
}

QPoint PieSeries::getCenter() const
{
    return center;
}

void PieSeries::setCenter()
{
    center =QPoint(this->rect().center());
}

//this function recalculate geometry of our pieseries
void PieSeries::updateSizes()
{
    if(this->parentWidget()!=nullptr){
        setCenter();
        setRadius();
        setRectangle();
    }
}

void PieSeries::paintEvent(QPaintEvent *e)
{
    hole->raise();
}

//on resize event geometry of pieslice and hole is changed
void PieSeries::resizeEvent(QResizeEvent *event)
{
    updateSizes();

    foreach (PieSlice *s, slices) {
        s->setRectangle(this->rectangle);
        s->resize(this->width(),this->height());
    }

    hole->setRect(rectangle);
    hole->resize(this->width(),this->height());

}

qreal PieSeries::getAngle()
{
    return angle;
}

void PieSeries::setRectangle()
{
    rectangle = QRectF(center.x(),center.y(),radius*2,radius*2);
}

QRectF PieSeries::getRectangle() const
{
    return rectangle;
}

qreal PieSeries::getRadius() const
{
    return radius;
}

void PieSeries::setRadius()
{
    radius = qMin(width(),height())*relativeRadiusSize; //radius is calculated in accordance to size of pieseries
}

QColor PieSeries::randomColor()
{
    return QColor(rand()%256, rand()%256, rand()%256);//just return a random color
}

qreal PieSeries::getRelativeRadiusSize() const
{
    return relativeRadiusSize;
}

void PieSeries::setRelativeRadiusSize(const qreal &value)
{
    relativeRadiusSize = value;
}

QFont PieSeries::getCentralTitleFont() const
{
    return hole->getFont();
}

void PieSeries::setCentralTitleFont(const QFont &value)
{
    hole->setFont(value);
}

qreal PieSeries::getHoleSize() const
{
    return hole->getSize();
}

void PieSeries::setHoleSize(const qreal &value)
{
    hole->setSize(qBound(minSize,value,maxSize));
}

void PieSeries::setHoleColor(const QColor &value) const
{
    hole->setBackgroundColor(value);
}

const qreal PieSeries::minSize=0;
const qreal PieSeries::maxSize=1;
