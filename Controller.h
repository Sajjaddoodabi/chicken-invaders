#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <Chicken.h>
#include <Meat.h>
#include <Score.h>
#include <SpaceShip.h>
#include <QMediaPlayer>

class Controller : public QObject
{
    // macro
    Q_OBJECT

    // add friend classes
    friend class Loading;
    friend class Menu;
    friend class View;
    friend class NewGameButton;
    friend class SpaceShip;

private:
    // private members
    QGraphicsScene * scene;
    QGraphicsPixmapItem *scoreBoard;
    Score *controllerScore;
    QTimer * timer;
    QGraphicsRectItem * holder;
    QMediaPlayer * media;

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
