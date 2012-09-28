#include <QtGui/QGuiApplication>
#include "qtquick2applicationviewer.h"
#include "qPhidgetRFID.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/rfidWebkit/main.qml"));
    viewer.showExpanded();

    qPhidgetRFID *r;
    r = new qPhidgetRFID();

    return app.exec();
}
