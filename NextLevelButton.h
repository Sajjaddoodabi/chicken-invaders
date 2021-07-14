#ifndef NEXTLEVELBUTTON_H
#define NEXTLEVELBUTTON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class NextLevelButton : public QGraphicsPixmapItem
{
    friend class AfterLevel;
private:
    QGraphicsScene * buttonScene;
    QMediaPlayer * buttonMedia;
    int click;

public:
    //constructor
    NextLevelButton(QGraphicsScene *scene);

    //destructor
    ~NextLevelButton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // NEXTLEVELBUTTON_H