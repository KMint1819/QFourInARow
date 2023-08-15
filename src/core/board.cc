#include "board.h"

Board::Board(QObject *parent) : QAbstractListModel(parent)
{
    m_map.resize(ROW_MAX);

    for (int i = 0; i < ROW_MAX; ++i)
    {
        m_map[i].resize(COL_MAX);
    }
    m_map[0][0] = 1;
    m_map[ROW_MAX - 1][COL_MAX - 1] = 2;
}

int Board::rowCount(const QModelIndex &) const
{
    return ROW_MAX * COL_MAX;
}

QVariant Board::data(const QModelIndex &index, int role) const
{
    // Returning the map reversely
    int r = index.row() / COL_MAX;
    int c = index.row() % COL_MAX;
    qDebug("Getting data at %d,%d: %d", r, c, m_map[r][c]);

    if (role == Qt::DisplayRole)
    {
        return m_map[r][c];
    }
    return QVariant();
}

void Board::onPut(const PlayerId &playerNum, const int &col)
{
    qDebug("onPut: %d, %d", playerNum, col);
    bool success = false;
    for (int i = 0; i < COL_MAX; i++)
    {
        if (m_map[i][col] == 0)
        {
            m_map[i][col] = playerNum;
            qDebug("%d, %d, %d", i, COL_MAX, col);
            emit dataChanged(index(i * COL_MAX + col), index(i * COL_MAX + col));
            success = true;
            qDebug("Putting to %d, %d\n", i, col);
            break;
        }
    }
    if (!success)
    {
        qDebug() << "Column is full";
        return;
    }

    qDebug() << m_map;
    std::optional<PlayerId> winner = m_ref.judge(m_map);
    if (winner.has_value())
        emit gameOver(winner.value());
}

void Board::onRestart()
{
    emit beginResetModel();
    for (int i = 0; i < ROW_MAX; i++)
    {
        std::fill(m_map[i].begin(), m_map[i].end(), 0);
    }
    emit endResetModel();
}
