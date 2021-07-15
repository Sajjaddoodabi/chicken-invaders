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
    connect(timer, SIGNAL(timeout()), this, SLOT(shootEgg()));
    timer->start(5000);

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

    countChicken = new int();
    *countChicken = 0;

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
void Controller::addBabyChicken(int x, int y, int a, int b)
{
    // creating list of babychicken
    babychickenList.push_back(new BabyChicken(controllerScore,countChicken , a, b, holder));

    // adding to scene
    scene->addItem(babychickenList.last());
    babychickenList.last()->setPos(x, y);

    *countChicken += 1;
}

void Controller::addChicken(int x, int y, int a, int b, bool isLord)
{
    // creating list of babychicken
    chickenList.push_back(new Chicken(controllerScore, countChicken , a, b, isLord, holder));

    // adding to scene
    scene->addItem(chickenList.last());
    chickenList.last()->setPos(x, y);

    *countChicken += 1;
}

void Controller::shootEgg()
{
       // to do
}
