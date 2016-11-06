#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <paddle.h>
#include <brick.h>
#include <ball.h>
#include <breakout.h>
#include <QDebug>
#include <QPainter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BreakOut *game = new BreakOut();
    //game->view->show();
    //game->view->setRenderHint(QPainter::Antialiasing);
    return a.exec();
}
