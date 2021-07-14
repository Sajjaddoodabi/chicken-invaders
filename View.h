#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Controller.h"
#include "MainMenuButton.h"
#include "NextLevelButton.h"
#include "SaveButton.h"

class View : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    int level;
    int season;

    Controller * vController;
    QMediaPlayer * vMedia;
    QTimer * vTimer;
    int vTime;

    QMediaPlayer *gameOverMusic;
    QMediaPlayer *winMusic;

    int deathTime;
    QTimer * deathTimer;
    QMediaPlayer * deathMedia;

    MainMenuButton *mainmenuButton;
    NextLevelButton *nextlevelButton;
    SaveButton *saveButton;

public:
    // constructor
    explicit View(int season , int level);

    // destructor
    ~View();

    void mouseMoveEvent(QMouseEvent *event);
    void stopGame();

public slots:
    // showing animated background
    void animatedBackground();
    void death();
    void schedule();
};

#endif // VIEW_H
