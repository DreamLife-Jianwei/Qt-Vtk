#ifndef DIFFUSESPHERES_H
#define DIFFUSESPHERES_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkSmartPointer.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkProperty.h"
#include "vtkCamera.h"
#include "vtkLight.h"


namespace Ui {
class DiffuseSpheres;
}

class DiffuseSpheres : public QWidget
{
    Q_OBJECT

public:
    explicit DiffuseSpheres(QWidget *parent = 0);
    ~DiffuseSpheres();

private:
    Ui::DiffuseSpheres *ui;

    vtkSphereSource *sphere = nullptr;

    vtkPolyDataMapper *mapper = nullptr;

    vtkActor *sphere1 = nullptr,
            *sphere2 = nullptr,
            *sphere3 = nullptr,
            *sphere4 = nullptr,
            *sphere5 = nullptr,
            *sphere6 = nullptr,
            *sphere7 = nullptr,
            *sphere8 = nullptr;

    vtkRenderer *render = nullptr;
};

#endif // DIFFUSESPHERES_H
