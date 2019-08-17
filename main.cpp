// Man injam! Ba SVN commit mikonam!
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "shoppinglist.h"

/*

Refs:
[1] qmlRegisterType()
http://doc.qt.io/qt-5/qtqml-cppintegration-definetypes.html
[2] qmlRegisterType()
http://doc.qt.io/qt-5/qqmlengine.html#qmlRegisterType
[2] Extending QML with C++ (very good)
https://qmlbook.github.io/en/ch16/index.html


*/

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    // Any QObject-derived C++ class can be registered as QML object type. Once it is registered, it can be used like
    // any other QML object type [1]:
    qmlRegisterType<ShoppingList>("CppClasses", 1, 0, "ShoppingList");
    // Type namespace: "CppClasses"
    // Version: 1
    // Subversion: 0
    // Type name: "ShoppingList"

    // QQmlApplicationEngine manages the hierarchical order of contexts and components [2]:
    QQmlApplicationEngine engine;
    // QQmlApplicationEngine requires a qml file as starting point of the application (here main.qml) [2]:
    QUrl source(QStringLiteral("/main.qml"));
    engine.load(source);
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
