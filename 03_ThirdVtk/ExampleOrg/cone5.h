#ifndef CONE5_H
#define CONE5_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QTextBrowser>
#include <QResizeEvent>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkConeSource.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkActor.h"
#include "vtkCamera.h"


namespace Ui {
class Cone5;
}

class Cone5 : public QWidget
{
    Q_OBJECT

public:
    explicit Cone5(QWidget *parent = 0);
    ~Cone5();

    void startiren();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Cone5 *ui;

    vtkConeSource *cone = nullptr;

    vtkPolyDataMapper *mapper = nullptr;

    vtkActor *actor = nullptr;

    vtkRenderer *render = nullptr;

    vtkRenderWindowInteractor *iren = nullptr;

    vtkInteractorStyleTrackballCamera *style = nullptr;
};

#endif // CONE5_H
