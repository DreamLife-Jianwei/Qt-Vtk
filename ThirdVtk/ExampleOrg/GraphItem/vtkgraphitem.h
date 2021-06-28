#ifndef VTKGRAPHITEM_H
#define VTKGRAPHITEM_H


#include "vtkContextItem.h"

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



protected:


    vtkGraph *Graph;

};

#endif // VTKGRAPHITEM_H
