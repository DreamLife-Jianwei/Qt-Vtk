#ifndef CYLINDER_H
#define CYLINDER_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"


#include "vtkCylinderSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkProperty.h"
#include "vtkCamera.h"
#include "vtkActor.h"


namespace Ui {
class Cylinder;
}

class Cylinder : public QWidget
{
    Q_OBJECT

public:
    explicit Cylinder(QWidget *parent = 0);
    ~Cylinder();

private:
    Ui::Cylinder *ui;

    vtkCylinderSource *cylinder = nullptr;

    vtkPolyDataMapper *mapper = nullptr;

    vtkActor *actor = nullptr;

    vtkRenderer *render = nullptr;


};

#endif // CYLINDER_H
