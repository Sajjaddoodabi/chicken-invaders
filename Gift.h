#ifndef GIFT_H
#define GIFT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Gift : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QGraphicsScene * GiftScene;
    int timeIntervals;
public:
    Gift(QGraphicsScene *GiftScene , QTimer *timer , QGraphicsItem *parent = nullptr);
    ~Gift();

public slots:
    // move down
    void move();
};

#endif // GIFT_H
