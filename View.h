#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Controller.h"
#include "MainMenuButton.h"
#include "Score.h"

class View : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    Controller * vController;
    QMediaPlayer * vMedia;
    QTimer * vTimer;
    int vTime;

    QMediaPlayer *gameOverMusic;
    QMediaPlayer *winMusic;

    int deathTime;
    QTimer * deathTimer;
    QMediaPlayer * deathMedia;

    Score *score;

    MainMenuButton *mainmenuButton = nullptr;

    bool is;
public:
    // constructor
    explicit View();

    // destructor
    ~View();

    void mouseMoveEvent(QMouseEvent *event);
    void stopGame();

public slots:
    void death();
    void schedule();
};

#endif // VIEW_H
