#include <QApplication>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    MainWindow w;
    w.show();

    return app.exec();
}
