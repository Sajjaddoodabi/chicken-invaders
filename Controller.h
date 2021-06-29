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

    QGraphicsPixmapItem *scoreBoard;
    Score *controllerScore;
    QTimer * cTimer;
    QGraphicsRectItem * holder;
    //list of our enemyes
    QList<Chicken *> ChickenList;
    QList<Meat *> MeatList;
    QMediaPlayer * media;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();

    void addChicken(int speed);
    void addMeat();

};

#endif // CONTROLLER_H
