#ifndef CUBE_H
#define CUBE_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkCellArray.h"
#include "vtkFloatArray.h"
#include "vtkNamedColors.h"
#include "vtkNew.h"
#include "vtkPointData.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "array"
namespace Ui {
class Cube;
}

class Cube : public QWidget
{
    Q_OBJECT

public:
    explicit Cube(QWidget *parent = 0);
    ~Cube();

private:
    Ui::Cube *ui;

    std::array<std::array<double,3>,8> pts;

    std::array<std::array<vtkIdType,4>,6> ordering;

    vtkPolyData *cube = nullptr;

    vtkPoints *points = nullptr;

    vtkCellArray *polys = nullptr;

    vtkFloatArray *scalars = nullptr;

    vtkNamedColors *colors = nullptr;

    vtkPolyDataMapper *mapper = nullptr;

    vtkActor *actor = nullptr;

    vtkRenderer *render = nullptr;




};

#endif // CUBE_H
