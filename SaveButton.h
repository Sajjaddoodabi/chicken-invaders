#ifndef SAVEBUTTON_H
#define SAVEBUTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class SaveButton : public QGraphicsPixmapItem
{
    friend class AfterLevel;
private:
    QGraphicsScene * buttonScene;
    QMediaPlayer * buttonMedia;
    int click;

public:
    //constructor
    SaveButton(QGraphicsScene *scene);

    //destructor
    ~SaveButton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SAVEBUTTON_H
