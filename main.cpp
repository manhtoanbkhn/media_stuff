#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "image_handler.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ImageHandler* image_handler = new ImageHandler(&app);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("image_handler", image_handler);
    const QUrl url(u"qrc:/media_stuff/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
