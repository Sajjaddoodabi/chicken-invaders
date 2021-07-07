#ifndef NEWGAMEBUTTON_H
#define NEWGAMEBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QGraphicsScene>

class NewGameButton : public QGraphicsPixmapItem
{
    // friend class
    friend class Menu;

private:
    // private members
    QGraphicsScene * buttonScene;
    QMediaPlayer * buttonMedia;
    int click;

public:
    // constructor
    explicit NewGameButton(QGraphicsScene *scene);

    // destructor
    ~NewGameButton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // NEWGAMEBUTTON_H
