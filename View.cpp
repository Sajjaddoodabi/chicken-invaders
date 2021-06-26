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
    setBackgroundBrush(QBrush(QImage(":/images/SpaceBackground2.jpj")));

    // initialize viewTime to zero
    viewTime = 0;

    // create timer
    QObject::connect(viewController->cTimer, SIGNAL(timeout()), this, SLOT(background()));
    viewController->cTimer->start(); // to do

}

// destructor
View::~View()
{
    delete viewController;
}

void View::background()
{
    viewController->cTimer->stop();
}
