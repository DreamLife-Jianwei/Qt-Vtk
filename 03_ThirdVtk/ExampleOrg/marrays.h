#ifndef MARRAYS_H
#define MARRAYS_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
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

    vtkNew<vtkCellArray> strips;                //暂时不清楚

    vtkNew<vtkIntArray> temperature;            //暂时不了解

    vtkNew<vtkDoubleArray> vorticity;           //Double 数组

    vtkNew<vtkPolyData> polydata;               //PolyData格式的数据

    vtkNew<vtkPolyDataMapper> mapper;           //映射器

    vtkNew<vtkActor> actor;                     //就是Actor

    vtkNew<vtkRenderer> render;                 //渲染

};

#endif // MARRAYS_H
