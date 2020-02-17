#include "board.h"

Board::Board(QObject* parent, QString player1, QString player2, QQmlApplicationEngine& engine)
    : QObject(parent)
    , LoggedClass("Board")
    , engine(&engine)
    , player1(player1)
    , player2(player2)
    , ref(parent)
{
    log->debug("Constructing board...");
    engine.rootContext()->setContextProperty("board", this);

    m_map.resize(ROW_MAX + 1);

    for (int i = 1; i <= ROW_MAX; ++i) {
        m_map[i].resize(COL_MAX + 1);
    }

    col_height.resize(COL_MAX + 1);
    log->info("Board constructed");
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
        for (int j = 1; j <= COL_MAX; ++j) {
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
bool Board::put(const int& playerNum, const int& col)
{
    log->info("Putting %v to column %v", playerNum, col);

    if (col_height[col] >= ROW_MAX) {
        log->debug("Board::put failed due to position is occupied.");
        return false;
    }

    m_map[ROW_MAX - col_height[col]][col] = playerNum;
    col_height[col]++;
    counter++;
    log->debug("Put succeed!");

    if (ref.judge(playerNum, m_map)) {
        winner = playerNum;
    }
    if (counter >= COL_MAX * ROW_MAX) {
        winner = -100;
        log->info("The board is full!!");
    }
    return true;
}
void Board::clear()
{
    winner = 0;
    counter = 0;
    m_map.clear();
    m_map.resize(ROW_MAX + 1);
    for (int i = 1; i <= ROW_MAX; ++i) {
        m_map[i].resize(COL_MAX + 1);
    }

    col_height.clear();
    col_height.resize(COL_MAX + 1);
    log->debug("m_map cleared");
    printSep();
}
void Board::print() const
{
    log->debug("Printing board");

    for (int i = 1; i <= ROW_MAX; ++i) {
        QString tmp;

        for (int j = 1; j <= COL_MAX; ++j) {
            tmp.push_back(QString::number(m_map[i][j]));
        }
        log->info("%v", tmp.toStdString());
    }

    printSep();
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
    log->info("Ok");
}
