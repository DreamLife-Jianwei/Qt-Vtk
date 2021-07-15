#include "mainwindow.h"
#include <QApplication>
#include "vtkOutputWindow.h"
int main(int argc, char *argv[])
{
    //    vtkOutputWindow::SetGlobalWarningDisplay(0);                              //关闭错误输出
    VTK_MODULE_INIT(vtkRenderingOpenGL2);
    VTK_MODULE_INIT(vtkInteractionStyle);
    VTK_MODULE_INIT(vtkRenderingFreeType);
    VTK_MODULE_INIT(vtkRenderingContextOpenGL2);
    QApplication a(argc, argv);
    a.setStyleSheet("QTabWidget::pane{border-style:outset;background:transparent;}"
                    "QMenuBar{background-color:rgb(240,240,240);}"
                    "QSplitter::handle{ background-color:transparent;}");

    MainWindow w;
    w.show();

    return a.exec();
}
