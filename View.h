#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>

class View : public QGraphicsView
{
    Q_OBJECT

private:
    //members class
    QGraphicsScene *scene;
    QTimer *viewTimer;
    double viewTime;

public:
    //constructor
    explicit View();

signals:

public slots:
    void background();

};

#endif // VIEW_H
