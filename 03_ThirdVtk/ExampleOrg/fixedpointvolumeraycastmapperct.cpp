#include "fixedpointvolumeraycastmapperct.h"
#include "ui_fixedpointvolumeraycastmapperct.h"

FixedPointVolumeRayCastMapperCT::FixedPointVolumeRayCastMapperCT(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FixedPointVolumeRayCastMapperCT)
{
    ui->setupUi(this);
}

FixedPointVolumeRayCastMapperCT::~FixedPointVolumeRayCastMapperCT()
{
    delete ui;
}
