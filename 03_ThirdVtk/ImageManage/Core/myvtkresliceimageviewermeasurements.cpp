#include "myvtkresliceimageviewermeasurements.h"

#include "vtkAngleRepresentation.h"
#include "vtkAngleWidget.h"
#include "vtkBiDimensionalRepresentation.h"
#include "vtkBiDimensionalWidget.h"
#include "vtkCallbackCommand.h"
#include "vtkCamera.h"
#include "vtkCaptionRepresentation.h"
#include "vtkCaptionWidget.h"
#include "vtkCommand.h"
#include "vtkContourRepresentation.h"
#include "vtkContourWidget.h"
#include "vtkDistanceRepresentation.h"
#include "vtkDistanceWidget.h"
#include "vtkHandleRepresentation.h"
#include "vtkHandleWidget.h"
#include "vtkImageActor.h"
#include "vtkImageData.h"
#include "vtkObjectFactory.h"
#include "vtkPlane.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkResliceCursor.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursorWidget.h"
#include "myvtkresliceimageviewer.h"
#include "vtkSeedRepresentation.h"
#include "vtkSeedWidget.h"
#include "vtkSmartPointer.h"

vtkStandardNewMacro(MyVtkResliceImageViewerMeasurements);

MyVtkResliceImageViewerMeasurements::MyVtkResliceImageViewerMeasurements()
{
    this->ResliceImageViewer = nullptr;
    this->WidgetCollection = vtkCollection::New();
    this->EventCallbackCommand = vtkCallbackCommand::New();
    this->EventCallbackCommand->SetClientData(this);
    this->EventCallbackCommand->SetCallback(MyVtkResliceImageViewerMeasurements::ProcessEventsHandler);
    this->ProcessEvents = 1;
    this->Tolerance = 6;
}
void MyVtkResliceImageViewerMeasurements::PrintSelf(std::ostream &os, vtkIndent indent)
{
    this->Superclass::PrintSelf(os, indent);
    os << indent << "ResliceImageViewer: " << this->ResliceImageViewer << "\n";
    os << indent << "WidgetCollection: " << this->WidgetCollection << endl;
    this->WidgetCollection->PrintSelf(os, indent.GetNextIndent());
    os << indent << "ProcessEvents: " << (this->ProcessEvents ? "On" : "Off") << "\n";
    os << indent << "Tolerance: " << this->Tolerance << endl;
}
void MyVtkResliceImageViewerMeasurements::Render()
{
    this->ResliceImageViewer->Render();
}

void MyVtkResliceImageViewerMeasurements::AddItem(vtkAbstractWidget *w)
{
    this->WidgetCollection->AddItem(w);
}

void MyVtkResliceImageViewerMeasurements::RemoveItem(vtkAbstractWidget *w)
{
    this->WidgetCollection->RemoveItem(w);
}

void MyVtkResliceImageViewerMeasurements::RemoveAllItems()
{
    this->WidgetCollection->RemoveAllItems();
}

void MyVtkResliceImageViewerMeasurements::SetResliceImageViewer(MyVtkResliceImageViewer *i)
{
    this->ResliceImageViewer = i;
    if (i)
    {
      i->GetResliceCursor()->AddObserver(vtkResliceCursorWidget::ResliceAxesChangedEvent, this->EventCallbackCommand);
      i->GetResliceCursor()->AddObserver(vtkResliceCursorWidget::ResliceAxesChangedEvent, this->EventCallbackCommand);
    }
}
MyVtkResliceImageViewerMeasurements::~MyVtkResliceImageViewerMeasurements()
{
    if(this->ResliceImageViewer)
        this->ResliceImageViewer->GetResliceCursor()->RemoveObservers(vtkResliceCursorWidget::ResliceAxesChangedEvent,this->EventCallbackCommand);
    this->WidgetCollection->Delete();
    this->EventCallbackCommand->Delete();
}

bool MyVtkResliceImageViewerMeasurements::IsItemOnReslicedPlane(vtkAbstractWidget *w)
{
    if(vtkDistanceWidget *dw = vtkDistanceWidget::SafeDownCast(w))
        return this->IsWidgetOnReslicedPlane(dw);
    if(vtkAngleWidget *aw = vtkAngleWidget::SafeDownCast(w))
        return this->IsWidgetOnReslicedPlane(aw);
    if(vtkBiDimensionalWidget *aw = vtkBiDimensionalWidget::SafeDownCast(w))
        return this->IsWidgetOnReslicedPlane(aw);
    if(vtkCaptionWidget *capw = vtkCaptionWidget::SafeDownCast(w))
        return IsWidgetOnReslicedPlane(capw);
    if(vtkContourWidget *capw = vtkContourWidget::SafeDownCast(w))
        return this->IsWidgetOnReslicedPlane(capw);
    if(vtkSeedWidget *s = vtkSeedWidget::SafeDownCast(w))
        return this->IsWidgetOnReslicedPlane(s);
    if(vtkHandleWidget *s = vtkHandleWidget::SafeDownCast(w))
        return this->IsWidgetOnReslicedPlane(s);
    return true;
}

