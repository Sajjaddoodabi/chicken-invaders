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

    // add class view to friend
    friend class View;

private:
    // private members
    QGraphicsScene * scene;
    QGraphicsPixmapItem *scoreBoard;
    Score *controllerScore;
    QTimer * cTimer;
    QGraphicsRectItem * holder;
    //list of our enemyes
    QList<Chicken *> ChickenList;
    QList<Meat *> MeatList;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();

    void addChicken(int speed);
    void addMeat();

};

#endif // CONTROLLER_H
