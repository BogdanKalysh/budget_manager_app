#include<pieslice.h>

PieSlice::PieSlice(QWidget *parent):QWidget(parent)
    ,data(new PieSliceData())
{

}

PieSlice::PieSlice(qreal value, QString label,QRectF& rectangle , QWidget *parent):QWidget(parent)
{
    this->rectangle=rectangle;

    data=new PieSliceData();
    data->label=label;
    data->value=value;
}

PieSlice::~PieSlice()
{

}

PieSlice::setStartAngle(qreal angle)
{
    data->startAngle=angle;
}

PieSlice::setSpanAngle(qreal angle)
{
    data->spanAngle=angle;
}

void PieSlice::setPen(const QPen &value)
{
    pen = value ;
}

QPen PieSlice::getPen() const
{
    return pen;
}

QColor PieSlice::getBorderColor()
{
    return borderColor;
}

void PieSlice::setBorderColor(const QColor &value)
{
    borderColor = value;
}

int PieSlice::getBorderWidth()
{
    return borderWidth;
}

void PieSlice::setBorderWidth(const int &value)
{
    borderWidth = value;
}

void PieSlice::setBrush(const QBrush &value)
{
    brush = value;
}

QColor PieSlice::getColor()
{
    return color;
}

void PieSlice::setColor(const QColor &value)
{
    color = value;
}

qreal PieSlice::startAngle() const
{
    return data->startAngle;
}

qreal PieSlice::spanAngle() const
{
    return data->spanAngle;
}

QRectF PieSlice::getRectangle() const
{
    return rectangle;
}

void PieSlice::setRectangle(const QRectF &value)
{
    rectangle = value;
}

PieSliceData *PieSlice::getData() const
{
    return data;
}

QRegion PieSlice::getRegion() const
{
    return region;
}

void PieSlice::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(pen);

    if(brush.color()!=color){
        painter.setBrush(QBrush(color));
    }
    else{
        painter.setBrush(brush);
    }

    rectangle.normalized();

    QPainterPath path;

    path.moveTo(rectangle.center().x()-rectangle.width()/2, rectangle.center().y()-rectangle.height()/2);
    path.arcTo(rectangle.x()-rectangle.width()/2, rectangle.y()-rectangle.height()/2, rectangle.width(), rectangle.height(), startAngle(), spanAngle());
    path.closeSubpath();

    painter.drawPath(path);

    //calculating the region of our slice (changing this part of code can lead to not correct mousepress events behaviour)
    QPolygon polygon = path.toFillPolygon().toPolygon();
    region = QRegion(polygon,  Qt::WindingFill);

    setMask(region);//this stuff make sometimes some pixels artifacts but without it we cant use mouse events
}

//change this part of code to make your own action on press event
//at this moment its just print the label of pieslice
void PieSlice::mousePressEvent(QMouseEvent *event)
{
    const QPoint p = event->pos();
    event->ignore();
    printf("%s",data->label.toUtf8().constData());
}


