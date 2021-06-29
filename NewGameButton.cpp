#include "NewGameButton.h"

// constructor
NewGameButton::NewGameButton(QGraphicsScene *scene) :  QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // create scene
    setPixmap(QPixmap(":/images/menu/newgamebutton.jpg"));
    buttonScene->addItem(this);
    setPos(665, 603);
}

// destructor
NewGameButton::~NewGameButton()
{
    delete buttonScene;
    delete view;
}

// muuse event (click)
void NewGameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    click = 1;
    view = new View;
    view->show();
}
