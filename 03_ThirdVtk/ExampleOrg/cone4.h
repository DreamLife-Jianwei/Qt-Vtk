#ifndef CONE4_H
#define CONE4_H

#include <QWidget>
#include <QTimer>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkProperty.h"

namespace Ui {
class Cone4;
}

class Cone4 : public QWidget
{
    Q_OBJECT

public:
    explicit Cone4(QWidget *parent = 0);
    ~Cone4();

private:
    Ui::Cone4 *ui;


    vtkConeSource *cone = nullptr;

    vtkPolyDataMapper *mapper = nullptr;

    vtkActor *actor1 = nullptr,*actor2 = nullptr;

    vtkProperty *property = nullptr;

    vtkRenderer *render = nullptr;

    QTimer *rotateTimer = nullptr;




};

#endif // CONE4_H
