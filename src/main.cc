#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QRunnable>
#include <QThreadPool>

#include "core/base.h"
#include "core/board.h"
#include "core/referee.h"
#include "easyloggingpp/src/easylogging++.h"
#include <iostream>
#include <utility>

INITIALIZE_EASYLOGGINGPP

void test(QGuiApplication& app, QUrl url)
{
    LOG(INFO) << "Testing...";
    //
    const void* address = static_cast<const void*>(&app);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();
    LOG(INFO) << name;
    //

    QVector<QString> dualName = { "A", "B" };
    QQmlApplicationEngine engine(&app);
    engine.load(url);

    //
    ss.clear();
    ss.flush();
    const void* address1 = static_cast<const void*>(&app);
    ss << address1;
    name = ss.str();
    LOG(INFO) << name;
    //
    Board board(&app, dualName[0], dualName[1], engine);
    LOG(DEBUG) << "Hello";
    //    for (int i = 1; !board.getWinner(); i = i % 2 + 1) {
    //        LOG(INFO) << "Player " << dualName[i - 1].toStdString() << ": Please enter column:";
    //        int c;
    //        std::cin >> c;

    //        while (!board.put(i, c)) {
    //            LOG(INFO) << "This position is occupied. Enter again(row, column):";
    //            std::cin >> c;
    //        }

    //        board.print();

    //        int winner = board.getWinner();
    //        if (winner) {
    //            LOG(INFO) << "Player " << dualName[i - 1].toStdString() << " win!!";
    //            break;
    //        }

    //        board.print();
    //    }
}
int main(int argc, char* argv[])
{
    START_EASYLOGGINGPP(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    const QUrl url(QStringLiteral("qrc:/gui/main.qml"));
    //    QQmlApplicationEngine engine;
    //    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //        &app, [url](QObject* obj, const QUrl& objUrl) {
    //            if (!obj && url == objUrl) {
    //                QCoreApplication::exit(-1);
    //            }
    //        },
    //        Qt::QueuedConnection);
    //    Tester tester(&app);
    //    QThreadPool::globalInstance()->start(&tester);
    //    tester.run();
    //    test(&app);

    //    const void* address = static_cast<const void*>(&app);
    //    std::stringstream ss;
    //    ss << address;
    //    std::string name = ss.str();
    //    LOG(INFO) << name;

    //    test(app, url);

    LOG(INFO) << "Testing...";
    QVector<QString> dualName = { "A", "B" };
    QQmlApplicationEngine engine;
    engine.load(url);
    Board board(&app, dualName[0], dualName[1], engine);
    LOG(DEBUG) << "Hello";

    return app.exec();
}
