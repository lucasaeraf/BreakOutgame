#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <paddle.h>
#include <brick.h>
#include <ball.h>
#include <breakout.h>
#include <QPainter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*QGraphicsView *w = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene();
    w->setScene(scene);
    Paddle *paddle = new Paddle(0, 0);
    Ball *ball = new Ball(0, 100);
    scene->addItem(paddle);
    scene->addItem(brick);
    scene->addItem(ball);*/
    BreakOut *game = new BreakOut();
    game->v->setRenderHint(QPainter::Antialiasing);
    game->v->show();
    //w->setRenderHint(QPainter::Antialiasing);
    //w->show();

    return a.exec();
}
