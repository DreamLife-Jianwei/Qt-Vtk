#ifndef CONE_H
#define CONE_H

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
class Cone;
}

class Cone : public QWidget
{
    Q_OBJECT

public:
    explicit Cone(QWidget *parent = 0);
    ~Cone();

private:
    Ui::Cone *ui;

    vtkConeSource *cone = nullptr;                  //声明椎体

    vtkPolyDataMapper *coneMapper = nullptr;        //声明映射器

    vtkActor *coneActor = nullptr;                  //声明Actor

    vtkRenderer *coneRender = nullptr;              //声明渲染器

    QTimer *rotationTimer = nullptr;                //声明定时器，用于旋转椎体
};

#endif // CONE_H
