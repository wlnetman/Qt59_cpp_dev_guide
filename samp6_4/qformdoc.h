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
#include <QFileInfo>


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

    QString current_file_;
    bool is_fileopened_;

public:
    void loadFromFile(QString &filename);
    QString currentFileName();

public:
    bool isFileOpened();
    void setEditFont();
    void textCut();
    void textCopy();
    void textPaste();

};

#endif // QFORMDOC_H
