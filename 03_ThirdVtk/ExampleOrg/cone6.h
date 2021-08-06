#ifndef CONE6_H
#define CONE6_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QTextBrowser>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkCommand.h"
#include "vtkBoxWidget.h"
#include "vtkTransform.h"
#include "vtkInteractorStyleTrackballCamera.h"


namespace Ui {
class Cone6;
}




class vtkMyCallBack : public vtkCommand
{
public:
    static vtkMyCallBack *New()
    {
        return new vtkMyCallBack;
    }
    void Execute(vtkObject *caller, unsigned long eventId, void *callData) override;
};


class Cone6 : public QWidget
{
    Q_OBJECT

public:
    explicit Cone6(QWidget *parent = 0);
    ~Cone6();

    void startInteractor();

private:
    Ui::Cone6 *ui;


    vtkConeSource *cone = nullptr;

    vtkPolyDataMapper *mapper = nullptr;

    vtkActor *actor = nullptr;

    vtkRenderer *render = nullptr;

    vtkRenderWindowInteractor *iren = nullptr;

    vtkInteractorStyleTrackballCamera * style = nullptr;

    vtkBoxWidget *boxWidget = nullptr;

    vtkMyCallBack *callback = nullptr;

};

#endif // CONE6_H
