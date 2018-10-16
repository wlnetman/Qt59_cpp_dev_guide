#include <QHBoxLayout>
#include "qwdlgmanual.h"

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    initUI();
    initSignalSlots();
    setWindowTitle(u8("感谢各位水友"));
}

QWDlgManual::~QWDlgManual()
{

}

// 初始化界面
void QWDlgManual::iniUI()
{
    // 水平布局Underline,Italic,Bold
    chkBoxUnder = new QCheckBox(tr("Underline"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxBold  = new QCheckBox(tr("Blod"));
    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);

    //水平布局Black,Red,Blue
    rBtnBlack = new QRadioButton(tr("Black"));
    rBtnRed = new QRadioButton(tr("Red"));
    rBtnBlue = new QRadioButton(tr("Blue"));
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(rBtnBlack);
    HLay2->addWidget(rBtnRed);
    HLay2->addWidget(rBtnBlue);

    // 确认，取消，退出
    btnOK = new QPushButton(tr("确定"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("退出"));
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addWidget(btnOK);
    HLay3->addWidget(btnCancel);
    HLay3->addWidget(btnClose);

    //文本框，设置初始字体
    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText(tr("感谢各位水友，关注走一波"));
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    //

}

// 初始化信号跟槽
void QWDlgManual::initSignalSlots()
{

}

// 设置字体格式
void QWDlgManual::on_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

// 设置字体颜色
void QWDlgManual::setTextFontColor()
{

}
