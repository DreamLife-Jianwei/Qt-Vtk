#ifndef FIXEDPOINTVOLUMERAYCASTMAPPERCT_H
#define FIXEDPOINTVOLUMERAYCASTMAPPERCT_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"
namespace Ui {
class FixedPointVolumeRayCastMapperCT;
}

class FixedPointVolumeRayCastMapperCT : public QWidget
{
    Q_OBJECT

public:
    explicit FixedPointVolumeRayCastMapperCT(QWidget *parent = nullptr);
    ~FixedPointVolumeRayCastMapperCT();

private:
    Ui::FixedPointVolumeRayCastMapperCT *ui;
};

#endif // FIXEDPOINTVOLUMERAYCASTMAPPERCT_H
