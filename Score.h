#ifndef SCORE_H
#define SCORE_H

#include <QObject>

class Score : public QObject
{
    Q_OBJECT
private:
    int playerScore;
public:
    explicit Score(QObject *parent = nullptr);

signals:

};

#endif // SCORE_H
