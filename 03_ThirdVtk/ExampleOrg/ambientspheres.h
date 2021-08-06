#ifndef AMBIENTSPHERES_H
#define AMBIENTSPHERES_H

#include <QWidget>

#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkSmartPointer.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkProperty.h"
#include "vtkCamera.h"
#include "vtkLight.h"

namespace Ui {
class AmbientSpheres;
}

class AmbientSpheres : public QWidget
{
    Q_OBJECT

public:
    explicit AmbientSpheres(QWidget *parent = 0);
    ~AmbientSpheres();



private:
    Ui::AmbientSpheres *ui;

    vtkSmartPointer<vtkSphereSource> sphere = nullptr;

    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = nullptr;

    vtkSmartPointer<vtkActor>   sphere1 = nullptr,
                                sphere2 = nullptr,
                                sphere3 = nullptr,
                                sphere4 = nullptr,
                                sphere5 = nullptr,
                                sphere6 = nullptr,
                                sphere7 = nullptr,
                                sphere8 = nullptr;

    vtkSmartPointer<vtkRenderer> renderer = nullptr;


    vtkSmartPointer<vtkLight> light = nullptr;
};

#endif // AMBIENTSPHERES_H
