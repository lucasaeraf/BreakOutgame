#include "breakout.h"
#include <paddle.h>
#include <QKeyEvent>
#include <QDebug>

//A função de construção dessa classe é responsável por criar o cenário onde o jogo acontece. Essa classe também será responsável pelo Event Handling do jogo
BreakOut::BreakOut()
{

    view = new QGraphicsView();
    scene = new QGraphicsScene();

    gameOver = false;
    gameWon = false;
    gameStarted = false;
    paused = false;

    QTransform transf;
    transf = transf.rotate(-180, Qt::YAxis);


    scene->setSceneRect(0,0,427,377);
    for(int i = 1; i <= 10; i++){                                                               //Nessa primeira iteração colocamos os tijolso das colunas
        for(int j = 1; j <= 10; j++){                                                           //Nessa segunda iteração colocamos os tijolos das linhas
            scene->addItem(new Brick(112.5 + 23*(j-1), 60 + 28*(i-1), i, j));                       //Os tijolos são colocados primeiramente no ponto inicial e espaçados de 26px para dar a margem de 1px entre dois tijolos
            }
    }

    player = new Paddle(0, 50);

    boss = new Paddle(0,0);
    boss->setTransform(transf);
    boss->setPos(scene->width(), 50);

    ball = new Ball(50, 50);

    scene->addItem(player);
    scene->addItem(boss);
    scene->addItem(ball);

    view->setScene(scene);
    QObject::startTimer(50);
}

BreakOut::~BreakOut(){
    delete this;
}

void BreakOut::keyPressEvent(QKeyEvent *event){

    int dy = 0;
    switch ( event->key() ) {
    case Qt::Key_Up:

        dy = -1;
        player->setDy(dy);
        qDebug() << "Apertou pra cima";
        break;

    case Qt::Key_Down:

        dy = 1;
        player->setDy(dy);
        qDebug() << "Apertou pra baixo";
        break;

    default:
        QWidget::keyPressEvent(event);
    }
}

void BreakOut::keyReleaseEvent(QKeyEvent *e) {

    int dy = 0;

    switch ( e->key() ) {
        case Qt::Key_Up:
            dy = 0;
            player->setDy(dy);
            break;

        case Qt::Key_Down:
            dy = 0;
            player->setDy(dy);
            break;
    }
}

/*void BreakOut::timerEvent(QTimerEvent *e) {


  ball->autoMove();
  ball->update();
  scene->update();
}*/
