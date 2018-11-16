#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include "dlglogin.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    DlgLogin *login = new DlgLogin;
    if( QDialog::Accepted == login->exec())
    {
        QMessageBox::information(nullptr, "登录成功", "恭喜你");
    } else {
        QMessageBox::information(nullptr, "登录不成功", "恭喜你");
    }
    return app.exec();
}
