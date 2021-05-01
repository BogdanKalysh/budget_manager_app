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

    relativeRadiusSize =0.3;
    hole=new Hole();

    hole->setParent(this);
    hole->setRect(this->rectangle);
    hole->installEventFilter(this);
}

PieSeries::PieSeries(QList<QSharedPointer<PieSlice>> slices, QWidget *parent)
    :QWidget(parent)
{
    srand (time(NULL));

    this->slices=slices;
    relativeRadiusSize =0.3;
    hole=new Hole();

    hole->setParent(this);
    hole->setRect(this->rectangle);
    hole->installEventFilter(this);
}

PieSeries::~PieSeries()
{
    for (QSharedPointer<PieSlice> s: slices){
        s.clear();//this qt method dropping the reference that it may have had to the pointer.
                  //If this was the last reference, then the pointer itself will be deleted.
    }

    slices.clear();
    delete hole;

}

PieSlice* PieSeries::append(qreal value, QString label)
{
    QSharedPointer<PieSlice> slice = QSharedPointer<PieSlice>(new PieSlice(value,label,rectangle),&QObject::deleteLater);

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
    foreach (QSharedPointer<PieSlice> s, slices){
        totalSum+=s.get()->getData()->value;
    }

    angle=(qreal)360/totalSum;
    qreal startAngle = 0;

    for (QSharedPointer<PieSlice> s: slices) {

        PieSlice * slice=s.get();

        qreal spanAngle=slice->getData()->value*angle;

        slice->setStartAngle(startAngle);
        slice->setSpanAngle(spanAngle);
        startAngle+=spanAngle;

        //set all atributtes of pieslice
        if(categoryColor.find(slice->getData()->label)==categoryColor.end()){
            QColor color =randomColor();                           //if category has no user color we just random color
            categoryColor.insert(slice->getData()->label,color);
        }

        slice->setColor(categoryColor.find(slice->getData()->label).value());
        slice->setPen(Qt::NoPen);                   // it sets the border of pislice to none
        slice->installEventFilter(this);
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
