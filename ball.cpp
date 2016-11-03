#include "ball.h"

//A classe Ball é reposável pelas funcionalidades e desenho da bola. Ela é uma reimplementação de QGraphicsItem
Ball::Ball(qreal x, qreal y)
{
    x_center = x;
    y_center = y;
}

QRectF Ball::boundingRect() const{
    return QRectF(x_center - 7.5, y_center - 7.5, 15, 15);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse(boundingRect());
}

Ball::~Ball(){
    delete this;
}

void Ball::setBottomEdge(int bot){
    BOTTOM_EDGE = bot;
}

void Ball::resetState(){
    boundingRect().moveTo(x_center - 7.5, y_center - 7.5);
}

void Ball::setXDir(int x){
    xdir = x;
}

void Ball::setYDir(int y){
    ydir = y;
}

int Ball::getXDir(){
    return xdir;
}

int Ball::getYDir(){
    return ydir;
}

void Ball::autoMove(){

    boundingRect().translate(xdir, ydir);

    if (boundingRect().top() == 0) {
      ydir = -ydir;
    }

    if (boundingRect().bottom() == BOTTOM_EDGE) {
      ydir = -ydir;
    }

}
