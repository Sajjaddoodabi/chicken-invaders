#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>

class Egg : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsScene *EggScene;

public:
    Egg(QGraphicsScene *EggScene , QTimer *timer , QGraphicsItem *parent = nullptr);

public slots:
    // move down
    void move();

};

#endif // EGG_H
