#ifndef AFTERLEVEL_H
#define AFTERLEVEL_H
#include <QGraphicsView>
#include <QMediaPlayer>
#include "SaveButton.h"
#include "MainMenuButton.h"
#include "NextLevelButton.h"
#include "Menu.h"
#include "View.h"

class AfterLevel : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    int level;
    int season;
    QGraphicsScene * Scene;
    QMediaPlayer * Media;
    QTimer * Timer;
    Menu *menu;
    NextLevelButton * nextlevelButton;
    MainMenuButton * mainmenuButton;
    SaveButton * saveButton;
    View * view;

public:
    //constructor
    AfterLevel(int season , int level);

    //destructor
    ~AfterLevel();

public slots:
    void schedule();
};

#endif // AFTERLEVEL_H
