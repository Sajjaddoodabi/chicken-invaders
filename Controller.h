#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include "Chicken.h"
#include "Meat.h"
#include "Score.h"
#include "Lives.h"
#include "SpaceShip.h"

class Controller : public QObject
{
    // macro
    Q_OBJECT

    // add friend classes
    friend class Loading;
    friend class Menu;
    friend class View;
    friend class NewGameButton;

private:
    // private members
    QGraphicsScene * scene;
    QTimer * timer;
    QGraphicsRectItem * holder;
    QMediaPlayer * media;

    // create playerscore
    QGraphicsPixmapItem * scoreBoard;
    Score * controllerScore;

    // create playerlives
    QGraphicsPixmapItem * liveBoard;
    Lives * controllerLives;

    // create spaceship
    SpaceShip * spaceShip;

    // lists
    QList<Chicken *> ChickenList;
    QList<Meat *> MeatList;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();

    // to be (add chicken and meat in view)
    void addChicken(int speed , int Health , bool isLord);
    void addMeat();

};

#endif // CONTROLLER_H
