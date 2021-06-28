#include "View.h"

// constructor
View::View() : QGraphicsView()
{
    // creat controller
    viewController = new Controller;

    // add scnen
    setScene(viewController->scene);

    // fullsceenig the game window
    setWindowState(Qt::WindowFullScreen);

    // delete scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/game/background1.jpg")));

    // initialize viewTime to zero
    viewTime = 0;

    // create timer
    QObject::connect(viewController->timer, SIGNAL(timeout()), this, SLOT(background()));
    viewController->timer->start(); // to do

}

// destructor
View::~View()
{
    delete viewController;
}

void View::background()
{
    viewController->timer->stop();
}
