#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>

class Chicken : public QObject
{
    Q_OBJECT
public:
    explicit Chicken(QObject *parent = nullptr);

signals:

};

#endif // CHICKEN_H
