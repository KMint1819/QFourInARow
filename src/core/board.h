#ifndef BOARD_H
#define BOARD_H

#include "core/base.h"
#include "core/referee.h"
#include <QObject>
#include <QPair>
#include <QQuickView>
#include <QVector>

#include "base.h"
#include <QDebug>
#include <QtQuick>
class Board : public QObject, public LoggedClass {
    Q_OBJECT
    Q_PROPERTY(QVector<int> map READ getMap1d WRITE setMap1d NOTIFY mapChanged)
    Q_PROPERTY(QVector<int> colHeight READ getColHeight)
public:
    explicit Board(QObject* parent, QString player1, QString player2, QQuickView* view);
    void test();
    void clear();
    void print();
    int getWinner();
    QPair<QString, QString> getPlayerName();
    StatusCode put(int playerNum, int col);
    QVector<QVector<int>> getMap2d();
    QVector<int> getMap1d();
    void setMap1d(QVector<int>);
    //    QString toString();
signals:
    void mapChanged();

private:
    QQuickView* m_view;
    QVector<QVector<int>> m_map;
    QVector<int> col_height;
    int winner = 0;
    QString player1;
    QString player2;
    Referee ref;
};
#endif // BOARD_H
