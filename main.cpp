#include <QtGui/QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickView>
#include <QQmlContext>
#include "qmlInterface.h"

#include <QDebug>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QtQuick2ApplicationViewer viewer;
//    viewer.setMainQmlFile(QStringLiteral("qml/rfidWebkit/main.qml"));
//    viewer.showExpanded();

    QQuickView view;
    QQmlContext *context = view.rootContext();

    QObject::connect((QObject*)view.engine(), SIGNAL(quit()), &app, SLOT(quit()));

    qmlInterface *ui;
    ui = new qmlInterface(0,context);

    context->setContextProperty("qIf",ui);
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    view.setSource(QUrl("qml/rfidWebkit/main.qml"));
    view.show();

    return app.exec();
}
