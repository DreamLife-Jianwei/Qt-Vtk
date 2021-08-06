#ifndef CONE2_H
#define CONE2_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QTextBrowser>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkCommand.h"
namespace Ui {
class Cone2;
}




class vtkMyCallback : public vtkCommand
{

public:
    static vtkMyCallback *New()
    {
        return new vtkMyCallback;
    }
    void Execute(vtkObject *caller,unsigned long,void*) override;

    QTextBrowser *textBrowser = nullptr;

private:


};



class Cone2 : public QWidget
{
    Q_OBJECT

public:
    explicit Cone2(QWidget *parent = nullptr);
    ~Cone2();
    void outputMessage(double temp);

private:
    Ui::Cone2 *ui;
    vtkConeSource *cone = nullptr;                  //声明椎体

    vtkPolyDataMapper *coneMapper = nullptr;        //声明映射器

    vtkActor *coneActor = nullptr;                  //声明Actor

    vtkRenderer *coneRender = nullptr;              //声明渲染器

    QTimer *rotationTimer = nullptr;                //声明定时器，用于旋转椎体

    vtkMyCallback *myCallBack = nullptr;
};

#endif // CONE2_H
