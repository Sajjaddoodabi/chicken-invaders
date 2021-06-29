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
    Controller * viewController;
    int viewTime;

public:
    // constructor
    explicit View();

    // destructor
    ~View();

public slots:
    // show animated background
    void animatedBackground();

};

#endif // VIEW_H
