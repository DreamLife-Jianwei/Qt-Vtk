#include "customlinkview.h"
#include "ui_customlinkview.h"

CustomLinkView::CustomLinkView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomLinkView)
{
    ui->setupUi(this);
}

CustomLinkView::~CustomLinkView()
{
    delete ui;
}
