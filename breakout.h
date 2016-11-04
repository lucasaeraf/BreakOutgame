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
#include <QKeyEvent>
#include <QTimerEvent>
#include <QTimer>

class BreakOut : public QWidget
{
public:
    BreakOut();
    ~BreakOut();
    QGraphicsView *view;

protected:
    //virtual void timerEvent(QTimerEvent *);
    virtual void keyPressEvent(QKeyEvent* );
    virtual void keyReleaseEvent(QKeyEvent* );
    //void mouseMoveEvent(QMouseEvent *); //Método para ser implementado pro jogo cumprir os requisitos

    /*void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();*/

private:
    QGraphicsScene *scene;
    Ball *ball;
    Paddle *player;
    Paddle *boss;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
};

#endif // BREAKOUT_H
