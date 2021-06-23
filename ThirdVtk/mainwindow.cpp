#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget_Main->tabBar()->hide();
    this->setWindowTitle("Qt&Vtk");
    mAmbintSpheres = new AmbientSpheres(ui->tab_ambientSpheres);
    mAmbintSpheres->resize(ui->tab_ambientSpheres->size());

    mArrays = new MArrays(ui->tab_Arrays);
    mArrays->resize(ui->tab_Arrays->size());





    this->showMaximized();                  //这句话不要写到前面，不然你得知道怎么死的
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
}

void MainWindow::on_actionAmbientSpheres_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(0);
    update();
}


void MainWindow::on_actionArrays_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(1);
    update();
}
