#ifndef PIESLICE_H
#define PIESLICE_H
#include <pieslicedata.h>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>

class PieSlice : public QWidget{
    Q_OBJECT
private:

    PieSliceData *data;
    QRectF  rectangle;

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

    void pathCalculation(QPainterPath& path);

public:
    explicit PieSlice(QWidget * parent=nullptr);
    PieSlice(qreal value ,QString label, QRectF& rectangle ,QWidget * parent=nullptr);
    ~PieSlice();


    setStartAngle(qreal angle);
    setSpanAngle(qreal angle);

    void setPen(const QPen &value);
    QPen getPen() const;

    QColor getBorderColor();
    void setBorderColor(const QColor &value);

    int getBorderWidth();
    void setBorderWidth(const int &value);

    void setBrush(const QBrush &value);
    QBrush getBrush() const;

    QColor getColor();
    void setColor(const QColor &value);

    QColor labelColor();
    void setLabelColor(const QColor &value);

    void setLabelFont(const QFont &value);
    QFont labelFont() const;

    qreal startAngle() const;
    qreal spanAngle() const;

    QRectF getRectangle() const;
    void setRectangle(const QRectF &value);

    PieSliceData *getData() const;

    QRegion getRegion() const;

private:

    qreal borderWidth;
    QPen pen;
    QColor color;
    QColor borderColor;
    QBrush brush;
    QColor m_labelcolor;
    QFont m_font;
    QRegion region;
};

#endif // PIESLICE_H
