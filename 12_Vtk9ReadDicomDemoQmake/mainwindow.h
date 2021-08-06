#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "QVTKOpenGLNativeWidget.h"
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    vtkConeSource *cone = nullptr;                  //声明椎体

    vtkPolyDataMapper *coneMapper = nullptr;        //声明映射器

    vtkActor *coneActor = nullptr;                  //声明Actor

    vtkRenderer *coneRender = nullptr;              //声明渲染器

    QTimer *rotationTimer = nullptr;                //声明定时器，用于旋转椎体
};
#endif // MAINWINDOW_H
