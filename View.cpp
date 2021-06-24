#include "View.h"

View::View() : QGraphicsView()
{
    //create scnen
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1920, 1080);
    setScene(scene);

    //fullsceenig the game window
    setWindowState(Qt::WindowFullScreen);

    //delete scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //adding background
    setBackgroundBrush(QBrush(QImage(":/images/SpaceBackground2.jpg")));

}
