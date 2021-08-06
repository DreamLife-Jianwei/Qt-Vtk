#ifndef RGRID_H
#define RGRID_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkNamedColors.h"
#include "vtkPolyDataMapper.h"
#include "vtkProperty.h"
#include "vtkRectilinearGrid.h"
#include "vtkRectilinearGridGeometryFilter.h"
#include "vtkFloatArray.h"

#include "array"

namespace Ui {
class RGrid;
}

class RGrid : public QWidget
{
    Q_OBJECT

public:
    explicit RGrid(QWidget *parent = 0);
    ~RGrid();

private:
    Ui::RGrid *ui;

    vtkNew<vtkNamedColors> colors;
    //数据直接操作不来吧
    std::array<double, 47> x = {
        {-1.22396,  -1.17188,  -1.11979,  -1.06771,  -1.01562,  -0.963542,
         -0.911458, -0.859375, -0.807292, -0.755208, -0.703125, -0.651042,
         -0.598958, -0.546875, -0.494792, -0.442708, -0.390625, -0.338542,
         -0.286458, -0.234375, -0.182292, -0.130209, -0.078125, -0.026042,
         0.0260415, 0.078125,  0.130208,  0.182291,  0.234375,  0.286458,
         0.338542,  0.390625,  0.442708,  0.494792,  0.546875,  0.598958,
         0.651042,  0.703125,  0.755208,  0.807292,  0.859375,  0.911458,
         0.963542,  1.01562,   1.06771,   1.11979,   1.17188}};
    std::array<double, 33> y = {
        {-1.25,    -1.17188,  -1.09375, -1.01562,  -0.9375,  -0.859375,
         -0.78125, -0.703125, -0.625,   -0.546875, -0.46875, -0.390625,
         -0.3125,  -0.234375, -0.15625, -0.078125, 0,        0.078125,
         0.15625,  0.234375,  0.3125,   0.390625,  0.46875,  0.546875,
         0.625,    0.703125,  0.78125,  0.859375,  0.9375,   1.01562,
         1.09375,  1.17188,   1.25}};
    std::array<double, 44> z = {{0,   0.1,  0.2, 0.3,  0.4, 0.5,  0.6, 0.7, 0.75,
                                 0.8, 0.9,  1,   1.1,  1.2, 1.3,  1.4, 1.5, 1.6,
                                 1.7, 1.75, 1.8, 1.9,  2,   2.1,  2.2, 2.3, 2.4,
                                 2.5, 2.6,  2.7, 2.75, 2.8, 2.9,  3,   3.1, 3.2,
                                 3.3, 3.4,  3.5, 3.6,  3.7, 3.75, 3.8, 3.9}};


    vtkNew<vtkFloatArray> xCoords,yCoords,zCoords;

    vtkNew<vtkRectilinearGrid> rgrid;

    vtkNew<vtkRectilinearGridGeometryFilter> plane;

    vtkNew<vtkPolyDataMapper> mapper;

    vtkNew<vtkActor> actor;
};

#endif // RGRID_H
