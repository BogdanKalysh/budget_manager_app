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
#include <memory>

class PieSeries :public QWidget
{
    Q_OBJECT
public:
    static const qreal minSize;
    static const qreal maxSize;

private:
    QList<QSharedPointer<PieSlice>> slices;
    qreal sum;

public:
    explicit PieSeries(QWidget * parent=nullptr);
    PieSeries(QList<QSharedPointer<PieSlice>> m_slices,QWidget * parent=nullptr);
    ~PieSeries();

    PieSlice* append(qreal value,QString label);
    PieSlice* append(qreal value,QString label,QColor color);
    void append(QSharedPointer<PieSlice> slice);

    void setFont(const QFont &value);

    int count();
    void updateSizes();

    qreal getHoleSize() const;
    void setHoleSize(const qreal &value);

    void setHoleColor(const QColor &value) const;

    QFont getCentralTitleFont() const;
    void setCentralTitleFont(const QFont &value);

    QMap<QString, QColor> getPiesliceLabelColor() const;

    qreal getRelativeRadiusSize() const;
    void setRelativeRadiusSize(const qreal &value);

    void clear();
protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent* event);

private:
    void init();
    qreal getAngle();

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
    qreal relativeRadiusSize;
    QRectF rectangle;
    Hole *hole;

};

#endif // PIESERIES_H
