#ifndef MARRAYS_H
#define MARRAYS_H

#include <QWidget>
#include "QVTKOpenGLWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkActor.h"
#include "vtkCellArray.h"
#include "vtkDoubleArray.h"
#include "vtkFloatArray.h"
#include "vtkIntArray.h"
#include "vtkNamedColors.h"
#include "vtkNew.h"
#include "vtkPointData.h"
#include "vtkPoints.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include <array>
namespace Ui {
class MArrays;
}

class MArrays : public QWidget
{
    Q_OBJECT

public:
    explicit MArrays(QWidget *parent = 0);
    ~MArrays();

private:
    Ui::MArrays *ui;

    vtkNew<vtkNamedColors> colors;              //新建颜色对象
    vtkNew<vtkDoubleArray> pcoords;             //新建Double数组

    std::array<std::array<double,3>,4> pts = {{{{0.0, 0.0, 0.0}},
                                               {{0.0, 1.0, 0.0}},
                                               {{1.0, 0.0, 0.0}},
                                               {{1.0, 1.0, 0.0}}}};     //新建Double 二维数组

    vtkNew<vtkPoints> points;                   //新建坐标点

    vtkNew<vtkCellArray> strips;

    vtkNew<vtkIntArray> temperature;

    vtkNew<vtkDoubleArray> vorticity;

    vtkNew<vtkPolyData> polydata;

    vtkNew<vtkPolyDataMapper> mapper;

    vtkNew<vtkActor> actor;

    vtkNew<vtkRenderer> render;

};

#endif // MARRAYS_H
