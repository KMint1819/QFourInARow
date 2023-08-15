#ifndef BOARD_H
#define BOARD_H

#include "core/base.h"
#include "core/referee.h"
#include <QAbstractListModel>
#include <QObject>
#include <QPair>
#include <QQuickView>
#include <QVector>

#include "base.h"
#include <QDebug>
#include <QtQuick>

class Board : public QAbstractListModel
{
    Q_OBJECT

  public:
    explicit Board(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Slots
    Q_INVOKABLE void onPut(const int &col);
    Q_INVOKABLE void onRestart();

  signals:
    void gameOver(PlayerId winner);

  private:
    BoardContainer m_map;
    Referee m_ref;
    PlayerId m_currentPlayer = 1;
};
#endif // BOARD_H
