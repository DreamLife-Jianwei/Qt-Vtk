#ifndef QSCALARSTOCOLORS_H
#define QSCALARSTOCOLORS_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkChartXY.h"
#include "vtkColorTransferFunction.h"
#include "vtkCompositeTransferFunctionItem.h"
#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkFloatArray.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkMath.h"
#include "vtkNew.h"
#include "vtkPiecewiseFunction.h"
#include "vtkPlot.h"
#include "vtkQtTableView.h"
#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkTimerLog.h"
#include <QResizeEvent>
namespace Ui {
class QScalarsToColors;
}

class QScalarsToColors : public QWidget
{
    Q_OBJECT

public:
    explicit QScalarsToColors(QWidget *parent = 0);
    ~QScalarsToColors();


    void resizeEvent(QResizeEvent *event)override;

private:
    Ui::QScalarsToColors *ui;

    QVTKOpenGLNativeWidget *qvtkWidget = nullptr;

    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;

    vtkNew<vtkContextView> view;
};

#endif // QSCALARSTOCOLORS_H
