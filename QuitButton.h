#ifndef QUITBUTTON_H
#define QUITBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include "View.h"

class QuitButton : public QGraphicsPixmapItem
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
    explicit QuitButton(QGraphicsScene *scene);

    // destructor
    ~QuitButton();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // QUITBUTTON_H
