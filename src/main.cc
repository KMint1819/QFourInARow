#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QRunnable>
#include <QThreadPool>

#include "core/base.h"
#include "core/board.h"
#include "core/referee.h"
#include <iostream>
#include <utility>

void test(QGuiApplication &app, QUrl url)
{
    const void *address = static_cast<const void *>(&app);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();

    QVector<QString> dualName = {"A", "B"};
    QQmlApplicationEngine engine(&app);
    engine.load(url);
    ss.clear();
    ss.flush();
    const void *address1 = static_cast<const void *>(&app);
    ss << address1;
    name = ss.str();
    Board board(&app, dualName[0], dualName[1], engine);
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    const QUrl url(QStringLiteral("qrc:/gui/main.qml"));

    QVector<QString> dualName = {"A", "B"};
    QQmlApplicationEngine engine;
    engine.load(url);
    Board board(&app, dualName[0], dualName[1], engine);

    return app.exec();
}
