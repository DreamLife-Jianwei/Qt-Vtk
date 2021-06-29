#include "mainwindow.h"
#include <QApplication>
#include "vtkOutputWindow.h"
int main(int argc, char *argv[])
{
    //    vtkOutputWindow::SetGlobalWarningDisplay(0);
    VTK_MODULE_INIT(vtkRenderingOpenGL2);
    VTK_MODULE_INIT(vtkInteractionStyle);
    VTK_MODULE_INIT(vtkRenderingFreeType);
    VTK_MODULE_INIT(vtkRenderingContextOpenGL2);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
