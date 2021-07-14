#ifndef MAINMENUBUTTON_H
#define MAINMENUBUTTON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class MainMenuButton : public QGraphicsPixmapItem
{
    friend class AfterLevel;
private:
    QGraphicsScene * buttonScene;
    QMediaPlayer * buttonMedia;
    int click;

public:
    //constructor
    MainMenuButton(QGraphicsScene *scene);

    //destructor
    ~MainMenuButton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MAINMENUBUTTON_H
