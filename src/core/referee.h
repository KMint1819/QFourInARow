#ifndef REFEREE_H
#define REFEREE_H

#include <QObject>

#include "core/base.h"
#include "core/board.h"
class Referee : public QObject, public LoggedClass
{
    Q_OBJECT
public:
    explicit Referee(QObject* parent = nullptr);
    WinCode judge(int playerNum, Board* board);
private:
    WinCode vertical(int playerNum, QVector<QVector<int>> map);
    WinCode horizontal(int playerNum, QVector<QVector<int>> map);
    WinCode diagonal_up(int playerNum, QVector<QVector<int>> map);
    WinCode diagonal_down(int playerNum, QVector<QVector<int>> map);
signals:

public slots:
};

#endif // REFEREE_H
