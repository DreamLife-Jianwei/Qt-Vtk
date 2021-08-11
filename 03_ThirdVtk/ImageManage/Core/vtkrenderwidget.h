#ifndef VTKRENDERWIDGET_H
#define VTKRENDERWIDGET_H


/***********Qt*******************/
#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <QColor>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QResizeEvent>

/***********VTK*******************/
#include "vtkRenderWindow.h"
#include "QVTKInteractor.h"
#include "myqvtkopenglnativewidget.h"

namespace Ui {
class VTKRenderWidget;
}

class VTKRenderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VTKRenderWidget(QWidget *parent = nullptr);
    ~VTKRenderWidget();

    /**
     * @brief set_BackGroundColor
     * 设置背景颜色 RGBA
     * @param r
     * @param g
     * @param b
     * @param a
     */
    void set_BackGroundColor(int r=0,int g=0,int b = 0,int a = 255);
    /**
     * @brief set_OpenFolderEnable
     * 设置文档提示开关
     * @param enable
     */
    void set_OpenFolderEnable(bool enable = false);

    //------------------------------------------------------------------------------------

    vtkRenderWindow* renderWindow() const;

    QVTKInteractor* interactor() const;

    void setRenderWindow(vtkGenericOpenGLRenderWindow* win);

    void setRenderWindow(vtkRenderWindow* win);
signals:
    void signal_mouseDoubleClicked();

private:
    /**
     * @brief paintEvent
     * 重写绘图时间
     * @param event
     */
    void paintEvent(QPaintEvent *event);
    /**
     * @brief resizeEvent
     * 重置窗口尺寸
     * @param event
     */
    void resizeEvent(QResizeEvent *event);
    /**
     * @brief enterEvent
     * 鼠标进入事件
     * @param event
     */
    void enterEvent(QEvent  *event);
    /**
     * @brief leaveEvent
     * 鼠标离开事件
     * @param event
     */
    void leaveEvent(QEvent *event);

private:
    Ui::VTKRenderWidget *ui;
    QColor m_BackGroundColor = QColor(255,255,0,255);           //背景颜色

    QLabel *m_OpenFolderText = nullptr;                         //打开文件夹提示


    QMenu *m_Menu_1 = nullptr;
    QAction *test = nullptr;
    QAction *test1 = nullptr;

};

#endif // VTKRENDERWIDGET_H
