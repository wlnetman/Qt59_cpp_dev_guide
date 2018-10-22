#include <QApplication>
#include "testtime.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TestTime w;
    w.show();

    return app.exec();
}
