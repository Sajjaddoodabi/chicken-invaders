#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QGraphicsScene>
#include "Babychichken.h"
#include "Score.h"
#include "Lives.h"

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

    QGraphicsPixmapItem * scoreBoard;
    Score * controllerScore;

    QGraphicsPixmapItem * liveBoard;
    Lives * controllerLives;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();

    // adding babychicken function
    void addBabyChicken(int velocity);
};

#endif // CONTROLLER_H
