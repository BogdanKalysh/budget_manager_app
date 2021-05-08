
#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include<pieseries.h>


namespace Ui {
class Piechart;
}

class Piechart : public QWidget
{
    Q_OBJECT
public:
    static const qreal minSize;
    static const qreal maxSize;

public:
    explicit Piechart(QWidget *parent = nullptr);
    Piechart(PieSeries* series,QWidget *parent = nullptr);
    ~Piechart();

    void setHole(qreal);

    qreal getRowInterval() const;
    void setRowInterval(const qreal &value);

    qreal getSpacing() const;
    void setSpacing(const qreal &value);

    qreal getMargin() const;
    void setMargin(const qreal &x,const qreal &y);

    void setFont(const QFont &value);

    PieSeries *getSeries() const;
    void setSeries(PieSeries *value);

    void setTextColor(const QColor &value);

    qreal getFontRelativeSize() const;
    void setFontRelativeSize(const qreal &value);

    void standartSetting();

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

private:
    Ui::Piechart *ui;
    PieSeries *series;

    QFont font;
    QColor textColor;

    qreal rowInterval;
    qreal spacing;
    qreal marginX;
    qreal marginY;
    qreal fontRelativeSize;

};

#endif // PIECHART_H

