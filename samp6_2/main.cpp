#include <QApplication>
#include "qwdialogheaders.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWDialogHeaders w;
    w.show();

    return app.exec();
}
