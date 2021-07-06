#ifndef IMAGEMANAGE_H
#define IMAGEMANAGE_H

#include <QWidget>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QResizeEvent>
#include <QEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include "QVTKOpenGLWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkDICOMImageReader.h"
#include "vtkSmartPointer.h"
#include "vtkImageData.h"
#include "vtkResliceImageViewer.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkCellPicker.h"
#include "vtkProperty.h"
#include "vtkImagePlaneWidget.h"


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
    bool eventFilter(QObject *watched, QEvent *event)override;

private:
    Ui::ImageManage *ui;
    QSplitter *mSplitterMain = nullptr;
    QSplitter *mSplitterVertical = nullptr;
    QSplitter *mSplitterUp = nullptr;
    QSplitter *mSplitterDown = nullptr;
    double color[3] = {1,1,0};

    vtkSmartPointer<vtkDICOMImageReader> imageReader = nullptr;
    int imageDims[3] = {0};
    vtkSmartPointer<vtkResliceImageViewer> riw[3];

    vtkSmartPointer<vtkCellPicker> picker;

    vtkSmartPointer<vtkProperty> ipwProp;

    vtkSmartPointer<vtkRenderer> render;

    vtkSmartPointer<vtkRenderWindowInteractor> iren;

    vtkSmartPointer<vtkImagePlaneWidget> planeWidget[3];



};

#endif // IMAGEMANAGE_H
