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
    //constructor
    NextLevelBotton(QGraphicsScene *scene);

    //destructor
    ~NextLevelBotton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // NEXTLEVELBOTTON_H
