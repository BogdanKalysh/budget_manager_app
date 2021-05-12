#include<pieseries.h>
#include<iostream>


PieSeries::PieSeries(QWidget *parent)
    :QWidget(parent)
{
    init();
}

PieSeries::PieSeries(QList<QSharedPointer<PieSlice>> slices, QWidget *parent)
    :QWidget(parent)
{
    this->slices=slices;
    init();
}

PieSeries::~PieSeries()
{
    clear();
    delete hole;
}

void PieSeries::init()
{
    srand (time(NULL));
    relativeRadiusSize = 0.4;
    hole=new Hole();

    hole->setParent(this);
    hole->setRect(this->rectangle);
    hole->installEventFilter(this);
}

PieSlice* PieSeries::append(qreal value, QString label)
{
    QSharedPointer<PieSlice> slice = QSharedPointer<PieSlice>(new PieSlice(value,label,rectangle),&QObject::deleteLater);
    append(slice);
    slice.clear();

}

PieSlice *PieSeries::append(qreal value, QString label, QColor color)
{
    QSharedPointer<PieSlice> slice = QSharedPointer<PieSlice>(new PieSlice(value,label,color,rectangle),&QObject::deleteLater);
    append(slice);
    slice.clear();
}

void PieSeries::append(QSharedPointer<PieSlice> slice)
{
    qreal totalSum=0;

    if(slice->parentWidget()!=nullptr) // already added to some series
        return;
    slice.get()->setParent(this);

    slices.append(slice);

    //calculating geometry for all slices
    //this algorithm calculates start and span angle for sector(geometry of pieslice widget is circle sector)
    for (QSharedPointer<PieSlice> s: slices){
        totalSum+=s.get()->getData()->value;
    }

    angle=(qreal)360/totalSum;
    qreal startAngle = 0;

    for (QSharedPointer<PieSlice> s: slices) {

        PieSlice * slice = s.get();

        qreal spanAngle=slice->getData()->value*angle;

        slice->setStartAngle(startAngle);
        slice->setSpanAngle(spanAngle);
        startAngle+=spanAngle;

        slice->resize(this->width(),this->height());
        slice->setPen(Qt::NoPen);                   // it sets the border of pislice to none
        slice->installEventFilter(this);
        slice->show();
    }

    hole->setLabelText(QString::number(totalSum) + " ₴");//Label in the center of our widget is total sum of pieslices value
    hole->raise();
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
    if(slices.length()==0)
        return ;
    for (QSharedPointer<PieSlice> s: slices){
        s.get()->setRectangle(this->rectangle);
        s.get()->resize(this->width(),this->height());
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
    rectangle = QRectF(center.x(),center.y()-height()/2*(1-marginY)+radius,radius*2,radius*2);
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

void PieSeries::setMarginY(const qreal &value)
{
    marginY = qBound(minSize,value,maxSize);
}

qreal PieSeries::getRelativeRadiusSize() const
{
    return relativeRadiusSize;
}

void PieSeries::setRelativeRadiusSize(const qreal &value)
{
    relativeRadiusSize = value;
}

void PieSeries::setHoleTextColor(const QColor &value)
{
    hole->setTextColor(value);
}

void PieSeries::clear()
{

    for (QSharedPointer<PieSlice> s: slices){
        s.clear();//this qt method dropping the reference that it may have had to the pointer.
                  //If this was the last reference, then the pointer itself will be deleted.
    }
   slices.clear();
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

QMap<QString, QColor> PieSeries::getPiesliceLabelColor() const
{
    QMap<QString, QColor> piesliceLabelColor;
    for (QSharedPointer<PieSlice> s: slices) {
        PieSlice * slice = s.get();
        piesliceLabelColor.insert(slice->getData()->label,slice->getColor());
    }
    return piesliceLabelColor;
}

const qreal PieSeries::minSize=0;
const qreal PieSeries::maxSize=1;
