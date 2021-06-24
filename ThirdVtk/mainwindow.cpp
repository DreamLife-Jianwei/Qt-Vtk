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
