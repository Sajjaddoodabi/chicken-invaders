#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include "NewGameButton.h"
#include "Quitbutton.h"
#include "Controller.h"

class Menu : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    Controller * menuController;
    NewGameButton * newGameButton;
    QuitButton * quitButton;

public:
    // constructor
    explicit Menu();

    // destructor
    ~Menu();

public slots:
    void schedule();

};

#endif // MENU_H
