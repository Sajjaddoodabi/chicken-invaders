#ifndef QUITBUTTON_H
#define QUITBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>
#include <QGraphicsScene>

class QuitButton : public QGraphicsPixmapItem
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
    explicit QuitButton(QGraphicsScene *scene);

    // destructor
    ~QuitButton();

    // muuse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // QUITBUTTON_H
