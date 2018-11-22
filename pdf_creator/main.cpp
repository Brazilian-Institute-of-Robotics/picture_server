/* Copyright 2018 JIRo */

#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <QGuiApplication>

#include <pdf_generator.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQuickView view;
    PdfGenerator pdf;

    view.engine()->rootContext()->setContextProperty("pdf", &pdf);
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.setTitle("Report sample");
    view.show();

    return app.exec();
}
