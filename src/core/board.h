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
class Board : public QObject
{

    Q_OBJECT

  public:
    explicit Board(QObject *parent, QString player1, QString player2, QQmlApplicationEngine &engine);
    void test();
    void print() const;
    QVector<QVector<int>> getMap2d() const;
    // QML
    Q_INVOKABLE bool put(const int &playerNum, const int &col);
    Q_INVOKABLE QVector<int> getMap1d() const;
    Q_INVOKABLE int getWinner() const;
    Q_INVOKABLE QVector<QString> getPlayerName() const;
    Q_INVOKABLE void clear();
    //    QString toString();

  private:
    QQmlApplicationEngine *engine;
    QVector<QVector<int>> m_map;
    QVector<int> col_height;
    int winner = 0;
    int counter = 0;
    QString player1;
    QString player2;
    Referee ref;
};
#endif // BOARD_H
