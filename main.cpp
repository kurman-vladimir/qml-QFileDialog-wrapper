#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "FileSaveDialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<FileSaveDialog>("DialogsExtentions", 1, 0, "FileSaveDialog");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
