#ifndef REFEREE_H
#define REFEREE_H

#include <QObject>

#include "core/base.h"

class Referee : public QObject
{
    Q_OBJECT

  public:
    explicit Referee(QObject *parent = nullptr);
    std::optional<PlayerId> judge(const BoardContainer &map) const;

  private:
    bool vertical(const PlayerId &playerNum, const BoardContainer &map) const;
    bool horizontal(const PlayerId &playerNum, const BoardContainer &map) const;
    bool diagonalUp(const PlayerId &playerNum, const BoardContainer &map) const;
    bool diagonalDown(const PlayerId &playerNum, const BoardContainer &map) const;
};

#endif // REFEREE_H
