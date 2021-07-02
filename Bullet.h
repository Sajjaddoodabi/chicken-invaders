#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    int level;
    int x;
    int y;

public:
    // constructor
    explicit Bullet(QGraphicsItem *parent, QTimer *bulletTimer, QMediaPlayer *bulletSound, int x, int y);

    // add level and set picture
    void addLevel();

    // low-off level and set picture
    void lowOffLevel();

public slots:
    // move bullet to up
    void moveToUp();
};

#endif // BULLET_H
