#ifndef HEN_H
#define HEN_H

#include <QObject>

class Hen : public QObject
{
    Q_OBJECT
public:
    explicit Hen(QObject *parent = nullptr);

signals:

};

#endif // HEN_H
