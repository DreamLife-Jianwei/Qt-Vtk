#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVTKWidget.h>         //提升空间包含头文件
#include <vtkAutoInit.h>        //启动必须有
#include <vtkOutputWindow.h>    //控制台窗口
#include <vtkSmartPointer.h>    //
#include <vtkJPEGReader.h>
#include <vtkPNGReader.h>
#include <vtkTIFFReader.h>
#include <vtkBMPReader.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkPolyData.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkCellArray.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <array>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief renderJpegImage   渲染jpg资源
     * @param index 窗口号
     * @param temp  资源文件路径
     */
    void renderJpegImage(int index,const char* temp);
    /**
     * @brief renderPngImage    渲染png资源
     * @param index     窗口号
     * @param temp      资源文件路径
     */
    void renderPngImage(int index,const char* temp);
    /**
     * @brief renderTiffImage   渲染tiff资源
     * @param index 窗口号
     * @param temp  资源文件路径
     */
    void renderTiffImage(int index,const char* temp);
    /**
     * @brief renderBmprImage   传染bmp资源
     * @param index 窗口号
     * @param temp  资源文件路径
     */
    void renderBmprImage(int index,const char* temp);
    /**
     * @brief renderDicomImage 渲染Dicom资源
     * @param index 窗口号
     * @param temp  资源路径
     */
    void renderDicomImage(int index,const char* temp);

    void drawVtkCube(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
