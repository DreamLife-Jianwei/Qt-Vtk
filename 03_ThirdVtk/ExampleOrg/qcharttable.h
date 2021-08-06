#ifndef QCHARTTABLE_H
#define QCHARTTABLE_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkChartXY.h"
#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkFloatArray.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkMath.h"
#include "vtkNew.h"
#include "vtkPlot.h"
#include "vtkQtTableView.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkTable.h"
#include "vtkTimerLog.h"

#include "QHBoxLayout"
#include "QSurfaceFormat"
#include "QResizeEvent"
namespace Ui {
class QChartTable;
}

class QChartTable : public QWidget
{
    Q_OBJECT

public:
    explicit QChartTable(QWidget *parent = 0);
    ~QChartTable();

    void resizeEvent(QResizeEvent *event);

private:
    Ui::QChartTable *ui;

    QVTKOpenGLNativeWidget *qvtkWidget = nullptr;

    vtkNew<vtkGenericOpenGLRenderWindow> renderWidow;

    vtkNew<vtkContextView> view;

    vtkNew<vtkTable> table;

    vtkNew<vtkFloatArray> arrX;

    vtkNew<vtkFloatArray> arrC;

    vtkNew<vtkFloatArray> arrS;

    vtkNew<vtkTimerLog> timers;

    vtkNew<vtkChartXY> chart;

    vtkNew<vtkQtTableView> tableview;

    vtkPlot *line = nullptr;
};

#endif // QCHARTTABLE_H
