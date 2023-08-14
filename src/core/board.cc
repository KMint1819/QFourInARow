#include "board.h"

Board::Board(QObject *parent) : QAbstractListModel(parent)
{
    m_map.resize(ROW_MAX + 1);

    for (int i = 1; i <= ROW_MAX; ++i)
    {
        m_map[i].resize(COL_MAX + 1);
    }
}

int Board::rowCount(const QModelIndex &parent) const
{
    return ROW_MAX;
}

int Board::columnCount(const QModelIndex &parent) const
{
    return COL_MAX;
}

QVariant Board::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_map[index.row() + 1][index.column() + 1];
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
