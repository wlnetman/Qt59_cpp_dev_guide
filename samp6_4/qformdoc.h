#ifndef QFORMDOC_H
#define QFORMDOC_H

#include <QWidget>
#include <QFileDialog>
#include <QFontDialog>
#include <QToolBar>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QVBoxLayout>

namespace Ui {
class QFormDoc;
}

class QFormDoc : public QWidget
{
    Q_OBJECT

public:
    explicit QFormDoc(QWidget *parent = nullptr);
    ~QFormDoc();

private slots:
    void on_actOpen_triggered();

    void on_actFont_triggered();

private:
    Ui::QFormDoc *ui;
};

#endif // QFORMDOC_H
