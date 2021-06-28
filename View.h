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
    // show background
    void background();

};

#endif // VIEW_H
