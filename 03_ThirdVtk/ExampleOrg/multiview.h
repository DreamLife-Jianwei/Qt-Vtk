#ifndef MULTIVIEW_H
#define MULTIVIEW_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkAnnotationLink.h"
#include "vtkCommand.h"
#include "vtkDataRepresentation.h"
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
#include "vector"


class ViewUpdater :public vtkCommand
{
public:
    static ViewUpdater* New()
    {
        return new ViewUpdater;
    }
    void AddView(vtkView *view)
    {
        this->Views.push_back(view);
        view->AddObserver(vtkCommand::SelectionChangedEvent,this);
    }

    void Execute(vtkObject*,unsigned long,void*)override
    {
        for(unsigned int i = 0;i<this->Views.size();i++)
        {
            this->Views[i]->Update();
        }
    }


private:
    ViewUpdater() = default;
    ~ViewUpdater() override = default;
    std::vector<vtkView*> Views;
};




namespace Ui {
class MultiView;
}

class MultiView : public QWidget
{
    Q_OBJECT

public:
    explicit MultiView(QWidget *parent = 0);
    ~MultiView();

private:
    Ui::MultiView *ui;

    vtkMutableDirectedGraph *graph = nullptr;

    vtkStringArray* labels = nullptr;

    vtkTree* tree = nullptr;

    vtkGraphLayoutView* view = nullptr;

    vtkGraphLayoutView* view2 = nullptr;

    vtkAnnotationLink* link = nullptr;

    ViewUpdater* update = nullptr;


};

#endif // MULTIVIEW_H
