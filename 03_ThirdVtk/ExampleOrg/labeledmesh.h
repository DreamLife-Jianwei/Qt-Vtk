#ifndef LABELEDMESH_H
#define LABELEDMESH_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkSmartPointer.h"
#include "vtkPoints.h"
#include "vtkCellArray.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper2D.h"
#include "vtkActor2D.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkIdFilter.h"
#include "vtkRenderer.h"
#include "vtkSelectVisiblePoints.h"
#include "vtkLabeledDataMapper.h"
#include "vtkCellCenters.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkTextProperty.h"

static int xLength;
static int yLength;
static vtkSmartPointer<vtkSelectVisiblePoints> visPts;
static vtkSmartPointer<vtkSelectVisiblePoints> visCells;
static vtkSmartPointer<vtkPoints> pts;
static vtkSmartPointer<vtkRenderWindow>renwin;





namespace Ui {
class LabeledMesh;
}

class LabeledMesh : public QWidget
{
    Q_OBJECT

public:
    explicit LabeledMesh(QWidget *parent = 0);
    ~LabeledMesh();

    void PlaceWindow(int xmin, int ymin);

    void MoveWindow();


private:
    Ui::LabeledMesh *ui;
};

#endif // LABELEDMESH_H
