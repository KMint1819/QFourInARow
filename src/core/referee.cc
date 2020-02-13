#include "referee.h"
#include "core/base.h"

#include <QSet>
Referee::Referee(QObject* parent)
    : QObject(parent)
    , LoggedClass("Referee")
{
    log->debug("Constructing referee...");
}
WinCode Referee::judge(int playerNum, QVector<QVector<int>> map)
{
    log->debug("Judging board...");

    if (vertical(playerNum, map) == Win || horizontal(playerNum, map) == Win || diagonal_up(playerNum, map) == Win || diagonal_down(playerNum, map) == Win) {
        log->debug("Player %v won.", playerNum);
        return Win;
    }

    return NotFinished;
}
WinCode Referee::vertical(int playerNum, QVector<QVector<int>> map)
{
    log->debug("judging board vertically for player %v...", playerNum);
    WinCode winCode = Lose;

    // vertical
    for (int i = 1; i <= ROW_MAX - 4 + 1 && winCode == Lose; ++i)
        for (int j = 1; j <= COL_MAX && winCode == Lose; ++j) {
            log->debug("Head: %v, %v", i, j);
            bool tmp = true;

            for (int k = 0; k < 4 && tmp; ++k) {
                if (map[i + k][j] != playerNum) {
                    tmp = false;
                }
            }

            if (tmp == true) {
                winCode = Win;
                log->debug("Win!");
            }
        }

    log->debug("============================================");
    return winCode;
}
WinCode Referee::horizontal(int playerNum, QVector<QVector<int>> map)
{
    log->debug("judging board horizontally...");
    WinCode winCode = Lose;

    for (int i = 1; i <= ROW_MAX && winCode == Lose; ++i)
        for (int j = 1; j <= COL_MAX - 4 + 1 && winCode == Lose; ++j) {
            bool tmp = true;
            log->debug("Head: %v, %v", i, j);

            for (int k = 0; k < 4 && tmp; ++k) {
                if (map[i][j + k] != playerNum) {
                    tmp = false;
                }
            }

            if (tmp == true) {
                winCode = Win;
                log->debug("Win!");
            }
        }

    log->debug("============================================");
    return winCode;
}
WinCode Referee::diagonal_up(int playerNum, QVector<QVector<int>> map)
{
    log->debug("judging board diagonally up...");
    WinCode winCode = Lose;
    QSet<QPair<int, int>> judgeHeadList;

    for (int i = ROW_MAX; i - 3 >= 1; --i) {
        judgeHeadList.insert(QPair<int, int>(i, 1));
    }

    for (int i = 1; i + 3 <= COL_MAX; ++i) {
        judgeHeadList.insert(QPair<int, int>(1, i));
    }

    for (auto startPoint : judgeHeadList) {
        if (winCode == Win) {
            break;
        }

        QPair<int, int> head = startPoint;

        for (int i = 0; head.first + i + 3 <= ROW_MAX && head.second + i + 3 < COL_MAX; ++i) {
            if (winCode == Win) {
                break;
            }

            head = QPair<int, int>(head.first + i, head.second + i);
            WinCode tmp = Win;

            for (int j = 0; j < 4; ++j) {
                if (map[head.first + i][head.second + i] != playerNum) {
                    tmp = Lose;
                }
            }

            winCode = tmp;
        }
    }

    log->debug("============================================");
    return winCode;
}
WinCode Referee::diagonal_down(int playerNum, QVector<QVector<int>> map)
{
    log->debug("judging board diagonally down...");
    WinCode winCode = NotFinished;
    QSet<QPair<int, int>> judgeHeadList;

    for (int i = 1; i + 3 <= ROW_MAX; ++i) {
        judgeHeadList.insert(QPair<int, int>(i, 1));
    }

    for (int i = 1; i + 3 <= COL_MAX; ++i) {
        judgeHeadList.insert(QPair<int, int>(1, i));
    }

    log->debug("Initial judgeHeadList:");

    for (auto i : judgeHeadList) {
        log->debug("(%v, %v)", i.first, i.second);
    }

    for (auto head : judgeHeadList) {
        for (int i = 0; head.first + i + 3 <= ROW_MAX && head.second + i + 3 < COL_MAX; ++i) {
            judgeHeadList.insert(QPair<int, int>(head.first + i, head.second + i));
        }
    }

    log->debug("Preprocessed judgeHeadList:");

    for (auto i : judgeHeadList) {
        log->debug("(%v, %v)", i.first, i.second);
    }

    // Start judge
    for (auto head : judgeHeadList) {
        if (winCode == Win) {
            break;
        }

        bool allPass = true;
        log->debug("Head: %v, %v", head.first, head.second);

        for (int i = 0; i < 4; ++i) {
            if (map[head.first + i][head.second + i] != playerNum) {
                allPass = false;
                break;
            }
        }

        if (allPass) {
            winCode = Win;
            log->debug("Win!");
        }
    }

    log->debug("============================================");
    return winCode;
}
