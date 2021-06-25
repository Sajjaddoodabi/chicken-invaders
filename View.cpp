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

    //create timer
    viewTime = 0;
    viewTimer = new QTimer();
    QObject::connect(viewTimer, SIGNAL(timeout()), this, SLOT(background()));
    viewTimer->start(500);

}

void View::background()
{
    viewTime += 0.5;
    if(viewTime == 4){
        viewTimer->stop();
        exit(1);}
}
