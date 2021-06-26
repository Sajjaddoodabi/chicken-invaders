#include "Menu.h"

// constructor
Menu::Menu() : QGraphicsView()
{
    // create controller
    menuController = new Controller;

    // add scene
    setScene(menuController->scene);

    // fullsceenig the game window
    setWindowState(Qt::WindowFullScreen);

    // delete scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/menu.jpeg")));
}

// destructor
Menu::~Menu()
{
    delete menuController;
}

