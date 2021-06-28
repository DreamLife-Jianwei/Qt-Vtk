#ifndef GRAPHITEM_H
#define GRAPHITEM_H

#include <QWidget>
#include "QVTKOpenGLWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"


#include "vtkCommand.h"
#include "vtkRandomGraphSource.h"
#include "vtkGraph.h"
#include "vtkgraphitem.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkContextView.h"
#include "vtkContextScene.h"

#include "vtkObjectFactory.h"


class GraphAnimate : public vtkCommand
{
    static GraphAnimate *New(){return new GraphAnimate();}
    vtkTypeMacro(GraphAnimate,vtkCommand);
    void Execute(vtkObject *caller, unsigned long eventId, void *callData) override
    {
        this->GraphItem->UpDatePositions();
        this->view->Render();
        this->view->GetRenderWindow()->GetInteractor()->CreateOneShotTimer(10);
    }
    vtkGraphItem *GraphItem;
    vtkContextView *view;
};




namespace Ui {
class GraphItem;
}

class GraphItem : public QWidget
{
    Q_OBJECT

public:
    explicit GraphItem(QWidget *parent = nullptr);
    ~GraphItem();

private:
    Ui::GraphItem *ui;
};

#endif // GRAPHITEM_H
