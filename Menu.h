#ifndef MENU_H
#define MENU_H

#include <QGraphicsView>
#include "NewGameButton.h"
#include "Quitbutton.h"
#include "View.h"

class Menu : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    QGraphicsScene * mScene;
    QMediaPlayer * mMedia;
    QTimer * mTimer;
    NewGameButton * newGameButton;
    QuitButton * quitButton;
    View * view;

public:
    // constructor
    explicit Menu();

    // destructor
    ~Menu();

public slots:
    // restarting music and changing window
    void schedule();

};

#endif // MENU_H
