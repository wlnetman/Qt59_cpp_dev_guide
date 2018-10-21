#include <QApplication>
#include "testspinbox.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TestSpinBox test;
    test.show();

    return app.exec();
}
