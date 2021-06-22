#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    vtkOutputWindow::SetGlobalWarningDisplay(0);    //关闭窗口控制台,位置要正确
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
