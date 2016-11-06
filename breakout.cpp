#include "breakout.h"
#include <paddle.h>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QObject>
#include <QDebug>

//A função de construção dessa classe é responsável por criar o cenário onde o jogo acontece. Essa classe também será responsável pelo Event Handling do jogo
BreakOut::BreakOut()
{
    scene = new QGraphicsScene();
    gameOver = false;
    gameWon = false;
    gameStarted = false;
    paused = false;
    int k = 0;

    QTransform transf;
    transf = transf.rotate(-180, Qt::YAxis);


    scene->setSceneRect(0,0,427,377);
    //scene->setSceneRect(0,0,700,800);
    for(int i = 1; i <= 10; i++){                                                               //Nessa primeira iteração colocamos os tijolso das colunas
        for(int j = 1; j <= 10; j++){                                                           //Nessa segunda iteração colocamos os tijolos das linhas
            tijolos.append(new Brick(112.5 + 23*(j-1), 60 + 28*(i-1), i, j));
            scene->addItem(tijolos.at(k));                       //Os tijolos são colocados primeiramente no ponto inicial e espaçados de 26px para dar a margem de 1px entre dois tijolos
            k++;
        }
    }

    player = new Paddle(0, 50);

    boss = new Paddle(0,0);
    boss->setTransform(transf);
    boss->setPos(this->scene->width(), 50);

    ball = new Ball(50, 50);
    ball->setBottomEdge(377);

    scene->addItem(this->player);
    scene->addItem(this->boss);
    scene->addItem(this->ball);

    setBallVelocidade(1, -1);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->fitInView(scene->sceneRect());
    view->show();

    QObject::startTimer(100);

}

BreakOut::~BreakOut(){
    delete this;
}

void BreakOut::setBallVelocidade(int x, int y){
    ball->setXDir(x);
    ball->setYDir(y);
}

/*
void BreakOut::keyReleaseEvent(QKeyEvent *e) {

    int dy = 0;

    switch ( e->key() ) {
        case Qt::Key_Up:
            dy = 0;
            this->player->setDy(dy);
            break;

        case Qt::Key_Down:
            dy = 0;
            this->player->setDy(dy);
            break;
        default:
            QWidget::keyReleaseEvent(e);
    }
}*/

void BreakOut::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    ball->autoMove();
}
