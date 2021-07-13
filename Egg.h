#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>

class Egg : public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *EggScene;
    QTimer *timer;

public:
     Egg(QObject *parent = nullptr);

signals:

};

#endif // EGG_H
