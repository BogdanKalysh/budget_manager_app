#ifndef PIESERIES_H
#define PIESERIES_H
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include<QString>
#include<QColor>
#include<QMap>
#include <time.h>
#include <pieslice.h>
#include<hole.h>


class PieSeries :public QWidget
{
    Q_OBJECT
public:
    static const qreal minSize;
    static const qreal maxSize;

private:
    QList<PieSlice*> slices;
    qreal sum;
    QMap<QString, QColor> categoryColor;

public:
    explicit PieSeries(QWidget * parent=nullptr);
    PieSeries(QList<PieSlice *> m_slices,QWidget * parent=nullptr);
    ~PieSeries();

    PieSlice* append(qreal value,QString label);
    void append(PieSlice *slice);

    void setFont(const QFont &value);

    int count();
    void updateSizes();

    qreal getHoleSize() const;
    void setHoleSize(const qreal &value);

    void setHoleColor(const QColor &value) const;

    QFont getCentralTitleFont() const;
    void setCentralTitleFont(const QFont &value);

    QMap<QString, QColor> getCategoryColor() const;
    void setCategoryColor(const QMap<QString, QColor> &value);

    qreal getRelativeRadiusSize() const;
    void setRelativeRadiusSize(const qreal &value);

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent* event);

private:
    qreal getAngle();

    void clear();

    qreal getRadius() const;
    void setRadius();

    QPoint getCenter() const;
    void setCenter();

    void setRectangle();
    QRectF getRectangle() const;

    QColor randomColor();

private:

    qreal angle;
    QFont font;
    QPoint center;
    qreal radius;
    qreal relativeRadiusSize = 0.3;
    QRectF rectangle;
    Hole *hole;

};

#endif // PIESERIES_H
