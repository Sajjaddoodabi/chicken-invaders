#include "Quitbutton.h"

// constructor
QuitButton::QuitButton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/quitbutton.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(47, 938);
}

// destructor
QuitButton::~QuitButton()
{
    // deleting pointers
    delete buttonScene;
    delete view;
}

// muuse event (click)
void QuitButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // exiting the game
    exit(0);
}
