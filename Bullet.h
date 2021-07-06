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

public:
    // constructor
    explicit Bullet(QTimer *bulletTimer, QMediaPlayer *bulletSound, QGraphicsItem *parent = nullptr);

    // add level and set picture
    void addLevel();

    // low-off level and set picture
    void lowOffLevel();

public slots:
    // move bullet to up
    void moveToUp();
};

#endif // BULLET_H
