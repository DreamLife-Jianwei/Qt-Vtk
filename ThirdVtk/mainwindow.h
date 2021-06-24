#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QTabBar>
#include "ExampleOrg/ambientspheres.h"
#include "ExampleOrg/marrays.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void resizeEvent(QResizeEvent *event);

private slots:
    void on_actionAmbientSpheres_triggered();

    void on_actionArrays_triggered();

private:
    Ui::MainWindow *ui;
    AmbientSpheres *mAmbintSpheres = nullptr;
    MArrays *mArrays = nullptr;
};

#endif // MAINWINDOW_H
