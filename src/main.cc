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

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    const QUrl url(QStringLiteral("qrc:/gui/main.qml"));

    QQmlApplicationEngine engine;
    Board board(&app);
    engine.rootContext()->setContextProperty("boardModel", &board);

    engine.load(url);

    return app.exec();
}
