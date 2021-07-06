#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
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

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NEWGAMEBUTTON_H
