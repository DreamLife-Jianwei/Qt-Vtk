#ifndef CREATETREE_H
#define CREATETREE_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"

#include "vtkDataSetAttributes.h"
#include "vtkGraphLayoutView.h"
#include "vtkMutableDirectedGraph.h"
#include "vtkRandomGraphSource.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkStringArray.h"
#include "vtkTree.h"
#include "vtkViewTheme.h"

namespace Ui {
class CreateTree;
}

class CreateTree : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTree(QWidget *parent = 0);
    ~CreateTree();

    void startInteractor();

private:
    Ui::CreateTree *ui;


    vtkMutableDirectedGraph *graph = nullptr;

    vtkStringArray *lables = nullptr;


    vtkTree *tree = nullptr;

    vtkGraphLayoutView *view = nullptr;

    vtkViewTheme *theme = nullptr;

};

#endif // CREATETREE_H
