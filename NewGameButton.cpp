#include "NewGameButton.h"

NewGameButton::NewGameButton(QGraphicsScene *scene) :  QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // create scene
    setPixmap(QPixmap(":/images/menu/newgame.jpg"));
    buttonScene->addItem(this);
    setPos(790, 610);
}

NewGameButton::~NewGameButton()
{
    delete buttonScene;
    delete view;
}

void NewGameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    click = 1;
    view = new View;
    view->show();
}
