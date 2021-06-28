#include "graphitem.h"
#include "ui_graphitem.h"

GraphItem::GraphItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphItem)
{
    ui->setupUi(this);
}

GraphItem::~GraphItem()
{
    delete ui;
}
