#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QPainter>


class Ball : public QGraphicsObject
{
public:
    Ball(qreal x, qreal y);
    ~Ball();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

public:
    void resetState();
    void autoMove();
    void setXDir(int x);
    void setYDir(int y);
    void setBottomEdge(int bot);
    int getXDir();
    int getYDir();

private:
    qreal x_center = 0;
    qreal y_center = 0;
    int xdir;
    int ydir;
    int BOTTOM_EDGE;
};

#endif // BALL_H
