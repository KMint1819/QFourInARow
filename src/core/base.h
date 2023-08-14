#ifndef BASE_H
#define BASE_H

#include <QDir>
#include <QString>

const QDir PRO_ROOT("../");

const uint8_t ROW_MAX = 6;
const uint8_t COL_MAX = 7;

using PlayerId = uint8_t;
using BoardContainer = QVector<QVector<PlayerId>>;

#endif // BASE_H
