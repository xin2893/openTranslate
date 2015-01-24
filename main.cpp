#include <QApplication>
//#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlContext>


#include "translate.h"
#include "baiduapidictresult.h"
#include "global.h"




int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
#if  1
    qmlRegisterType<Translate>("Translate", 1, 0, "Translate");
    qmlRegisterType<BaiduAPIDictResult>("BaiduAPIDictResult", 1, 0, "BaiduAPIDictResult");
    QQmlEngine engine;
    Translate dict;
    engine.rootContext()->setContextProperty("dict", &dict);

    //engine.load(QUrl(QStringLiteral("qrc:///main.qml")));
    QQmlComponent component(&engine, QUrl::fromLocalFile("main.qml"));
    component.create();
#endif
    return app.exec();



}







