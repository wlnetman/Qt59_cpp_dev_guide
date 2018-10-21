#include "testqstring.h"
#include "testqstring.h"
#include "ui_testqstring.h"

TestQString::TestQString(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestQString)
{
    ui->setupUi(this);

    setWindowTitle("QString常用功能");
    //setStatusBar(nullptr);
    // 置顶
    setWindowFlags(Qt::WindowStaysOnTopHint);

}

TestQString::~TestQString()
{
    delete ui;
}

void TestQString::on_pBtnAppend_clicked()
{
    QString str3 = str1().append(str2());
    ui->edResult->setText(str3);
}

void TestQString::on_pBtnPrepend_clicked()
{
    QString str3 = str1().prepend(str2());
    ui->edResult->setText(str3);
}

QString TestQString::str1()
{
    return ui->cbStr1->lineEdit()->text();
}

QString TestQString::str2()
{
    return ui->cbStr2->lineEdit()->text();
}

void TestQString::setResult(QString ret)
{
    ui->edResult->setText(ret);
    ui->spinBCount->setValue(ret.count());
}

void TestQString::setResult(bool ret)
{
    ui->edResult->setText( ret? "true": "false");
    ui->spinBCount->setValue(ret);
}


void TestQString::on_pBtnToup_clicked()
{
    QString str3 = ui->edResult->text().toUpper();
    setResult(str3);
}

void TestQString::on_pBtnToLow_clicked()
{
    QString str3 = ui->edResult->text().toLower();
    setResult(str3);
}

void TestQString::on_pBtnLeft_clicked()
{
    QString ret = str1().left(1);
    ret.append(str2().left(1));
    setResult(ret);
}

void TestQString::on_pBtnRight_clicked()
{
    QString ret = str1().right(1);
    ret.append(str2().right(1));
    setResult(ret);
}

void TestQString::on_pBtnSection_clicked()
{
    QString str = str1();
    QString::SectionFlag flag = QString::SectionSkipEmpty;
    QString ret = str.section('/', 1, 2, flag);
    setResult(ret);
}

void TestQString::on_pBtnSim_clicked()
{
    setResult(str1().simplified());
}

void TestQString::on_pBtnTrimmed_clicked()
{
    setResult(str1().trimmed());
}

void TestQString::on_pBtnSplite_clicked()
{
    QString str = str1();
    QList<QString> ret = str.split('/');
    setResult(ret[0]);
}

void TestQString::on_bBtnCount_clicked()
{
    setResult(QString::number(str1().count()));
}

void TestQString::on_pBtnSize_clicked()
{
    setResult(QString::number(str1().size()));
}

void TestQString::on_pBtnIndex_clicked()
{
    setResult(QString::number(str1().indexOf(str2())));
}

void TestQString::on_pBtnLastIndex_clicked()
{
    setResult(QString::number(str1().lastIndexOf(str2())));
}

void TestQString::on_pBtnCap_clicked()
{
    setResult(QString::number(str1().capacity()));
}

void TestQString::on_pBtnEnds_clicked()
{
    setResult(str1().endsWith(str2()));
}

void TestQString::on_pBtnStart_clicked()
{
    setResult(str1().startsWith(str2()));
}

void TestQString::on_pBtnContains_clicked()
{
    setResult(str1().contains(str2()));
}

void TestQString::on_pBtnNull_clicked()
{
    setResult(str1().isNull());
}

void TestQString::on_pBtnEmpty_clicked()
{
    setResult(str1().isEmpty());
}
