#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QGraphicsScene>
#include "Babychichken.h"
#include "Score.h"
#include "Lives.h"
#include "SpaceShip.h"
#include "Meat.h"

class Controller : public QObject
{
    // macro
    Q_OBJECT

    // adding friend classes
    friend class View;

private:
    // private members
    QGraphicsScene * scene;
    QTimer * timer;
    QGraphicsRectItem * holder;

    QList<BabyChicken *> babychickenList;
    int *countBabyChicken;
    QList<Meat *> MeatList;

    QGraphicsPixmapItem * scoreBoard;
    Score * controllerScore;

    QGraphicsPixmapItem * liveBoard;
    Lives * controllerLives;

    SpaceShip * spaceShip;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();

    // adding babychicken function
    void addBabyChicken(int x, int y, int a, int b);
    void addMeat();
 };

#endif // CONTROLLER_H
