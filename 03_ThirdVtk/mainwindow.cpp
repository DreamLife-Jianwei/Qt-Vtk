#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


static QPoint last(0,0);        //保存坐标
const int TITLEHEIGFHT = 30;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->centralWidget->installEventFilter(this);
    ui->tab_Logo->installEventFilter(this);
    ui->tabWidget_Main->tabBar()->hide();
    ui->tabWidget_Main->setCurrentIndex(0);
    ui->tabWidget_Example->tabBar()->hide();
    ui->tabWidget_Example->setGeometry(0,0,ui->tab_Example->width(),ui->tab_Example->height());
    //    ui->tabWidget_Main->resize(1366,768);
    ui->ToolBarImage->hide();
    infor = new QLabel(this);
    infor->setText("Qt 版本: 5.7.1 后面更换为5.14.2  "
                   "VS版本：2015 Update 3 "
                   "Vtk版本: 8.2.0 Release "
                   "制作：张建伟 "
                   "邮箱：jianwei1992@foxmail.com "
                   "博客：dreamlife.blog.csdn.net "
                   "GieHub地址：github.com/DreamLife-Jianwei");
    ui->statusBar->addPermanentWidget(infor);
    ui->tabWidget_Example->setCurrentIndex(0);
    this->setWindowTitle("Qt&Vtk");

    /****************官方代码示例*********************/

    mAmbintSpheres = new AmbientSpheres(ui->tab_ambientSpheres);
    mArrays = new MArrays(ui->tab_Arrays);
    mCone = new Cone(ui->tab_Cone);
    mCone2 = new Cone2(ui->tab_Cone2);
    mCone3 = new Cone3(ui->tab_Cone3);
    mCone4 = new Cone4(ui->tab_Cone4);
    mCone5 = new Cone5(ui->tab_Cone5);
    mCone6 = new Cone6(ui->tab_Cone6);
    mCreateTree = new CreateTree(ui->tab_CreateTree);
    mCube = new Cube(ui->tab_Cube);
    mCylinder = new Cylinder(ui->tab_Cylinder);
    mDiffuseSpheres = new DiffuseSpheres(ui->tab_DiffuseSpheres);
    mGraphItem = new GraphItem(ui->tab_GraphItem);
    mHelloWorld = new HelloWorld(ui->tab_HelloWorld);
    mLabeldMesh = new LabeledMesh(ui->tab_LabeledMesh);
    mMultiview = new MultiView(ui->tab_MultiView);
    mPiecewiseItem = new PiecewiseItem(ui->tab_PiecewiseItem);
    mQchartTable = new QChartTable(ui->tab_QChartTable);
    mQScalarsToColors = new QScalarsToColors(ui->tab_QScalarsToColors);
    mRGrid = new RGrid(ui->tab_RGrid);
    mSGrid = new SGrid(ui->tab_SGrid);
    mSpecularSpheres = new SpecularSpheres(ui->tab_SpecularSpheres);
    mTheme = new Theme(ui->tab_Theme);

    /****************图像管理*********************/

    mImageManage = new ImageManage(ui->tab_ImageManage);



    /**
      下面这个函数没有啥实际用途，目的就是在构造完成后强制的调用resizeevent，来刷新界面
      */
    QTimer::singleShot(1,this,[=](){
        resizeWindow();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)

    ui->tabWidget_Example->resize(ui->tab_Example->size());
    //官方实例演示
    mAmbintSpheres->resize(ui->tab_ambientSpheres->size());
    mArrays->resize(ui->tab_Arrays->size());
    mCone->resize(ui->tab_Cone->size());
    mCone2->resize(ui->tab_Cone2->size());
    mCone3->resize(ui->tab_Cone3->size());
    mCone4->resize(ui->tab_Cone4->size());
    mCone5->resize(ui->tab_Cone5->size());
    mCone6->resize(ui->tab_Cone6->size());
    mCreateTree->resize(ui->tab_CreateTree->size());
    mCube->resize(ui->tab_Cube->size());
    mCylinder->resize(ui->tab_Cylinder->size());
    mDiffuseSpheres->resize(ui->tab_DiffuseSpheres->size());
    mGraphItem->resize(ui->tab_GraphItem->size());
    mHelloWorld->resize(ui->tab_HelloWorld->size());
    mLabeldMesh->resize(ui->tab_LabeledMesh->size());
    mMultiview->resize(ui->tab_MultiView->size());
    mPiecewiseItem->resize(ui->tab_PiecewiseItem->size());
    mQchartTable->resize(ui->tab_QChartTable->size());
    mQScalarsToColors->resize(ui->tab_QScalarsToColors->size());
    mRGrid->resize(ui->tab_RGrid->size());
    mSGrid->resize(ui->tab_SGrid->size());
    mSpecularSpheres->resize(ui->tab_SpecularSpheres->size());
    mTheme->resize(ui->tab_Theme->size());
    //图像管理
    mImageManage->resize(ui->tab_ImageManage->size());
}

