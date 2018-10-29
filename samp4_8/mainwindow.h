#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QTreeWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_actAddFolder_triggered();

    void on_treeWidget_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous);

    void on_actAddFiles_triggered();

    void on_actDeleteItem_triggered();

    void on_actScanItems_triggered();

    void on_actZoomFitH_triggered();

    void on_actZoomRealSize_triggered();

    void on_actDockVisible_triggered(bool checked);

    void on_actDockFloat_triggered(bool checked);

    void on_dockWidget_visibilityChanged(bool visible);

    void on_dockWidget_topLevelChanged(bool topLevel);

private:
    Ui::MainWindow* ui;

    enum treeItemType { itTopItem = 1001,
        itGroupItem,
        itImageItem };
    enum treeCloNum { colItem = 0,
        colItemType = 1 };

    QLabel* LabFileName;
    QPixmap curPixmap;
    float pixRatio;

private:
    void iniTree();
    void addFolderItem(QTreeWidgetItem* parItem, QString dirName);
    QString getFinalFolderName(const QString& fullPathName);
    void addImageItem(QTreeWidgetItem* item, QString aFileName);
    void displayImage(QTreeWidgetItem* item);
    void changeItemCaption(QTreeWidgetItem* item);
};

#endif // MAINWINDOW_H
