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
    SaveBotton(QGraphicsScene *scene);


};

#endif // SAVEBOTTON_H
