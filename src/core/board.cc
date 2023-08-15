#include "board.h"

Board::Board(QObject *parent) : QAbstractListModel(parent)
{
    m_map.resize(ROW_MAX + 1);

    for (int i = 0; i <= ROW_MAX; ++i)
    {
        m_map[i].resize(COL_MAX + 1);
    }
    m_map[1][1] = 1;
    m_map[ROW_MAX][COL_MAX] = 2;
}

int Board::rowCount(const QModelIndex &) const
{
    return ROW_MAX * COL_MAX;
}

QVariant Board::data(const QModelIndex &index, int role) const
{
    int r = index.row() / COL_MAX + 1;
    int c = index.row() % COL_MAX + 1;

    if (role == Qt::DisplayRole)
    {
        return m_map[r][c];
    }
    return QVariant();
}

void Board::onPut(const PlayerId &playerNum, const int &col)
{
    bool success = false;
    for (int i = 1; i <= COL_MAX; i++)
    {
        if (m_map[i][col] == 0)
        {
            m_map[i][col] = playerNum;
            success = true;
            break;
        }
    }
    if (!success)
    {
        qDebug() << "Column is full";
        return;
    }

    std::optional<PlayerId> winner = m_ref.judge(m_map);
    if (winner.has_value())
    {
        emit updateSignal(m_map, winner.value());
        return;
    }
    updateSignal(m_map, 0);
}

void Board::onRestart()
{
    for (int i = 1; i <= ROW_MAX; i++)
    {
        std::fill(m_map[i].begin(), m_map[i].end(), 0);
    }
    emit updateSignal(m_map, 0);
}
