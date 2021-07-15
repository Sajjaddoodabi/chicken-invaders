#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Controller.h"
#include "MainMenuButton.h"
#include "NextLevelButton.h"

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

    MainMenuButton *mainmenuButton = nullptr;
    NextLevelButton *nextlevelButton;

    bool is;
public:
    // constructor
    explicit View(int season , int level);

    // destructor
    ~View();

    void mouseMoveEvent(QMouseEvent *event);
    void stopGame();

public slots:
    void death();
    void schedule();
};

#endif // VIEW_H
