#ifndef BABYCHICKEN_H
#define BABYCHICKEN_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class babyChicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int Health;
    int speedPerPix;
    QMediaPlayer *BabyChickenSound;
public:
    bool gameOver;
    babyChicken(int speedPerPix, QTimer *timer , QGraphicsItem *parent , int Healt);
};

#endif // BABYCHICKEN_H
