#include "referee.h"
#include "core/base.h"

#include <QSet>
Referee::Referee(QObject *parent) : QObject(parent)
{
}
std::optional<PlayerId> Referee::judge(const BoardContainer &map) const
{
    if (vertical(1, map) || horizontal(1, map) || diagonalUp(1, map) || diagonalDown(1, map))
    {
        return 1;
    }
    else if (vertical(2, map) || horizontal(2, map) || diagonalUp(2, map) || diagonalDown(2, map))
    {
        return 2;
    }
    return std::nullopt;
}

bool Referee::vertical(const PlayerId &playerNum, const BoardContainer &map) const
{
    bool has_won = false;

    // vertical
    for (int i = 0; i < ROW_MAX - 4 + 1 && has_won == false; ++i)
        for (int j = 0; j < COL_MAX && has_won == false; ++j)
        {
            bool tmp = true;

            for (int k = 0; k < 4 && tmp; ++k)
            {
                if (map[i + k][j] != playerNum)
                {
                    tmp = false;
                }
            }

            if (tmp == true)
            {
                has_won = true;
            }
        }

    return has_won;
}
bool Referee::horizontal(const PlayerId &playerNum, const BoardContainer &map) const
{
    bool has_won = false;

    for (int i = 0; i < ROW_MAX && has_won == false; ++i)
        for (int j = 0; j < COL_MAX - 4 + 1 && has_won == false; ++j)
        {
            bool tmp = true;

            for (int k = 0; k < 4 && tmp; ++k)
            {
                if (map[i][j + k] != playerNum)
                {
                    tmp = false;
                }
            }

            if (tmp == true)
            {
                has_won = true;
            }
        }

    return has_won;
}
bool Referee::diagonalUp(const PlayerId &playerNum, const BoardContainer &map) const
{
    bool has_won = false;
    QSet<QPair<int, int>> headList;

    for (int i = ROW_MAX - 1; i - 3 >= 0; --i)
        for (int j = 0; j + 3 < COL_MAX; ++j)
            headList.insert(QPair<int, int>(i, j));

    for (auto head : headList)
    {
        if (has_won == true)
        {
            break;
        }
        int r = head.first;
        int c = head.second;
        bool tmp = true;
        for (int i = 0; i < 4; ++i)
        {
            if (map[r - i][c + i] != playerNum)
            {
                tmp = false;
                break;
            }
        }
        if (tmp == true)
            has_won = true;
    }

    return has_won;
}
bool Referee::diagonalDown(const PlayerId &playerNum, const BoardContainer &map) const
{
    bool has_won = false;
    QSet<QPair<int, int>> headList;

    for (int i = 0; i + 3 < ROW_MAX; ++i)
        for (int j = 0; j + 3 < COL_MAX; ++j)
            headList.insert(QPair<int, int>(i, j));

    for (auto head : headList)
    {
        if (has_won == true)
        {
            break;
        }

        int r = head.first;
        int c = head.second;
        bool tmp = true;
        for (int i = 0; i < 4; ++i)
        {
            if (map[r + i][c + i] != playerNum)
            {
                tmp = false;
                break;
            }
        }

        if (tmp == true)
        {
            has_won = true;
        }
    }

    return has_won;
}
