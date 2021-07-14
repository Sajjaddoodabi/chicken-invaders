#ifndef MAINMENUBOTTON_H
#define MAINMENUBOTTON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class MainMenuBotton : public QGraphicsPixmapItem
{
    friend class AfterLevel;
private:
    QGraphicsScene * buttonScene;
    QMediaPlayer * buttonMedia;
    int click;

public:
    //constructor
    MainMenuBotton(QGraphicsScene *scene);

    //destructor
    ~MainMenuBotton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MAINMENUBOTTON_H
