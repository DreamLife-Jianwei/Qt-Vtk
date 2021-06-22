#include "mainwindow.h"
#include <QApplication>
#include "vtkOutputWindow.h"
int main(int argc, char *argv[])
{
//    vtkOutputWindow::SetGlobalWarningDisplay(0);
    VTK_MODULE_INIT(vtkRenderingOpenGL2);
    VTK_MODULE_INIT(vtkInteractionStyle);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
