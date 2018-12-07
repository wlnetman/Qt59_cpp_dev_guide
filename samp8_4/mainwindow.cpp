#include "mainwindow.h"
#include "qwgraphicsview.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labViewCord = new QLabel("View 坐标: ");
    labViewCord->setMinimumWidth(150);
    ui->statusbar->addWidget(labViewCord);

    labSceneCord= new QLabel("Scene 坐标: ");
    labSceneCord->setMinimumWidth(150);
    ui->statusbar->addWidget(labSceneCord);

    labItemCord= new QLabel("Item 坐标: ");
    labItemCord->setMinimumWidth(150);
    ui->statusbar->addWidget(labItemCord);

    ui->view->setCursor(Qt::CrossCursor);
    ui->view->setMouseTracking(true);
    ui->view->setDragMode(QGraphicsView::RubberBandDrag);

    connect(ui->view, &QWGraphicsView::mouseMovePoint , this, &MainWindow::on_mouseMovePoint);
    connect(ui->view, &QWGraphicsView::mouseClicked , this, &MainWindow::on_mouseClicked);

    iniGraphicsSystem();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniGraphicsSystem()
{
    QRectF rect(-200, -100, 400, 200);
    scene = new QGraphicsScene(rect);
    ui->view->setScene(scene);
    QGraphicsRectItem *item = new QGraphicsRectItem(rect);
    item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
    QPen pen;
    pen.setWidth(2);
    item->setPen(pen);
    scene->addItem(item);

    QGraphicsEllipseItem *item2 = new QGraphicsEllipseItem(-100, -50, 200, 100);
    item2->setPos(0,0);
    item2->setBrush(QBrush(Qt::blue));
    item2->setFlags(QGraphicsItem::ItemIsMovable
                    | QGraphicsItem::ItemIsSelectable
                    | QGraphicsItem::ItemIsFocusable);
    scene->addItem(item2);

    QGraphicsEllipseItem *item3 = new QGraphicsEllipseItem(-50, -50, 100, 100);
    item2->setPos(rect.right(), rect.bottom());
    item2->setBrush(QBrush(Qt::red));
    item2->setFlags(QGraphicsItem::ItemIsMovable
                    | QGraphicsItem::ItemIsSelectable
                    | QGraphicsItem::ItemIsFocusable);
    scene->addItem(item3);

    scene->clearSelection();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    QString str = QString::asprintf("Graphics View坐标,左上角总是(0,0),宽度= %d,高度=%d",
                                    ui->view->width(), ui->view->height());
    ui->labViewSize->setText(str);
    QRectF rectF = ui->view->sceneRect();
    str = QString::asprintf("QGraphicsView::sceneRect=(Left,Top,Width,Heigth)=%.0f,%.0f,%.0f,%.0f",
                            rectF.left(), rectF.top(), rectF.left(), rectF.top());
    ui->labSceneCord->setText(str);
}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    QString str = QString::asprintf("View 坐标: %d,%d", point.x(), point.y());
    labViewCord->setText(str);
    QPointF pointScene = ui->view->mapToScene(point); // 转换到Scene坐标
    str = QString::asprintf("Scene 坐标: %0.f,%0.f", pointScene.x(), pointScene.y());
    labSceneCord->setText(str);
}

void MainWindow::on_mouseClicked(QPoint point)
{
    QPointF pScene = ui->view->mapToScene(point);
    QGraphicsItem *item = nullptr;
    item = scene->itemAt(pScene, ui->view->transform());
    if(item != nullptr){
        QPointF pointItem = item->mapFromScene(pScene);
        QString str = QString::asprintf("Item 坐标: %.0f,%.0f", pointItem.x(), pointItem.y());
        labItemCord->setText(str);
    }
}

