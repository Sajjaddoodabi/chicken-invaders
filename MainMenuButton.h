#ifndef MAINMENUBUTTON_H
#define MAINMENUBUTTON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>

class MainMenuButton : public QGraphicsPixmapItem
{
    friend class View;
private:
    QMediaPlayer * buttonMedia;
    int click;

public:
    //constructor
    MainMenuButton();

    //destructor
    ~MainMenuButton();

    // mouse event (click)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MAINMENUBUTTON_H
