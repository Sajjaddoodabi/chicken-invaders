#ifndef AFTERLEVEL_H
#define AFTERLEVEL_H
#include <QGraphicsView>
#include <QMediaPlayer>
#include "SaveBotton.h"
#include "MainMenuBotton.h"
#include "NextLevelBotton.h"
#include "View.h"

class AfterLevel : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    QGraphicsScene * Scene;
    QMediaPlayer * Media;
    QTimer * Timer;
    NextLevelBotton * nextlevelButton;
    MainMenuBotton * mainmenuBotton;
    SaveBotton * saveButton;
    View * view;

public:
    //constructor
    AfterLevel();

    //destructor
    ~AfterLevel();

public slots:
    void schedule();
};

#endif // AFTERLEVEL_H
