#include "easyview.h"
#include "ui_easyview.h"

EasyView::EasyView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EasyView)
{
    ui->setupUi(this);
}

EasyView::~EasyView()
{
    delete ui;
}
