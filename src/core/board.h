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
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Slots
    void onPut(const PlayerId &playerNum, const int &col);
    void onRestart();

  signals:
    void updateSignal(BoardContainer map, PlayerId winner);

  private:
    BoardContainer m_map;
    Referee m_ref;
};
#endif // BOARD_H