bool MyVtkResliceImageViewerMeasurements::IsWidgetOnReslicedPlane(vtkDistanceWidget *w)
{
    if(w->GetWidgetState() != vtkDistanceWidget::Manipulate)
        return true;
    if(vtkDistanceRepresentation *rep = vtkDistanceRepresentation::SafeDownCast(w->GetRepresentation()))
        return this->IsPointOnReslicedPlane(rep->GetPoint1Representation()) && this->IsPointOnReslicedPlane(rep->GetPoint2Representation());
    return true;
}

bool MyVtkResliceImageViewerMeasurements::IsWidgetOnReslicedPlane(vtkAngleWidget *w)
{
    if (w->GetWidgetState() != vtkAngleWidget::Manipulate)
        return true;
    if (vtkAngleRepresentation* rep = vtkAngleRepresentation::SafeDownCast(w->GetRepresentation()))
        return this->IsPointOnReslicedPlane(rep->GetPoint1Representation()) && this->IsPointOnReslicedPlane(rep->GetPoint2Representation()) && this->IsPointOnReslicedPlane(rep->GetCenterRepresentation());
    return true;
}

bool MyVtkResliceImageViewerMeasurements::IsWidgetOnReslicedPlane(vtkBiDimensionalWidget *w)
{
    if (w->GetWidgetState() != vtkBiDimensionalWidget::Manipulate)
        return true;
    if (vtkBiDimensionalRepresentation* rep = vtkBiDimensionalRepresentation::SafeDownCast(w->GetRepresentation()))
        return this->IsPointOnReslicedPlane(rep->GetPoint1Representation()) && this->IsPointOnReslicedPlane(rep->GetPoint2Representation()) && this->IsPointOnReslicedPlane(rep->GetPoint3Representation()) && this->IsPointOnReslicedPlane(rep->GetPoint4Representation());
    return true;
}

bool MyVtkResliceImageViewerMeasurements::IsWidgetOnReslicedPlane(vtkCaptionWidget *w)
{
    if (vtkCaptionRepresentation* rep = vtkCaptionRepresentation::SafeDownCast(w->GetRepresentation()))
        return this->IsPointOnReslicedPlane(rep->GetAnchorRepresentation());
    return true;
}

bool MyVtkResliceImageViewerMeasurements::IsWidgetOnReslicedPlane(vtkContourWidget *w)
{
    if (w->GetWidgetState() != vtkContourWidget::Manipulate)
        return true;
    if (vtkContourRepresentation* rep = vtkContourRepresentation::SafeDownCast(w->GetRepresentation()))
    {
        const int nNodes = rep->GetNumberOfNodes();
        for (int i = 0; i < nNodes; i++)
        {
            double p[3];
            rep->GetNthNodeWorldPosition(i, p);
            if (this->IsPositionOnReslicedPlane(p) == false)
                return false;
        }
    }
    return true;
}

bool MyVtkResliceImageViewerMeasurements::IsWidgetOnReslicedPlane(vtkSeedWidget *w)
{
    if (vtkSeedRepresentation* rep = vtkSeedRepresentation::SafeDownCast(w->GetRepresentation()))
    {
        const int nNodes = rep->GetNumberOfSeeds();
        for (int i = 0; i < nNodes; i++)
        {
            w->GetSeed(i)->GetHandleRepresentation()->SetVisibility(w->GetEnabled() && this->IsPointOnReslicedPlane(w->GetSeed(i)->GetHandleRepresentation()));
        }
    }
    return true;
}

bool MyVtkResliceImageViewerMeasurements::IsWidgetOnReslicedPlane(vtkHandleWidget *w)
{
    return this->IsPointOnReslicedPlane(w->GetHandleRepresentation());
}

bool MyVtkResliceImageViewerMeasurements::IsPointOnReslicedPlane(vtkHandleRepresentation *h)
{
    double pos[3];
    h->GetWorldPosition(pos);
    return this->IsPositionOnReslicedPlane(pos);
}

bool MyVtkResliceImageViewerMeasurements::IsPositionOnReslicedPlane(double p[])
{
    if (vtkResliceCursorRepresentation* rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceImageViewer->GetResliceCursorWidget()->GetRepresentation()))
    {
        const int planeOrientation = rep->GetCursorAlgorithm()->GetReslicePlaneNormal();
        vtkPlane* plane = this->ResliceImageViewer->GetResliceCursor()->GetPlane(planeOrientation);
        const double d = plane->DistanceToPlane(p);
        return (d < this->Tolerance);
    }
    return true;
}
void MyVtkResliceImageViewerMeasurements::Update()
{
    if(this->ResliceImageViewer->GetResliceMode() != MyVtkResliceImageViewer::RESLICE_OBLIQUE)
        return;
    const int nItems = this->WidgetCollection->GetNumberOfItems();
    for(auto i =0;i<nItems;i++)
    {
        vtkAbstractWidget *a = vtkAbstractWidget::SafeDownCast(this->WidgetCollection->GetItemAsObject(i));
        vtkSeedWidget *s = vtkSeedWidget::SafeDownCast(a);
        if(!s)
            a->SetEnabled(this->IsItemOnReslicedPlane(a));
    }
}
void MyVtkResliceImageViewerMeasurements::ProcessEventsHandler(vtkObject *object, unsigned long event, void *clientdata, void *calldata)
{
    MyVtkResliceImageViewerMeasurements *self = reinterpret_cast<MyVtkResliceImageViewerMeasurements*>(clientdata);
    if(!self->GetProcessEvents())
        return;
    self->Update();
}