void MainWindow::on_actionAmbientSpheres_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(0);
    this->setWindowTitle("Qt&Vtk-Ambientspheres");
    changeExample();
}

void MainWindow::on_actionArrays_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(1);
    this->setWindowTitle("Qt&Vtk-Arrays");
    changeExample();
}

void MainWindow::on_actionCone_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(2);
    this->setWindowTitle("Qt&Vtk-Cone");
    changeExample();
}

void MainWindow::on_actionCone2_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(3);
    this->setWindowTitle("Qt&Vtk-Cone2");
    changeExample();
}

void MainWindow::on_actionCone3_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(4);
    this->setWindowTitle("Qt&Vtk-Cone3");
    changeExample();
}

void MainWindow::on_actionCone4_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(5);
    this->setWindowTitle("Qt&Vtk-Cone4");
    changeExample();
}

void MainWindow::on_actionCone5_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(6);
    this->setWindowTitle("Qt&Vtk-Cone5");
    mCone5->startiren();
    changeExample();
}

void MainWindow::on_actionCone6_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(7);
    this->setWindowTitle("Qt&Vtk-Cone6");
    mCone6->startInteractor();
    changeExample();
}

void MainWindow::on_actionCreateTree_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(8);
    this->setWindowTitle("Qt&Vtk-CreateTree");
    mCreateTree->startInteractor();
    changeExample();
}

void MainWindow::on_actionCube_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(9);
    this->setWindowTitle("Qt&Vtk-Cube");
    changeExample();
}

void MainWindow::on_actionCylinder_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(10);
    this->setWindowTitle("Qt&Vtk-Cylinder");
    changeExample();
}

void MainWindow::on_actionDiffuseSpheres_triggered()
{
    ui->tabWidget_Example->setCurrentIndex(11);
    this->setWindowTitle("Qt&Vtk-DiffuseSpheres");

    changeExample();
}

void MainWindow::on_actionGraphItem_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(12);
    this->setWindowTitle("Qt&Vtk-GraphItem");
    changeExample();
}

void MainWindow::on_actionHelloWorld_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(13);
    this->setWindowTitle("Qt&Vtk-HelloWorld");
    changeExample();
}

void MainWindow::on_actionLabeledMesh_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(14);
    this->setWindowTitle("Qt&Vtk-LabeldMesh");
    changeExample();

}

void MainWindow::on_actionMultiView_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(15);
    this->setWindowTitle("Qt&Vtk-MultiView");
    changeExample();
}

void MainWindow::on_actionPiecewiseItem_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(16);
    this->setWindowTitle("Qt&Vtk-PiecewiseItem");
    changeExample();
}

void MainWindow::on_actionQChartTable_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(17);
    this->setWindowTitle("Qt&Vtk-QChartTable");
    changeExample();
}

void MainWindow::on_actionQScalarsToColors_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(18);
    this->setWindowTitle("Qt&Vtk-QScalarsToColors");
    changeExample();
}

