#include "Controller.h"

// constructor
Controller::Controller(QObject *parent) : QObject(parent)
{
    // create scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 1920, 1080);

    // create timer of the game
    cTimer = new QTimer;
    cTimer->start(); // to do

    // create holder
    holder = new QGraphicsRectItem;
    holder->setRect(0, 0, 1920, 1080);
}

// destructor
Controller::~Controller()
{
    delete cTimer;
    delete scene;
    delete holder;
}

void Controller::addChicken(int speed)
{
    ChickenList.push_back(new Chicken{speed , cTimer , holder});
    scene->addItem(ChickenList.last());
    ChickenList.last()->setPos(0 , 0);
}
