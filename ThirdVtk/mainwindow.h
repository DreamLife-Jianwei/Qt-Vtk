#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QTabBar>

#include "ExampleOrg/ambientspheres.h"
#include "ExampleOrg/marrays.h"
#include "ExampleOrg/cone.h"
#include "ExampleOrg/cone2.h"
#include "ExampleOrg/cone3.h"
#include "ExampleOrg/cone4.h"
#include "ExampleOrg/cone5.h"
#include "ExampleOrg/cone6.h"
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

    void on_actionCone_triggered();

    void on_actionCone2_triggered();

    void on_actionCone3_triggered();

    void on_actionCone4_triggered();

    void on_actionCone5_triggered();

    void on_actionCone6_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AmbientSpheres *mAmbintSpheres = nullptr;
    MArrays *mArrays = nullptr;
    Cone *mCone = nullptr;
    Cone2 *mCone2 = nullptr;
    Cone3 *mCone3 = nullptr;
    Cone4 *mCone4 = nullptr;
    Cone5 *mCone5 = nullptr;
    Cone6 *mCone6 = nullptr;
};

#endif // MAINWINDOW_H
