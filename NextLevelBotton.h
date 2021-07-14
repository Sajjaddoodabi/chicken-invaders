#ifndef NEXTLEVELBOTTON_H
#define NEXTLEVELBOTTON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class NextLevelBotton : public QGraphicsPixmapItem
{
    friend class AfterLevel;
private:
    QGraphicsScene * buttonScene;
    QMediaPlayer * buttonMedia;
    int click;

public:
    NextLevelBotton(QGraphicsScene *scene);
};

#endif // NEXTLEVELBOTTON_H
