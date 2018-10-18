#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>


namespace Ui {
class QWMainWind;
}

class QWMainWind : public QMainWindow
{
    Q_OBJECT

public:
    explicit QWMainWind(QWidget *parent = 0);
    ~QWMainWind();

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

    // 手工添加设置字体大小跟字体的槽函数
    void on_spinBoxFontSize_valueChanged(int aFontSize); //改变字体大小
    void on_comboFont_currentIdexChanged(const QString &arg1); // 选择字体

private:
    Ui::QWMainWind *ui;

    QLabel *fLabCurFile;// 状态栏显示当前文件
    QProgressBar *progressBar1; // 状态栏进度条
    QSpinBox     *spinFontSize; //字体大小
    QFontComboBox *comboFont; // 字体名称

    void iniUI(); // 初始化自定义UI
    void iniSignalSlots(); //关联槽函数
};

#endif // QWMAINWIND_H
