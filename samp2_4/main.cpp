#include "qwmainwind.h"
#include <QApplication>


// 这个示例是自己写一个文本编辑器
// 图标文件，从喜欢的app里面提取出来，
// 用ResourcesExtract可以从本机程序提取图标文件
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWMainWind w;
    w.show();

    return a.exec();
}
