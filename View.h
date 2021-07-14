#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include "Controller.h"

class View : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    Controller * vController;
    QMediaPlayer * vMedia;
    QTimer * vTimer;
    int vTime;

public:
    // constructor
    explicit View();

    // destructor
    ~View();

    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // showing animated background
    void animatedBackground();
};

#endif // VIEW_H
