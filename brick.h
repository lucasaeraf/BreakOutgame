#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsItem>

class Brick : public QGraphicsObject
{
public:
    Brick(qreal x, qreal y, int i, int j);
    ~Brick();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    qreal x_center = 0;
    qreal y_center = 0;
    int i_index;
    int j_index;
};

#endif // BRICK_H
