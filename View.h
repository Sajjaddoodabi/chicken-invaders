#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>

class View : public QGraphicsView
{
    Q_OBJECT

private:
    //members class
    QGraphicsScene *scene;

public:
    //constructor
    explicit View();

signals:

public slots:

};

#endif // VIEW_H
