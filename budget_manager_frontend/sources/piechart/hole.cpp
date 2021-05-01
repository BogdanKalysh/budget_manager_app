#include "hole.h"

Hole::Hole(QWidget *parent) :
    QWidget(parent)

{
    font.setStyleHint(QFont::Times, QFont::PreferAntialias);
    textColor = Qt::black;
    backgroundColor = Qt::white;
    relativeFontSize=0.1;

    setAttribute(Qt::WA_TransparentForMouseEvents);

}
void Hole::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(backgroundColor));

    QPainterPath path;

    path.moveTo(rect.center());
    path.arcTo(rect.x()-rect.width()/2*size, rect.y()-rect.height()/2*size, rect.width()*size, rect.height()*size, 0,360);
    path.closeSubpath();

    painter.drawPath(path);

    qreal fontSize=rect.width()*relativeFontSize;
    font.setPointSize(fontSize);

    painter.setPen(textColor);
    painter.setFont(font);

    //centering of text in circle
    QFontMetrics fontMetrics(painter.font());
    qreal totalWidth = fontMetrics.horizontalAdvance(labelText);

    painter.drawText(rect.x()-totalWidth/2,rect.y()+fontSize/2,labelText);
}

QFont Hole::getFont() const
{
    return font;
}

qreal Hole::getSize() const
{
    return size;
}

void Hole::setTextColor(const QColor &value)
{
    textColor = value;
}

void Hole::setRelativeFontSize(const qreal &value)
{
    relativeFontSize = value;
}

void Hole::setLabelText(const QString &value)
{
    labelText = value;
}

void Hole::setFont(const QFont &value)
{
    font = value;
}

void Hole::setSize(const qreal &value)
{
    size = value;
}

QRectF Hole::getRect() const
{
    return rect;
}

void Hole::setRect(const QRectF &value)
{
    rect = value;
}

void Hole::mousePressEvent(QMouseEvent *event)
{

}

void Hole::setBackgroundColor(const QColor &value)
{
    backgroundColor = value;
}
