#ifndef BASE_H
#define BASE_H

#include "easyloggingpp/src/easylogging++.h"
#include <QDir>
#include <QString>

const QDir PRO_ROOT("../");
enum StatusCode {
    Fail,
    Success
};
enum WinCode {
    NotFinished,
    Win
};

const uint8_t ROW_MAX = 6;
const uint8_t COL_MAX = 7;
class LoggedClass {
public:
    LoggedClass(const QString& tag);
    ~LoggedClass();
    void printSep() const;
    el::Logger* log = nullptr;

private:
    QString conf_path;
    QString tag;
};

#endif // BASE_H
