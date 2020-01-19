#include "board.h"

#include <QDebug>

#include "base.h"

Board::Board(QObject* parent, QString player1, QString player2)
    : QObject(parent),
      LoggedClass("Board"),
      player1(player1),
      player2(player2)
{
    log->debug("Logger ok");
    map.resize(ROW_MAX + 1);

    for (int i = 1 ; i <= ROW_MAX; ++ i)
        map[i].resize(COL_MAX + 1);

    col_height.resize(COL_MAX + 1);
}
QVector<QVector<int>>* Board::getMap()
{
    return &map;
}
QPair<QString, QString> Board::getPlayerName()
{
    return QPair<QString, QString>(player1, player2);
}
StatusCode Board::put(int playerNum, int col)
{
    log->debug("Putting %v to column %v", playerNum, col);
    log->debug("Size of col_height: %v", col_height.size());
    log->debug("col_height[col] = %v", col_height[col]);

    if (col_height[col] >= ROW_MAX)
    {
        log->debug("Put failed");
        return Fail;
    }

    map[ROW_MAX - col_height[col]][col] = playerNum;
    col_height[col] ++;
    log->debug("Put succeed!");
    return Success;
}
void Board::clear()
{
    col_height.clear();
    map.clear();

    for (int i = 1; i <= 7; ++ i)
        map[i].clear();

    log->debug("Map cleared");
    print_sep();
}
void Board::print()
{
    log->debug("Printing board");

    for (int i = 1 ; i <= ROW_MAX ; ++ i)
    {
        QString tmp;

        for (int j = 1; j <= COL_MAX ; ++ j)
        {
            tmp.push_back(QString::number(map[i][j]));
        }

        log->info("%v", tmp.toStdString());
    }

    print_sep();
}
void Board::setWinner(int a)
{
    winner = a;
}
int Board::getWinner()
{
    return winner;
}
void Board::test()
{
    print();
    put(1, 3);
    put(2, 4);
    print();
    log->info("Ok");
}
