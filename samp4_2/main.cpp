#include <QApplication>
#include "testqstring.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TestQString test;
    test.show();

    return app.exec();
}
