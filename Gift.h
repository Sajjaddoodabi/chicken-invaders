#ifndef GIFT_H
#define GIFT_H

#include <QObject>
#include <QTimer>

class Gift : public QObject
{
    Q_OBJECT
public:
    explicit Gift(QObject *parent = nullptr);

signals:

};

#endif // GIFT_H
