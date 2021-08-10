#include "gpurenderdemo.h"
#include "ui_gpurenderdemo.h"

GPURenderDemo::GPURenderDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GPURenderDemo)
{
    ui->setupUi(this);
}

GPURenderDemo::~GPURenderDemo()
{
    delete ui;
}
