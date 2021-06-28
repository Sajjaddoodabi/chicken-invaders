#include "Quitbutton.h"

QuitButton::QuitButton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // create scene
    setPixmap(QPixmap(":/images/menu/quitbutton.jpg"));
    buttonScene->addItem(this);
    setPos(225, 950);
}

QuitButton::~QuitButton()
{
    delete buttonScene;
    delete view;
}

void QuitButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    click = 1;
    exit(0);
}
