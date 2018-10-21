#ifndef TESTSPINBOX_H
#define TESTSPINBOX_H

#include <QDialog>

namespace Ui {
class TestSpinBox;
}

class TestSpinBox : public QDialog
{
    Q_OBJECT

public:
    explicit TestSpinBox(QWidget *parent = nullptr);
    ~TestSpinBox();

private slots:
    void on_pBtnCacl_clicked();

    void on_pBtnDec_clicked();

    void on_pBtnBin_clicked();

    void on_pBtnHex_clicked();

private:
    Ui::TestSpinBox *ui;
};

#endif // TESTSPINBOX_H
