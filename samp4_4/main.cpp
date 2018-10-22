#include <QApplication>
#include "showwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ShowWidget w;
    w.show();

    return app.exec();
}
