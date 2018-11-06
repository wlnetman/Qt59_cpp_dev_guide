#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_btnAdd_clicked();

    void on_btnInsert_clicked();

    void on_btnDel_clicked();

    void on_btnClear_clicked();

    void on_btnShowText_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_btnTextClear_clicked();

private:
    Ui::Form *ui;

    QStringListModel *theModel;
};

#endif // FORM_H
