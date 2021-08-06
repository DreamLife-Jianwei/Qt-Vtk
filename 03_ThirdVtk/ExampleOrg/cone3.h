#ifndef CONE3_H
#define CONE3_H

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
namespace Ui {
class Cone3;
}

class Cone3 : public QWidget
{
    Q_OBJECT

public:
    explicit Cone3(QWidget *parent = 0);
    ~Cone3();

private:
    Ui::Cone3 *ui;

    vtkConeSource *cone = nullptr;                  //声明椎体

    vtkPolyDataMapper *coneMapper = nullptr;        //声明映射器

    vtkActor *coneActor = nullptr;                  //声明Actor

    vtkRenderer *coneRender1 = nullptr,*coneRender2 = nullptr;              //声明渲染器

    QTimer *rotationTimer = nullptr;                //声明定时器，用于旋转椎体
};

#endif // CONE3_H
