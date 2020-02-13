#include "board.h"

Board::Board(QObject* parent, QString player1, QString player2, QQuickView* view)
    : QObject(parent)
    , LoggedClass("Board")
    , m_view(view)
    , player1(player1)
    , player2(player2)
    , ref(parent)
{
    log->debug("Constructing board...");
    QObject* root = qobject_cast<QObject*>(view->rootObject());
    QObject::connect(root, SIGNAL(putSignal(QVariant, QVariant)),
        this, SLOT(put(QVariant, QVariant)));
    m_map.resize(ROW_MAX + 1);

    for (int i = 1; i <= ROW_MAX; ++i) {
        m_map[i].resize(COL_MAX + 1);
    }

    col_height.resize(COL_MAX + 1);
    log->info("Board constructed");
}
QVector<QVector<int>> Board::getMap2d()
{
    return m_map;
}
void Board::setMap1d(QVector<int> map1d)
{
    int p = 0;
    for (int i = 1; i <= ROW_MAX; ++i) {
        for (int j = 1; j <= COL_MAX; ++j) {
            m_map[i][j] = map1d[p++];
        }
    }
    emit mapChanged();
}
QVector<int> Board::getMap1d()
{
    QVector<int> output(ROW_MAX * COL_MAX);
    int p = 0;

    for (int i = 1; i <= m_map.size(); ++i)
        for (int j = 1; j <= m_map.size(); ++j) {
            output[p++] = m_map[i][j];
        }

    return output;
}
QPair<QString, QString> Board::getPlayerName()
{
    return QPair<QString, QString>(player1, player2);
}
StatusCode Board::put(int playerNum, int col)
{
    log->info("Putting %v to column %v", playerNum, col);

    if (col_height[col] >= ROW_MAX) {
        log->warn("Put failed");
        return Fail;
    }

    m_map[ROW_MAX - col_height[col]][col] = playerNum;
    col_height[col]++;
    log->debug("Put succeed!");

    if (ref.judge(playerNum, m_map)) {
        winner = playerNum;
    }
    return Success;
}
void Board::clear()
{
    col_height.clear();
    m_map.clear();

    for (int i = 1; i <= 7; ++i) {
        m_map[i].clear();
    }

    log->debug("m_map cleared");
    print_sep();
}
void Board::print()
{
    log->debug("Printing board");

    for (int i = 1; i <= ROW_MAX; ++i) {
        QString tmp;

        for (int j = 1; j <= COL_MAX; ++j) {
            tmp.push_back(QString::number(m_map[i][j]));
        }

        log->info("%v", tmp.toStdString());
    }

    print_sep();
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
