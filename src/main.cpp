#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "vmdetect.h"

int main(int argc, char *argv[])
{
    if(isVM()) {
        qputenv("QMLSCENE_DEVICE", "software");
        qputenv("QT_QUICK_BACKEND", "software");
    }

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qml/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
