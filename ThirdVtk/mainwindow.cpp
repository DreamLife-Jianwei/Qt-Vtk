#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget_Main->tabBar()->hide();
    mAmbintSpheres = new AmbientSpheres(ui->tab_ambientSpheres);
    mAmbintSpheres->resize(ui->tab_ambientSpheres->size());
    this->setWindowTitle("Qt&Vtk");
    this->showMaximized();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    mAmbintSpheres->resize(ui->tab_ambientSpheres->size());
}

void MainWindow::on_actionAmbientSpheres_triggered()
{
    ui->tabWidget_Main->setCurrentIndex(0);
}

