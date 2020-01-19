#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QVector>
#include <QPair>
#include "core/base.h"

class Board: public QObject, public LoggedClass
{
    Q_OBJECT
public:
    explicit Board(QObject* parent, QString player1, QString player2);
    void test();
    int getWinner();
    QPair<QString, QString> getPlayerName();
    void setWinner(int a);
    StatusCode put(int playerNum, int col);
    void clear();
    void print();
    QVector<QVector<int>>* getMap();
    //    QString toString();

private:
    QVector<QVector<int>> map;
    QVector<int> col_height;
    WinCode winCode = NotFinished;
    int winner = -1;
    QString player1;
    QString player2;

};
#endif // BOARD_H
