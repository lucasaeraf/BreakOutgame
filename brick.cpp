#include "brick.h"
#include <QPainter>

//A Classe Brick é uma subclasse de QGraphicsItem que desenha e implementa as funcionalidades dos tijolos que compõem o jogo
Brick::Brick(qreal x, qreal y, int i, int j)
{
    x_center = x;
    y_center = y;
    i_index = i;
    j_index = j;
}

QRectF Brick::boundingRect() const{
    return QRectF(x_center - 10, y_center - 12.5, 20, 25);
}

void Brick::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QBrush *brush = new QBrush(Qt::red);
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->drawRect(boundingRect());
    painter->fillRect(boundingRect(), *brush);

}

Brick::~Brick(){
    delete this;
}

