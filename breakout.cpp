#include "breakout.h"
#include <paddle.h>

//A função de construção dessa classe é responsável por criar o cenário onde o jogo acontece. Essa classe também será responsável pelo Event Handling do jogo
BreakOut::BreakOut()
{

    int x=1;
    QTransform transf;
    transf = transf.rotate(-180, Qt::YAxis);


    scene->setSceneRect(0,0,427,377);
    for(int i = 1; i <= 10; i++){                                                               //Nessa primeira iteração colocamos os tijolso das colunas
        for(int j = 1; j <= 10; j++){                                                           //Nessa segunda iteração colocamos os tijolos das linhas
            bricks[x] = new Brick(112.5 + 23*(j-1), 60 + 28*(i-1), i, j);
            scene->addItem(bricks[x]);                       //Os tijolos são colocados primeiramente no ponto inicial e espaçados de 26px para dar a margem de 1px entre dois tijolos
            x++;
        }
    }


    boss->setTransform(transf);
    boss->setPos(scene->width(), 50);

    ball->setPos(50, 50);

    scene->addItem(player);
    scene->addItem(boss);
    scene->addItem(ball);

    v->setScene(scene);
}

BreakOut::~BreakOut(){
    delete this;
}
