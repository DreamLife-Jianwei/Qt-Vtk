#include "marrays.h"
#include "ui_marrays.h"

MArrays::MArrays(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MArrays)
{
    ui->setupUi(this);
}

MArrays::~MArrays()
{
    delete ui;
}