void MainWindow::on_actionRGrid_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(19);
    this->setWindowTitle("Qt&Vtk-RGrid");
    changeExample();
}

void MainWindow::on_actionSGrid_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(20);
    this->setWindowTitle("Qt&Vtk-SGrid");
    changeExample();
}

void MainWindow::on_actionSpecularSpheres_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(21);
    this->setWindowTitle("Qt&Vtk-SpecularSpheres");
    changeExample();
}

void MainWindow::on_actionTheme_triggered()
{

    ui->tabWidget_Example->setCurrentIndex(22);
    this->setWindowTitle("Qt&Vtk-Theme");
    changeExample();
}

void MainWindow::changeExample()
{
    if(ui->tabWidget_Main->currentIndex() != 1)
    {
        ui->tabWidget_Main->setCurrentIndex(1);
        ui->ToolBarImage->hide();
    }
    resizeWindow();
}

void MainWindow::changeImageManage()
{
    if(ui->tabWidget_Main->currentIndex() != 2)
    {
        ui->tabWidget_Main->setCurrentIndex(2);
    }
    resizeWindow();
}

void MainWindow::resizeWindow()
{
    this->resize(this->size() - QSize(1, 1));
    this->resize(this->size() + QSize(1, 1));
}
/**
 * @brief MainWindow::paintEvent
 * @param event
 * 这部分代码是最坑爹的，在公司电脑上死活执行不正常，在家里电脑上又尼玛可以了
 */
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter_back(this);
    QPixmap image(":/MainWindow/Images/MainWindow/background.png");
    QPixmap imageN = image.scaled(this->width(),this->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    painter_back.translate(this->width()/2,this->height()/2);
    painter_back.drawPixmap(0-imageN.width()/2,0-imageN.height()/2,imageN);

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->y()<TITLEHEIGFHT)
    {
        last = event->globalPos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->y()<TITLEHEIGFHT)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        last = event->globalPos();
        this->move(this->x()+dx,this->y()+dy);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->y()<TITLEHEIGFHT)
    {
        int dx = event->globalX() - last.x();
        int dy = event->globalY() - last.y();
        this->move(this->x()+dx,this->y()+dy);
    }
}
/**
 * @brief MainWindow::eventFilter
 * @param watched
 * @param event
 * @return
 * 事件过滤器，最后还是没有用上
 */
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->centralWidget && event->type() == QEvent::Paint)
    {
        //        QPainter painter_back(ui->centralWidget);
        //        painter_back.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/MainWindow/Images/MainWindow/background.jpg"));
    }
    if(watched == ui->tab_Logo)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *keyEvent = static_cast<QMouseEvent*>(event);
            if(keyEvent->button() == Qt::LeftButton)
            {
                changeExample();
                ui->tabWidget_Example->setCurrentIndex(0);
                this->setWindowTitle("Qt&Vtk-Ambientspheres");
                this->resize(this->size() - QSize(1, 1));
                this->resize(this->size() + QSize(1, 1));
            }
        }
    }
    return QMainWindow::eventFilter(watched,event);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_action2_2_triggered()
{
    changeImageManage();
    mImageManage->setCurrentTab(0);
    ui->ToolBarImage->show();
    mImageManage->update();
    resizeWindow();
}
/**
 * @brief MainWindow::on_actionOpen_triggered
 * 打开文件夹
 */
void MainWindow::on_actionOpen_triggered()
{
    //打开文件,如果是全局，要清理
    QString dir = QFileDialog::getExistingDirectory(this, tr("打开影像文件夹"),"/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    if(!dir.isEmpty())
        mImageManage->slot_ReaderDICOMImage(dir.toLocal8Bit().data());
}
/**
 * @brief MainWindow::on_actionStart_triggered
 * 返回开始界面，没有啥实际作用，仅仅为了返回为返回
 */
void MainWindow::on_actionStart_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(0);
}
