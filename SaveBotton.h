#ifndef SAVEBOTTON_H
#define SAVEBOTTON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class SaveBotton : public QGraphicsPixmapItem
{
    friend class AfterLevel;
private:
    QGraphicsScene * buttonScene;
    QMediaPlayer * buttonMedia;
    int click;

public:
    //constructor
    SaveBotton(QGraphicsScene *scene);

    //destructor
    ~SaveBotton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // SAVEBOTTON_H
