#include "referee.h"
#include "core/base.h"

#include <QSet>
Referee::Referee(QObject *parent) : QObject(parent)
{
}
WinCode Referee::judge(const int &playerNum, const QVector<QVector<int>> &map) const
{

    if (vertical(playerNum, map) == Win || horizontal(playerNum, map) == Win || diagonalUp(playerNum, map) == Win ||
        diagonalDown(playerNum, map) == Win)
    {
        return Win;
    }

    return NotFinished;
}

WinCode Referee::vertical(const int &playerNum, const QVector<QVector<int>> &map) const
{
    WinCode winCode = NotFinished;

    // vertical
    for (int i = 1; i <= ROW_MAX - 4 + 1 && winCode == NotFinished; ++i)
        for (int j = 1; j <= COL_MAX && winCode == NotFinished; ++j)
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
                winCode = Win;
            }
        }

    return winCode;
}
WinCode Referee::horizontal(const int &playerNum, const QVector<QVector<int>> &map) const
{
    WinCode winCode = NotFinished;

    for (int i = 1; i <= ROW_MAX && winCode == NotFinished; ++i)
        for (int j = 1; j <= COL_MAX - 4 + 1 && winCode == NotFinished; ++j)
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
                winCode = Win;
            }
        }

    return winCode;
}
WinCode Referee::diagonalUp(const int &playerNum, const QVector<QVector<int>> &map) const
{
    WinCode winCode = NotFinished;
    QSet<QPair<int, int>> headList;

    for (int i = ROW_MAX; i - 3 >= 1; --i)
        for (int j = 1; j + 3 <= COL_MAX; ++j)
            headList.insert(QPair<int, int>(i, j));

    for (auto head : headList)
    {
        if (winCode == Win)
        {
            break;
        }
        int r = head.first;
        int c = head.second;
        WinCode tmp = Win;
        for (int i = 0; i < 4; ++i)
        {
            if (map[r - i][c + i] != playerNum)
            {
                tmp = NotFinished;
                break;
            }
        }
        if (tmp == Win)
            winCode = Win;
    }

    return winCode;
}
WinCode Referee::diagonalDown(const int &playerNum, const QVector<QVector<int>> &map) const
{
    WinCode winCode = NotFinished;
    QSet<QPair<int, int>> headList;

    for (int i = 1; i + 3 <= ROW_MAX; ++i)
        for (int j = 1; j + 3 <= COL_MAX; ++j)
            headList.insert(QPair<int, int>(i, j));

    for (auto head : headList)
    {
        if (winCode == Win)
        {
            break;
        }

        int r = head.first;
        int c = head.second;
        WinCode tmp = Win;
        for (int i = 0; i < 4; ++i)
        {
            if (map[r + i][c + i] != playerNum)
            {
                tmp = NotFinished;
                break;
            }
        }

        if (tmp == Win)
        {
            winCode = Win;
        }
    }

    return winCode;
}
