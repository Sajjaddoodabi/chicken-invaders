#ifndef NEXTLEVELBUTTON_H
#define NEXTLEVELBUTTON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class NextLevelButton : public QGraphicsPixmapItem
{
    friend class AfterLevel;
private:
    QMediaPlayer * buttonMedia;
    int click;
    int season;
    int level;

public:
    //constructor
    NextLevelButton(int season , int level);

    //destructor
    ~NextLevelButton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // NEXTLEVELBUTTON_H
