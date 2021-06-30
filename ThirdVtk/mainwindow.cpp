#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget_Main->tabBar()->hide();
    ui->tabWidget_Main->resize(1366,768);
    ui->statusBar->showMessage("Qt Creator版本: 5.7.1-MSVC 2015    "
                               "Visual Studio版本：VS2015 Update 3     "
                               "Vtk版本: 8.2.0 Release    "
                               "制作：张建伟  "
                               "邮箱：jianwei1992@foxmail.com    "
                               "博客：dreamlife.blog.csdn.net    "
                               "GieHub地址：github.com/DreamLife-Jianwei");
    //    ui->tabWidget_Main->setCurrentIndex(1);
    this->setWindowTitle("Qt&Vtk");
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





    //    this->showMaximized();                  //这句话不要写到前面，不然你得知道怎么死的
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
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
}

void MainWindow::on_actionAmbientSpheres_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(0);
    this->setWindowTitle("Qt&Vtk-Ambientspheres");
}


void MainWindow::on_actionArrays_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(1);
    this->setWindowTitle("Qt&Vtk-Arrays");
}

void MainWindow::on_actionCone_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(2);
    this->setWindowTitle("Qt&Vtk-Cone");
}

void MainWindow::on_actionCone2_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(3);
    this->setWindowTitle("Qt&Vtk-Cone2");
}

void MainWindow::on_actionCone3_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(4);
    this->setWindowTitle("Qt&Vtk-Cone3");
}

void MainWindow::on_actionCone4_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(5);
    this->setWindowTitle("Qt&Vtk-Cone4");
}

void MainWindow::on_actionCone5_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(6);
    this->setWindowTitle("Qt&Vtk-Cone5");
    mCone5->startiren();
}

void MainWindow::on_actionCone6_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(7);
    this->setWindowTitle("Qt&Vtk-Cone6");
    mCone6->startInteractor();
}

void MainWindow::on_actionCreateTree_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(8);
    this->setWindowTitle("Qt&Vtk-CreateTree");
    mCreateTree->startInteractor();
}

void MainWindow::on_actionCube_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(9);
    this->setWindowTitle("Qt&Vtk-Cube");
}

void MainWindow::on_actionCylinder_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(10);
    this->setWindowTitle("Qt&Vtk-Cylinder");
}

void MainWindow::on_actionDiffuseSpheres_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(11);
    this->setWindowTitle("Qt&Vtk-DiffuseSpheres");
}

void MainWindow::on_actionGraphItem_triggered()
{

    ui->tabWidget_Main->setCurrentIndex(12);
    this->setWindowTitle("Qt&Vtk-GraphItem");
}

void MainWindow::on_actionHelloWorld_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(13);
    this->setWindowTitle("Qt&Vtk-HelloWorld");
}

void MainWindow::on_actionLabeledMesh_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(14);
    this->setWindowTitle("Qt&Vtk-LabeldMesh");
}

void MainWindow::on_actionMultiView_triggered()
{

    ui->tabWidget_Main->setCurrentIndex(15);
    this->setWindowTitle("Qt&Vtk-MultiView");
}

void MainWindow::on_actionPiecewiseItem_triggered()
{

    ui->tabWidget_Main->setCurrentIndex(16);
    this->setWindowTitle("Qt&Vtk-PiecewiseItem");
}

void MainWindow::on_actionQChartTable_triggered()
{

    ui->tabWidget_Main->setCurrentIndex(17);
    this->setWindowTitle("Qt&Vtk-QChartTable");
}

void MainWindow::on_actionQScalarsToColors_triggered()
{

    ui->tabWidget_Main->setCurrentIndex(18);
    this->setWindowTitle("Qt&Vtk-QScalarsToColors");
}
