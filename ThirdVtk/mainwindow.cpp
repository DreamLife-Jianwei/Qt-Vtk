#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget_Main->tabBar()->hide();
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
