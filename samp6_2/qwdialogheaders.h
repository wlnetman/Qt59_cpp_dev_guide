#ifndef QWDIALOGHEADERS_H
#define QWDIALOGHEADERS_H

#include <QDialog>

namespace Ui {
class QWDialogHeaders;
}

class QWDialogHeaders : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogHeaders(QWidget *parent = nullptr);
    ~QWDialogHeaders();

    int rowCount();
    int columnCount();
    void setRowColumn(int row, int column);
private:
    Ui::QWDialogHeaders *ui;
};

#endif // QWDIALOGHEADERS_H
