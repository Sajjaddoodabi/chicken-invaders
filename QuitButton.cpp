#include "Quitbutton.h"

// constructor
QuitButton::QuitButton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // create scene
    setPixmap(QPixmap(":/images/menu/quitbutton.jpg"));
    buttonScene->addItem(this);
    setPos(47, 938);
}

// destructor
QuitButton::~QuitButton()
{
    delete buttonScene;
    delete view;
}

// muuse event (click)
void QuitButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    click = 1;
    exit(0);
}
