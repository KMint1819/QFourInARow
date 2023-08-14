#ifndef BASE_H
#define BASE_H

#include <QDir>
#include <QString>

const QDir PRO_ROOT("../");
enum StatusCode
{
    Fail,
    Success
};
enum WinCode
{
    NotFinished,
    Win
};

const uint8_t ROW_MAX = 6;
const uint8_t COL_MAX = 7;

#endif // BASE_H
