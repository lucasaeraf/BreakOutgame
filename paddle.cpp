#include "paddle.h"
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsScene>

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

void Paddle::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:

        this->setDy(-1);
        this->move();
        qDebug() << "Apertou pra cima";
        //this->update();
        break;

    case Qt::Key_Down:
        this->setDy(1);
        this->move();
        qDebug() << "Apertou pra baixo";
       // this->update();
        break;
    }
}

void Paddle::keyReleaseEvent(QKeyEvent *e) {

    int dy = 0;

    switch ( e->key() ) {
        case Qt::Key_Up:
            dy = 0;
            this->setDy(dy);
            break;

        case Qt::Key_Down:
            dy = 0;
            this->setDy(dy);
            break;
        default:
            QGraphicsItem::keyReleaseEvent(e);
    }
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
    qDebug() << "repintei";
}

QRectF Paddle::boundingRect() const
{
    return QRectF(x_bound, y_bound, 20, 60);
}

QPainterPath Paddle::shape() const
{
    QPainterPath *caminho = new QPainterPath();
    caminho->arcMoveTo(boundingRect(), -90);
    caminho->arcTo(boundingRect(), -90, 180);
    caminho->closeSubpath();

    return *caminho;
}

void Paddle::move(){

    this->prepareGeometryChange();
    y_bound = boundingRect().y() + this->dy;
    qDebug() << y_bound;
    x_bound = boundingRect().x();
    qDebug() << x_bound;
    boundingRect().moveTo(x_bound, y_bound);
    this->update();
}

void Paddle::setDy(int y){
    this->dy = y;
}
