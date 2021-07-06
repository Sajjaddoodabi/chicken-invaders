#include "NewGameButton.h"

// constructor
NewGameButton::NewGameButton(QGraphicsScene *scene) :  QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/newgamebutton.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(665, 603);
}

// destructor
NewGameButton::~NewGameButton()
{
    // deleting pointers
    delete buttonScene;
    delete view;
}

// muuse event (click)
void NewGameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // creating view
    view = new View();

    // showing view's window
    view->show();
}
