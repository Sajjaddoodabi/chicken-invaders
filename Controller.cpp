#include "Controller.h"

// constructor
Controller::Controller(QObject *parent) : QObject(parent)
{
    // creating scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 1920, 1080);

    // creating holder
    holder = new QGraphicsRectItem;
    holder->setRect(0, 0, 1920, 1080);

    // creating and starting timer
    timer = new QTimer();
    timer->start(40);

    // adding scoreboard
    scoreBoard = new QGraphicsPixmapItem;
    scoreBoard->setPixmap(QPixmap(":/images/scoreboard.png"));
    scene->addItem(scoreBoard);
    scoreBoard->setPos(0, 0);

    // adding score
    controllerScore = new Score();
    scene->addItem(controllerScore);
    controllerScore->setPos(30, 0);

    // adding liveboard
    liveBoard = new QGraphicsPixmapItem;
    liveBoard->setPixmap(QPixmap(":/images/liveboard.png"));
    scene->addItem(liveBoard);
    liveBoard->setPos(0, 1020);

    // adding lives
    controllerLives = new Lives();
    scene->addItem(controllerLives);
    controllerLives->setPos(45, 1035);

    // creating spaceship and adding to scene and setting position
    spaceShip = new SpaceShip(holder);
    scene->addItem(spaceShip);
    spaceShip->setPos(885, 890);
}

// destructor
Controller::~Controller()
{
    // deleting pointers
    delete timer;
    delete scene;
    delete holder;
    delete scoreBoard;
    delete controllerScore;
    delete liveBoard;
    delete controllerLives;
    delete spaceShip;
}

// adding babychicken function
void Controller::addBabyChicken()
{
    // creating list of babychicken
    babychickenList.push_back(new BabyChicken(timer, holder));

    // adding to scene
    scene->addItem(babychickenList.last());
    babychickenList.last()->setPos(500,500);// set random
}

void Controller::addMeat()
{
    MeatList.push_back(new Meat(scene , controllerScore , timer ,holder));
}
