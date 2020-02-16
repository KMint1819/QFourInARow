#include "base.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <iostream>
LoggedClass::LoggedClass(const QString& tag)
    : tag(tag)
{
    qDebug() << "Constructing " << tag << "LoggedClass";
    QDir tmp_path(PRO_ROOT.absolutePath() + "/config/log.conf");
    conf_path = tmp_path.absolutePath();
    log = el::Loggers::getLogger(tag.toStdString());
    el::Loggers::reconfigureLogger(tag.toStdString(), el::Configurations(conf_path.toStdString()));
    log->debug("LoggedClass succeed");
}

LoggedClass::~LoggedClass()
{
    el::Loggers::unregisterLogger(tag.toStdString());
}
void LoggedClass::print_sep()
{
    QString tmp("===============================");
    log->info("%v", tmp.toStdString());
}
