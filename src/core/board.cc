#include "board.h"

Board::Board(QObject *parent, QString player1, QString player2, QQmlApplicationEngine &engine)
    : QObject(parent), engine(&engine), player1(player1), player2(player2), ref(parent)
{
    engine.rootContext()->setContextProperty("board", this);

    m_map.resize(ROW_MAX + 1);

    for (int i = 1; i <= ROW_MAX; ++i)
    {
        m_map[i].resize(COL_MAX + 1);
    }

    col_height.resize(COL_MAX + 1);
}
QVector<QVector<int>> Board::getMap2d() const
{
    return m_map;
}
QVector<int> Board::getMap1d() const
{
    QVector<int> output(ROW_MAX * COL_MAX);
    int p = 0;

    for (int i = 1; i <= ROW_MAX; ++i)
        for (int j = 1; j <= COL_MAX; ++j)
        {
            output[p++] = m_map[i][j];
        }

    return output;
}
QVector<QString> Board::getPlayerName() const
{
    QVector<QString> names(2);
    names[0] = player1;
    names[1] = player2;
    return names;
}
bool Board::put(const int &playerNum, const int &col)
{

    if (col_height[col] >= ROW_MAX)
    {
        return false;
    }

    m_map[ROW_MAX - col_height[col]][col] = playerNum;
    col_height[col]++;
    counter++;

    if (ref.judge(playerNum, m_map))
    {
        winner = playerNum;
    }
    if (counter >= COL_MAX * ROW_MAX)
    {
        winner = -100;
    }
    return true;
}
void Board::clear()
{
    winner = 0;
    counter = 0;
    m_map.clear();
    m_map.resize(ROW_MAX + 1);
    for (int i = 1; i <= ROW_MAX; ++i)
    {
        m_map[i].resize(COL_MAX + 1);
    }

    col_height.clear();
    col_height.resize(COL_MAX + 1);
}
void Board::print() const
{

    for (int i = 1; i <= ROW_MAX; ++i)
    {
        QString tmp;

        for (int j = 1; j <= COL_MAX; ++j)
        {
            tmp.push_back(QString::number(m_map[i][j]));
        }
    }
}
int Board::getWinner() const
{
    return winner;
}
void Board::test()
{
    print();
    put(1, 3);
    put(2, 4);
    print();
}
