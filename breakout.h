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
#include <QWidget>
#include <QList>
#include <QTimer>

class BreakOut : public QWidget
{

public:
    BreakOut();
    ~BreakOut();
    QGraphicsView *view;
    QGraphicsScene *scene;
    Ball *ball;
    Paddle *player;
    Paddle *boss;
    QList <Brick* > tijolos;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    void setBallVelocidade(int x, int y);

protected:
    virtual void timerEvent(QTimerEvent *);
    //void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *e);
    //void mouseMoveEvent(QMouseEvent *); //Método para ser implementado pro jogo cumprir os requisitos

    /*void startGame();
    void pauseGame();
    void stopGame();
    void victory();
    void checkCollision();*/

/*private:
    QGraphicsScene *scene;
    Ball *ball;
    Paddle *player;
    Paddle *boss;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;*/
};

#endif // BREAKOUT_H
