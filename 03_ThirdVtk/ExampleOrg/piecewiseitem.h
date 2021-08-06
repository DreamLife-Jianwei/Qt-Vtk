#ifndef PIECEWISEITEM_H
#define PIECEWISEITEM_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"

#include "vtkSmartPointer.h"
#include "vtkContextView.h"
#include "vtkContextScene.h"
#include "vtkPiecewiseFunction.h"
#include "vtkPiecewiseFunctionItem.h"
#include "vtkPiecewiseControlPointsItem.h"

namespace Ui {
class PiecewiseItem;
}

class PiecewiseItem : public QWidget
{
    Q_OBJECT

public:
    explicit PiecewiseItem(QWidget *parent = 0);
    ~PiecewiseItem();

private:
    Ui::PiecewiseItem *ui;

    vtkSmartPointer<vtkContextView> view = nullptr;
    vtkSmartPointer<vtkPiecewiseFunction> source = nullptr;
    vtkSmartPointer<vtkPiecewiseControlPointsItem> item = nullptr;
};

#endif // PIECEWISEITEM_H
