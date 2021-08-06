#ifndef VTKGRAPHITEM_H
#define VTKGRAPHITEM_H

#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkContextItem.h"

#include "vtkEdgeListIterator.h"
#include "vtkOutEdgeIterator.h"
#include "vtkGraph.h"
#include "vtkMinimalStandardRandomSequence.h"
#include "vtkVariant.h"

#include "vtkContext2D.h"
#include "vtkContextScene.h"
#include "vtkContextMouseEvent.h"
#include "vtkPen.h"
#include "vtkBrush.h"
#include "vtkTextProperty.h"
#include "vtkTransform2D.h"


#include "vtkObjectFactory.h"
#include "vtkSmartPointer.h"

#include "utility"
#include "vector"

class vtkContext2D;
class vtkGraph;


class vtkGraphItem : public vtkContextItem
{

public:
    vtkTypeMacro(vtkGraphItem,vtkContextItem);
    void PrintSelf(ostream &os, vtkIndent indent) override;
    static vtkGraphItem *New();
    vtkGetObjectMacro(Graph,vtkGraph);
    virtual void SetGraph(vtkGraph* g);


    bool Paint(vtkContext2D *painter) override;

    bool Hit(const vtkContextMouseEvent &mouse)override;

    bool MouseEnterEvent(const vtkContextMouseEvent &mouse)override;

    bool MouseMoveEvent(const vtkContextMouseEvent &mouse)override;

    bool MouseLeaveEvent(const vtkContextMouseEvent &mouse)override;

    bool MouseButtonPressEvent(const vtkContextMouseEvent &mouse)override;

    bool MouseButtonReleaseEvent(const vtkContextMouseEvent &mouse)override;

    void UpdatePositions();



protected:

    vtkGraphItem();
    ~vtkGraphItem() override;

    float LastPosition[2];
    bool MouseOver;
    int MouseButtonPressed;


    vtkGraph *Graph;
    vtkIdType HitVertex;

    class Implementation;

    Implementation *Impl;

private:
    vtkGraphItem(const vtkGraphItem &) = delete;
    void operator =(const vtkGraphItem &) = delete;

};

#endif // VTKGRAPHITEM_H
