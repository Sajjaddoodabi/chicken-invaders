#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Controller.h"
#include "MainMenuButton.h"

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

    int ExitTime;

    QMediaPlayer *gameOverMusic;
    QMediaPlayer *winMusic;

    int deathTime;
    QTimer * deathTimer;
    QMediaPlayer * deathMedia;
    int ExitTime;
    int level;
public:
    // constructor
    explicit View();

    // destructor
    ~View();

    void mouseMoveEvent(QMouseEvent *event);
public slots:
    void death();
    void schedule();
};

#endif // VIEW_H
