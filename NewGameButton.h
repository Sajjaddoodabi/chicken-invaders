#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Controller.h"

class NewGameButton : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    Controller * buttonController;

public:
    // constructor
    explicit NewGameButton();

    // destructor
    ~NewGameButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NEWGAMEBUTTON_H
