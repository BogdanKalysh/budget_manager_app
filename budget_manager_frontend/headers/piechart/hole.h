#ifndef HOLE_H
#define HOLE_H
#include <QPainter>
#include <QPainterPath>
#include <QWidget>
namespace Ui {
class Hole;
}
class Hole :public QWidget
{
    Q_OBJECT

public:
    explicit Hole(QWidget *parent = nullptr);

    QRectF getRect() const;

    void setRect(const QRectF &value);

    void setSize(const qreal &value);

    void setFont(const QFont &value);

    void setLabelText(const QString &value);

    void setRelativeFontSize(const qreal &value);

    void setTextColor(const QColor &value);

    qreal getSize() const;

    QFont getFont() const;

    void setBackgroundColor(const QColor &value);

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

private:
    Ui::Hole *ui;
    QRectF rect;
    qreal relativeFontSize;
    qreal size;
    QFont font;
    QColor backgroundColor;
    QColor textColor;
    QString labelText;
};

#endif // HOLE_H
