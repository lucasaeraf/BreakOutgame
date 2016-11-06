#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsScene>


class Paddle : public QGraphicsObject
{
public:
    Paddle(qreal x, qreal y);
    ~Paddle();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *e);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QPainterPath shape() const;

public:
   void resetState(); //Função que será usada quando tivermos que resetar o jogo e redefinir a posição do paddle no tabuleiro
   void move();       //Função utilizada para mover o paddle
   void setDy(int);   //Função utilizada para setar o movimento do paddle

private:
    int dy;
    qreal x_bound = 0;
    qreal y_bound = 0;
    int normal = 0;
    //const int INITIAL_Y =
};

#endif // PADDLE_H
