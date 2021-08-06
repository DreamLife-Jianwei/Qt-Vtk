#ifndef SPECULARSPHERES_H
#define SPECULARSPHERES_H

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
class SpecularSpheres;
}

class SpecularSpheres : public QWidget
{
    Q_OBJECT

public:
    explicit SpecularSpheres(QWidget *parent = 0);
    ~SpecularSpheres();

private:
    Ui::SpecularSpheres *ui;

    vtkSmartPointer<vtkSphereSource> sphere = nullptr;


    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =nullptr;

    vtkSmartPointer<vtkActor> sphere1 =nullptr,sphere2 =nullptr,sphere3 =nullptr,sphere4 =nullptr,sphere5 =nullptr,sphere6 =nullptr,sphere7 =nullptr,sphere8 =nullptr;

    vtkSmartPointer<vtkRenderer> render = nullptr;

    vtkSmartPointer<vtkLight> light = nullptr;

};

#endif // SPECULARSPHERES_H
