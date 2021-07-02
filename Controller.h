#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <Chicken.h>
#include <Meat.h>
#include <Score.h>
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

private:
    // private members
    QGraphicsScene * scene;
    QTimer * timer;
    QGraphicsRectItem * holder;
    QMediaPlayer * media;
    QGraphicsPixmapItem * scoreBoard;
    Score * controllerScore;
    QGraphicsPixmapItem * liveBoard;

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
