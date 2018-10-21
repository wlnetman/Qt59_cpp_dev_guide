#ifndef TESTQSTRING_H
#define TESTQSTRING_H

#include <QMainWindow>

namespace Ui {
class TestQString;
}

class TestQString : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestQString(QWidget *parent = nullptr);
    ~TestQString();

private slots:
    void on_pBtnAppend_clicked();

    void on_pBtnPrepend_clicked();

    void on_pBtnToup_clicked();

    void on_pBtnToLow_clicked();

    void on_pBtnLeft_clicked();

    void on_pBtnRight_clicked();

    void on_pBtnSection_clicked();

    void on_pBtnSim_clicked();

    void on_pBtnTrimmed_clicked();

    void on_pBtnSplite_clicked();

    void on_bBtnCount_clicked();

    void on_pBtnSize_clicked();

    void on_pBtnIndex_clicked();

    void on_pBtnLastIndex_clicked();

    void on_pBtnCap_clicked();

    void on_pBtnEnds_clicked();

    void on_pBtnStart_clicked();

    void on_pBtnContains_clicked();

    void on_pBtnNull_clicked();

    void on_pBtnEmpty_clicked();

private:
    QString str1();
    QString str2();
    void setResult(QString ret);
    void setResult(bool ret);

private:
    Ui::TestQString *ui;
};

#endif // TESTQSTRING_H
