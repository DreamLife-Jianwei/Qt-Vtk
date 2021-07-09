#ifndef IMAGEMANAGE_H
#define IMAGEMANAGE_H

#include <QWidget>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QResizeEvent>
#include <QtDebug>

#include "QVTKOpenGLWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkSmartPointer.h"
#include "vtkResliceImageViewer.h"
#include "vtkImagePlaneWidget.h"
#include "vtkDistanceWidget.h"
#include "vtkResliceImageViewerMeasurements.h"
#include "vtkBoundedPlanePointPlacer.h"
#include "vtkCellPicker.h"
#include "vtkCommand.h"
#include "vtkDICOMImageReader.h"
#include "vtkDistanceRepresentation.h"
#include "vtkDistanceRepresentation2D.h"
#include "vtkDistanceWidget.h"
#include <vtkGenericOpenGLRenderWindow.h>
#include "vtkHandleRepresentation.h"
#include "vtkImageData.h"
#include "vtkImageMapToWindowLevelColors.h"
#include "vtkImageSlabReslice.h"
#include "vtkInteractorStyleImage.h"
#include "vtkLookupTable.h"
#include "vtkPlane.h"
#include "vtkPlaneSource.h"
#include "vtkPointHandleRepresentation2D.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkProperty.h"
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include "vtkRenderWindowInteractor.h"
#include "vtkResliceImageViewer.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkResliceImageViewerMeasurements.h"


class vtkResliceCursorCallback;

namespace Ui {
class ImageManage;
}

class ImageManage : public QWidget
{
    Q_OBJECT

public:
    explicit ImageManage(QWidget *parent = nullptr);
    ~ImageManage();
    void setCurrentTab(int temp =0);
public slots:
    /**
     * @brief slot_ReaderDICOMImage
     * @param fn
     * 读取DICOM文件
     */
    void slot_ReaderDICOMImage(const char* fn);
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    Ui::ImageManage *ui;
    QSplitter *mSplitterMain = nullptr;
    QSplitter *mSplitterVertical = nullptr;
    QSplitter *mSplitterUp = nullptr;
    QSplitter *mSplitterDown = nullptr;
    double color[3] = {0,0,0};                                              //颜色
    vtkSmartPointer<vtkDICOMImageReader> reader = nullptr;                  //读取DICOM文件
    int imageDims[3] = {0};                                                 //暂时不理解
    vtkSmartPointer< vtkResliceImageViewer > riw[3];                        //三个二维视图
    vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
    vtkSmartPointer< vtkDistanceWidget > DistanceWidget[3];                 //测试距离的，暂时没有移植，无用
    vtkSmartPointer< vtkResliceImageViewerMeasurements > ResliceMeasurements;   //不知道干啥，没有用到

    vtkSmartPointer<vtkProperty> ipwProp;                                       //属性
    vtkSmartPointer<vtkCellPicker> picker;                                      //拾取器
    vtkSmartPointer< vtkRenderer > ren;                                         //3D渲染器
    vtkSmartPointer<vtkResliceCursorCallback> cbk;                              //回调类

};

#endif // IMAGEMANAGE_H
