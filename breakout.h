#ifndef BREAKOUT_H
#define BREAKOUT_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <ball.h>
#include <paddle.h>
#include <brick.h>

class BreakOut : public QWidget
{
public:
    BreakOut();
    ~BreakOut();

/*protected:
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    //void mouseMoveEvent(QMouseEvent *); //Método para ser implementado pro jogo cumprir os requisitos

    void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();*/

private:
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *v = new QGraphicsView();
    Ball *ball = new Ball(0, 0);
    Paddle *player = new Paddle(0,50);
    Paddle *boss = new Paddle(0, 0);
    Brick *bricks[100];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
};

#endif // BREAKOUT_H
