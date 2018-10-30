#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDate>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSetHeader_clicked();

    void on_btnIniData_clicked();

    void on_tableInfo_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_btnInsertRow_clicked();

    void on_btnAppendRow_clicked();

    void on_btnDeleteRow_clicked();

    void on_chkBoxRowColor_clicked(bool checked);

private:
    Ui::MainWindow *ui;

    enum CellType{ctName = 1000, ctSex, ctBirth, ctNation, ctPartyM, ctScore};
    enum FieldColNum{colName = 0, colSex,colBirth, colNation, colPartyM, colScore};

    QLabel *labCellIndex,*labCellType,*labStudID; //状态栏
    void createItemsARow(int rowNo, QString name, QString sex,QDate birth,
                         QString Nation, bool isPM,int score);
};

#endif // MAINWINDOW_H
