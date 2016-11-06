#include "ball.h"
#include <QDebug>

//A classe Ball é reposável pelas funcionalidades e desenho da bola. Ela é uma reimplementação de QGraphicsItem
Ball::Ball(qreal x, qreal y)
{
    x_center = x;
    y_center = y;
}

QRectF Ball::boundingRect() const{
    return QRectF(x_center - 8, y_center - 8, 16, 16);
}

QPainterPath Ball::shape() const{
    QPainterPath forma;
    forma.addEllipse(boundingRect());
    return forma;

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
    this->prepareGeometryChange();
    boundingRect().moveTo(x_center - 8, y_center - 8);
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

    this->prepareGeometryChange();
    x_center += xdir;
    y_center += ydir;
    //qDebug() << x_center;
    //qDebug() << y_center;
    //qDebug() << boundingRect().top();

    if (boundingRect().top() == 0) {
        qDebug() << "to dentro";
        ydir = -ydir;
    }

    if (boundingRect().bottom() == BOTTOM_EDGE) {
      ydir = -ydir;
    }
    this->update();

}
