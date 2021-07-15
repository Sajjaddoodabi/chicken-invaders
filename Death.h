#ifndef DEATH_H
#define DEATH_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Death : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    QTimer * dTimer;
    int dTime;

public:
    // constructor
    Death();

public slots:
    void animated();
};

#endif // DEATH_H
