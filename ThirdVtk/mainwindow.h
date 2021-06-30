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
#include "ExampleOrg/createtree.h"
#include "ExampleOrg/cube.h"
#include "ExampleOrg/cylinder.h"
#include "ExampleOrg/diffusespheres.h"
#include "ExampleOrg/GraphItem/graphitem.h"
#include "ExampleOrg/helloworld.h"
#include "ExampleOrg/labeledmesh.h"
#include "ExampleOrg/multiview.h"
#include "ExampleOrg/piecewiseitem.h"
#include "ExampleOrg/qcharttable.h"
#include "ExampleOrg/qscalarstocolors.h"
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

    void on_actionCreateTree_triggered();

    void on_actionCube_triggered();

    void on_actionCylinder_triggered();

    void on_actionDiffuseSpheres_triggered();

    void on_actionGraphItem_triggered();

    void on_actionHelloWorld_triggered();

    void on_actionLabeledMesh_triggered();

    void on_actionMultiView_triggered();

    void on_actionPiecewiseItem_triggered();

    void on_actionQChartTable_triggered();

    void on_actionQScalarsToColors_triggered();

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
    CreateTree *mCreateTree = nullptr;
    Cube *mCube = nullptr;
    Cylinder *mCylinder = nullptr;
    DiffuseSpheres *mDiffuseSpheres = nullptr;
    GraphItem *mGraphItem = nullptr;
    HelloWorld *mHelloWorld = nullptr;
    LabeledMesh *mLabeldMesh = nullptr;
    MultiView *mMultiview = nullptr;
    PiecewiseItem *mPiecewiseItem = nullptr;
    QChartTable *mQchartTable = nullptr;
    QScalarsToColors *mQScalarsToColors = nullptr;
};

#endif // MAINWINDOW_H
