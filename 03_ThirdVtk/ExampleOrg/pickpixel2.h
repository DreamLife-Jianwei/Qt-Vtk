#ifndef PICKPIXEL2_H
#define PICKPIXEL2_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAssemblyPath.h"
#include "vtkCell.h"
#include "vtkCommand.h"
#include "vtkCornerAnnotation.h"
#include "vtkImageActor.h"
#include "vtkImageCast.h"
#include "vtkImageData.h"
#include "vtkImageNoiseSource.h"
#include "vtkImageViewer2.h"
#include "vtkInteractorStyleImage.h"
#include "vtkMath.h"
#include "vtkNamedColors.h"
#include "vtkNew.h"
#include "vtkPointData.h"
#include "vtkPropPicker.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"
#include "vtkTIFFReader.h"
#include "vtkTextProperty.h"

class vtkImageInteractionCallback;

namespace Ui {
class PickPixel2;
}

class PickPixel2 : public QWidget
{
    Q_OBJECT

public:
    explicit PickPixel2(QWidget *parent = nullptr);
    ~PickPixel2();

private:
    Ui::PickPixel2 *ui;
    vtkNew<vtkNamedColors> colors;
    vtkNew<vtkImageViewer2> imageViewer;
    vtkNew<vtkImageNoiseSource> noiseSource;
    vtkNew<vtkImageCast> imageCast;
    vtkNew<vtkPropPicker> propPicker;
    vtkImageActor* imageActor = nullptr;
    vtkRenderer* renderer = nullptr;
    vtkNew<vtkCornerAnnotation> cornerAnnotation;

    vtkNew<vtkImageInteractionCallback> callback;
    vtkInteractorStyleImage* imageStyle;
};

#endif // PICKPIXEL2_H
