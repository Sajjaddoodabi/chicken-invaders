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
    MainMenuBotton(QGraphicsScene *scene);
};

#endif // MAINMENUBOTTON_H
