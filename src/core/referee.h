#ifndef REFEREE_H
#define REFEREE_H

#include <QObject>

#include "core/base.h"

class Referee : public QObject
{

    Q_OBJECT
  public:
    explicit Referee(QObject *parent = nullptr);
    WinCode judge(const int &playerNum, const QVector<QVector<int>> &map) const;

  private:
    WinCode vertical(const int &playerNum, const QVector<QVector<int>> &map) const;
    WinCode horizontal(const int &playerNum, const QVector<QVector<int>> &map) const;
    WinCode diagonalUp(const int &playerNum, const QVector<QVector<int>> &map) const;
    WinCode diagonalDown(const int &playerNum, const QVector<QVector<int>> &map) const;
};

#endif // REFEREE_H
