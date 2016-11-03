#include "paddle.h"
#include <QGraphicsItem>
#include <QPainter>

//O paddle consiste em metade de uma elipse contida no retangulo definido pelos limites dado por boundingRect
//O desenho é implementado na função virtual paint herdada de QGraphicsItem
Paddle::Paddle(qreal x, qreal y)
{
    x_bound = x;
    y_bound = y;
}

Paddle::~Paddle()
{
    delete this;
}

void Paddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QBrush *brush = new QBrush(Qt::blue);
    QPen pen(Qt::black, 1);
    painter->setPen(pen);

    QPainterPath *caminho = new QPainterPath();
    caminho->arcMoveTo(boundingRect(), -90);
    caminho->arcTo(boundingRect(), -90, 180);
    caminho->closeSubpath();

    painter->drawPath(*caminho);
    painter->fillPath(*caminho, *brush);
}

QRectF Paddle::boundingRect() const
{
    return QRectF(x_bound, y_bound, 20, 60);
}

void Paddle::move(){

    int y = boundingRect().y() + dy;
    int x = boundingRect().x();

    boundingRect().moveTo(x, y);
}

void Paddle::setDy(int y){
    dy = y;
}
