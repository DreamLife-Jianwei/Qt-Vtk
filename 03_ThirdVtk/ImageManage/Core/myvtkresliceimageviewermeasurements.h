#ifndef MYVTKRESLICEIMAGEVIEWERMEASUREMENTS_H
#define MYVTKRESLICEIMAGEVIEWERMEASUREMENTS_H

#include "vtkInteractionImageModule.h"
#include "vtkObject.h"

class MyVtkResliceImageViewer;
class vtkAbstractWidget;
class vtkCallbackCommand;
class vtkCollection;
class vtkDistanceWidget;
class vtkAngleWidget;
class vtkBiDimensionalWidget;
class vtkHandleRepresentation;
class vtkHandleWidget;
class vtkCaptionWidget;
class vtkContourWidget;
class vtkSeedWidget;

class MyVtkResliceImageViewerMeasurements : public vtkObject
{
public:
    static MyVtkResliceImageViewerMeasurements* New();
    vtkTypeMacro(MyVtkResliceImageViewerMeasurements,vtkObject);
    void PrintSelf(ostream& os,vtkIndent indent) override;
    virtual void Render();
    virtual void AddItem(vtkAbstractWidget*w);
    virtual void RemoveItem(vtkAbstractWidget*w);
    virtual void RemoveAllItems();
    vtkSetClampMacro(ProcessEvents, vtkTypeBool, 0, 1);
    vtkGetMacro(ProcessEvents,vtkTypeBool);
    vtkBooleanMacro(ProcessEvents, vtkTypeBool);
    vtkSetMacro(Tolerance, double);
    vtkGetMacro(Tolerance, double);
    virtual void SetResliceImageViewer(MyVtkResliceImageViewer*i);
    vtkGetObjectMacro(ResliceImageViewer, MyVtkResliceImageViewer);
    virtual void Update();
protected:
    MyVtkResliceImageViewerMeasurements();
    ~MyVtkResliceImageViewerMeasurements() override;
    bool IsItemOnReslicedPlane(vtkAbstractWidget* w);
    bool IsWidgetOnReslicedPlane(vtkDistanceWidget* w);
    bool IsWidgetOnReslicedPlane(vtkAngleWidget* w);
    bool IsWidgetOnReslicedPlane(vtkBiDimensionalWidget* w);
    bool IsWidgetOnReslicedPlane(vtkCaptionWidget* w);
    bool IsWidgetOnReslicedPlane(vtkContourWidget* w);
    bool IsWidgetOnReslicedPlane(vtkSeedWidget* w);
    bool IsWidgetOnReslicedPlane(vtkHandleWidget* w);
    bool IsPointOnReslicedPlane(vtkHandleRepresentation* h);
    bool IsPositionOnReslicedPlane(double p[3]);
    static void ProcessEventsHandler(vtkObject *object,unsigned long event,void *clientdata,void *calldata);
    MyVtkResliceImageViewer *ResliceImageViewer;
    vtkCollection *WidgetCollection;
    vtkCallbackCommand *EventCallbackCommand;
    vtkTypeBool ProcessEvents;
    double Tolerance;
private:
    MyVtkResliceImageViewerMeasurements(const MyVtkResliceImageViewerMeasurements&) = delete;
    void operator=(MyVtkResliceImageViewerMeasurements&) = delete;
};

#endif // MYVTKRESLICEIMAGEVIEWERMEASUREMENTS_H
