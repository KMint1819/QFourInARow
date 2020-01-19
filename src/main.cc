#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QRunnable>
#include <QDebug>
#include <QThreadPool>

#include <iostream>
#include <utility>
#include "core/base.h"
#include "core/board.h"
#include "core/referee.h"
#include "easyloggingpp/src/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

void test(QGuiApplication* app)
{
    LOG(INFO) << "Testing...";
    QVector<QString> dualName = {"A", "B"};
    Board board(app, dualName[0], dualName[1]);
    Referee ref;

    for (int i = 1 ; board.getWinner() == -1; i = i % 2 + 1)
    {
        LOG(INFO) << "Player " << dualName[i - 1].toStdString() << ": Please enter column:";
        int c;
        std:: cin >> c;

        while (!board.put(i, c))
        {
            LOG(INFO) << "This position is occupied. Enter again(row, column):";
            std:: cin >> c;
        }

        board.print();

        if (ref.judge(i, &board) == Win)
        {
            LOG(INFO) << "Player " << dualName[i - 1].toStdString() << " win!!";
            break;
        }

        board.print();
    }
}
int main(int argc, char* argv[])
{
    START_EASYLOGGINGPP(argc, argv);
    LOG(INFO) << "TEST INFO";
    LOG(WARNING) << "TEST WARN";
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/gui/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject * obj, const QUrl & objUrl)
    {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    //    Tester tester(&app);
    //    QThreadPool::globalInstance()->start(&tester);
    //    tester.run();
    test(&app);
    engine.load(url);
    return app.exec();
}
