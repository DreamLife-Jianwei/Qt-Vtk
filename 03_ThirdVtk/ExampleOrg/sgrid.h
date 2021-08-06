#ifndef SGRID_H
#define SGRID_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkFloatArray.h"
#include "vtkHedgeHog.h"
#include "vtkMath.h"
#include "vtkNamedColors.h"
#include "vtkNew.h"
#include "vtkPointData.h"
#include "vtkPoints.h"
#include "vtkPolyDataMapper.h"
#include "vtkProperty.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkStructuredGrid.h"

#include "array"
namespace Ui {
class SGrid;
}

class SGrid : public QWidget
{
    Q_OBJECT

public:
    explicit SGrid(QWidget *parent = 0);
    ~SGrid();

private:
    Ui::SGrid *ui;
    vtkNew<vtkNamedColors> colors;
    float rMin = 0.5, rMax = 1.0, deltaRad, deltaZ;
    std::array<int, 3> dims = {{13, 11, 11}};
    vtkNew<vtkStructuredGrid> sgrid;
    vtkNew<vtkFloatArray> vectors;
    vtkNew<vtkPoints> points;
    vtkNew<vtkHedgeHog> hedgehog;
    vtkNew<vtkPolyDataMapper> sgridMapper;
    vtkNew<vtkActor> sgridActor;
    vtkNew<vtkRenderer> renderer;
};

#endif // SGRID_H
