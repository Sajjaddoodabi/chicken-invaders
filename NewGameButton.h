#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "View.h"

class NewGameButton : public QGraphicsPixmapItem
{
    // friend class
    friend class Menu;

private:
    // private members
    QGraphicsScene * buttonScene;
    View * view;
    int click;

public:
    // constructor
    explicit NewGameButton(QGraphicsScene *scene);

    // destructor
    ~NewGameButton();

    // muuse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NEWGAMEBUTTON_H
