#include "myvtkresliceimageviewer.h"

#include "vtkBoundedPlanePointPlacer.h"
#include "vtkCamera.h"
#include "vtkCommand.h"
#include "vtkImageActor.h"
#include "vtkImageData.h"
#include "vtkImageMapToWindowLevelColors.h"
#include "vtkImageReslice.h"
#include "vtkInteractorStyleImage.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"
#include "vtkPlane.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkResliceCursor.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorWidget.h"
//#include "vtkResliceImageViewerMeasurements.h"
#include "myvtkresliceimageviewermeasurements.h"
#include "vtkScalarsToColors.h"
#include "vtkSmartPointer.h"

vtkStandardNewMacro(MyVtkResliceImageViewer);

class vtkResliceImageViewerScrollCallback : public vtkCommand
{
public:
    static vtkResliceImageViewerScrollCallback* New()
    {
        return new vtkResliceImageViewerScrollCallback;
    }
    void Execute(vtkObject*,unsigned long ev,void*) override
    {
        if(!this->Viewer->GetSliceScrollOnMouseWheel())
            return;
        if(this->Viewer->GetInteractor()->GetShiftKey() || this->Viewer->GetInteractor()->GetControlKey() || this->Viewer->GetInteractor()->GetAltKey())
            return;
        int sign = (ev == vtkCommand::MouseWheelForwardEvent) ? 1 : -1;
        this->Viewer->IncrementSlice(sign);
        this->SetAbortFlag(1);
    }
    vtkResliceImageViewerScrollCallback() : Viewer(nullptr){}
    MyVtkResliceImageViewer *Viewer;
};

void MyVtkResliceImageViewer::PrintSelf(std::ostream &os, vtkIndent indent)
{
    this->Superclass::PrintSelf(os,indent);         //调用父类PrintSelf

    os << indent << "ResliceCursorWidget:\n";

    this->ResliceCursorWidget->PrintSelf(os,indent.GetNextIndent());

    os << indent << "ResliceMode: " << this->ResliceMode <<endl;

    os << indent << "SliceScorollOnMouseWheel:" << this->SliceScrollOnMouseWheel << endl;

    os << indent << "Point Placer: ";

    this->PointPlacer->PrintSelf(os,indent.GetNextIndent());

    os << indent << "Measurements: ";

    this->Measurements->PrintSelf(os,indent.GetNextIndent());

    os << indent << "Interactor: " << this->Interactor << "\n";

    if(this->Interactor)
        this->Interactor->PrintSelf(os,indent.GetNextIndent());
}

void MyVtkResliceImageViewer::Render()
{
    if(!this->WindowLevel->GetInput())          //判断是有数据
    {
        return;
    }

    this->UpdataPointPlacer();

    this->Superclass::Render();
}

void MyVtkResliceImageViewer::SetInputData(vtkImageData *in)
{
    if(!in)
        return;
    this->WindowLevel->SetInputData(in);
    this->GetResliceCursor()->SetImage(in);
    this->GetResliceCursor()->SetCenter(in->GetCenter());
    this->UpdateDisplayExtent();
    double range[2];
    in->GetScalarRange(range);
    if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
        if(vtkImageReslice *reslice = vtkImageReslice::SafeDownCast(rep->GetReslice()))
        {
            reslice->SetBackgroundColor(range[0],range[0],range[0],range[0]);
            this->SetColorWindow(range[1]-range[0]);
            this->SetColorLevel(range[0] + range[1]/2.0);
        }
}

void MyVtkResliceImageViewer::SetInputConnection(vtkAlgorithmOutput *input)
{
    vtkErrorMacro(<< "Use SetInputData instead.");
    this->WindowLevel->SetInputConnection(input);
    this->UpdateDisplayExtent();
}

void MyVtkResliceImageViewer::SetColorWindow(double s)
{
    double rmin = this->GetColorLevel() - 0.5 * fabs(s);
    double rmax = rmin + fabs(s);
    this->GetLookupTable()->SetRange(rmin,rmax);
    this->WindowLevel->SetWindow(s);
    if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
        rep->SetWindowLevel(s,rep->GetLevel(),1);
}

void MyVtkResliceImageViewer::SetColorLevel(double s)
{
    double rmin = s - 0.5 * fabs(this->GetColorWindow());
    double rmax = rmin + fabs(this->GetColorWindow());
    this->GetLookupTable()->SetRange(rmin,rmax);
    this->WindowLevel->SetLevel(s);
    if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
        rep->SetWindowLevel(rep->GetWindow(),s,1);
}

void MyVtkResliceImageViewer::SetResliceMode(int resliceMode)
{
    if(resliceMode == this->ResliceMode)
        return;
    this->ResliceMode = resliceMode;
    this->Modified();
    this->InstallPipeline();
}

void MyVtkResliceImageViewer::SetResliceModeToAxisAligned()
{
    this->SetResliceMode(MyVtkResliceImageViewer::RESLICE_AXIS_ALIGNED);
}

void MyVtkResliceImageViewer::SetResliceModeToOblique()
{
    this->SetResliceMode(MyVtkResliceImageViewer::RESLICE_OBLIQUE);
}

vtkScalarsToColors *MyVtkResliceImageViewer::GetLookupTable()
{
    if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
        return rep->GetLookupTable();
    return nullptr;
}

void MyVtkResliceImageViewer::SetThickMode(int mode)
{
    vtkSmartPointer<vtkResliceCursor> rc = this->GetResliceCursor();
    if(mode == this->GetThickMode())
        return;
    vtkSmartPointer<vtkResliceCursorLineRepresentation> resliceCursorRepOld = vtkResliceCursorLineRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation());
    vtkSmartPointer<vtkResliceCursorLineRepresentation> resliceCursorRepNew;
    this->GetResliceCursor()->SetThickMode(mode);
    if(mode)
        resliceCursorRepNew = vtkSmartPointer<vtkResliceCursorThickLineRepresentation>::New();
    else
        resliceCursorRepNew = vtkSmartPointer<vtkResliceCursorLineRepresentation>::New();
    int e = this->ResliceCursorWidget->GetEnabled();
    this->ResliceCursorWidget->SetEnabled(0);
    resliceCursorRepNew->GetResliceCursorActor()->GetCursorAlgorithm()->SetResliceCursor(rc);
    resliceCursorRepNew->GetResliceCursorActor()->GetCursorAlgorithm()->SetReslicePlaneNormal(this->SliceOrientation);
    this->ResliceCursorWidget->SetRepresentation(resliceCursorRepNew);
    resliceCursorRepNew->SetLookupTable(resliceCursorRepOld->GetLookupTable());
    resliceCursorRepNew->SetWindowLevel(resliceCursorRepOld->GetWindow(),resliceCursorRepOld->GetLevel(),1);
    this->ResliceCursorWidget->SetEnabled(e);
}

int MyVtkResliceImageViewer::GetThickMode()
{
    return (vtkResliceCursorThickLineRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation())) ? 1 : 0;
}

void MyVtkResliceImageViewer::Reset()
{
    this->ResliceCursorWidget->ResetResliceCursor();
}

void MyVtkResliceImageViewer::IncrementSlice(int inc)
{
    if(this->GetResliceMode() == MyVtkResliceImageViewer::RESLICE_AXIS_ALIGNED)
    {
        int oldSlice = this->GetSlice();
        this->SetSlice(this->GetSlice() + inc);
        if(this->GetSlice() != oldSlice)
        {
            this->InvokeEvent(MyVtkResliceImageViewer::SliceChangedEvent,nullptr);
            this->InvokeEvent(vtkCommand::InteractionEvent,nullptr);
        }
    }
    else
    {
        if(vtkPlane *p = this->GetReslicePlane())
        {
            double n[3],c[3],bounds[6];
            p->GetNormal(n);
            const double spacing = this->GetInterSliceSpacingInResliceMode() * inc;
            this->GetResliceCursor()->GetCenter(c);
            vtkMath::MultiplyScalar(n,spacing);
            c[0] += n[0];
            c[1] += n[1];
            c[2] += n[2];
            if(vtkImageData *image = this->GetResliceCursor()->GetImage())
            {
                image->GetBounds(bounds);
                if(c[0] >= bounds[0] && c[0] <= bounds[1] && c[1] >= bounds[2] && c[1] <= bounds[3] && c[2] >= bounds[4] && c[2] <= bounds[5])
                {
                    this->GetResliceCursor()->SetCenter(c);
                    this->InvokeEvent(MyVtkResliceImageViewer::SliceChangedEvent,nullptr);
                    this->InvokeEvent(vtkCommand::InteractionEvent,nullptr);
                }
            }
        }
    }
}

MyVtkResliceImageViewer::MyVtkResliceImageViewer()
{
    this->ResliceMode = MyVtkResliceImageViewer::RESLICE_AXIS_ALIGNED;
    this->ResliceCursorWidget = vtkResliceCursorWidget::New();
    vtkSmartPointer<vtkResliceCursor> resliceCursor = vtkSmartPointer<vtkResliceCursor>::New();
    resliceCursor->SetThickMode(0);
    resliceCursor->SetThickness(10,10,10);
    vtkSmartPointer<vtkResliceCursorLineRepresentation> resliceCursorRep = vtkSmartPointer<vtkResliceCursorLineRepresentation>::New();
    resliceCursorRep->GetResliceCursorActor()->GetCursorAlgorithm()->SetResliceCursor(resliceCursor);
    resliceCursorRep->GetResliceCursorActor()->GetCursorAlgorithm()->SetReslicePlaneNormal(this->SliceOrientation);
    this->ResliceCursorWidget->SetRepresentation(resliceCursorRep);
    this->PointPlacer = vtkBoundedPlanePointPlacer::New();
    this->Measurements = MyVtkResliceImageViewerMeasurements::New();
//    this->Measurements->SetResliceImageViewer(this);                    //重写

    this->ScrollCallback = vtkResliceImageViewerScrollCallback::New();    //等待实现
    this->ScrollCallback->Viewer = this;
    this->SliceScrollOnMouseWheel = 1;
    this->InstallPipeline();
}

MyVtkResliceImageViewer::~MyVtkResliceImageViewer()
{
    this->Measurements->Delete();
    if(this->ResliceCursorWidget)
    {
        this->ResliceCursorWidget->Delete();
        this->ResliceCursorWidget = nullptr;
    }

    this->PointPlacer->Delete();
    this->ScrollCallback->Delete();
}

void MyVtkResliceImageViewer::InstallPipeline()
{
    this->Superclass::InstallPipeline();
    if(this->Interactor)
    {
        this->ResliceCursorWidget->SetInteractor(this->Interactor);
        this->Interactor->RemoveObserver(this->ScrollCallback);
        this->Interactor->AddObserver(vtkCommand::MouseWheelForwardEvent,this->ScrollCallback,0.55);
        this->Interactor->AddObserver(vtkCommand::MouseWheelBackwardEvent,this->ScrollCallback,0.55);
    }

    if(this->Renderer)
    {
        this->ResliceCursorWidget->SetDefaultRenderer(this->Renderer);
        vtkCamera *cam = this->Renderer->GetActiveCamera();
        cam->ParallelProjectionOn();
    }

    if(this->ResliceMode == RESLICE_OBLIQUE)
    {
        this->ResliceCursorWidget->SetEnabled(1);
        this->ImageActor->SetVisibility(0);
        this->UpdateOrientation();

        double bounds[6] = {0,1,0,1,0,1};

        vtkCamera *cam = this->Renderer->GetActiveCamera();
        double onespacing[3] = {1,1,1};
        double *spacing = onespacing;
        if(this->GetResliceCursor()->GetImage())
        {
            this->GetResliceCursor()->GetImage()->GetBounds(bounds);
            spacing = this->GetResliceCursor()->GetImage()->GetSpacing();
        }
        double avg_spacing = (spacing[0] + spacing[1] + spacing[2]) / 3.0;
        cam->SetClippingRange(bounds[this->SliceOrientation * 2] - 100 * avg_spacing,bounds[this->SliceOrientation *2 +1] + 100 * avg_spacing);
    }
    else
    {
        this->ResliceCursorWidget->SetEnabled(0);
        this->ImageActor->SetVisibility(1);
        this->UpdateOrientation();
    }
    if(this->WindowLevel)
        this->WindowLevel->SetLookupTable(this->GetLookupTable());
}

void MyVtkResliceImageViewer::UnInstallPipeline()
{
    this->ResliceCursorWidget->SetEnabled(0);
    if(this->Interactor)
        this->Interactor->RemoveObserver(this->ScrollCallback);
    this->Superclass::UnInstallPipeline();
}

void MyVtkResliceImageViewer::UpdateOrientation()
{
    vtkCamera *cam = this->Renderer ? this->Renderer->GetActiveCamera() : nullptr;
    if(cam)
    {
        switch (this->SliceOrientation) {
        case vtkImageViewer2::SLICE_ORIENTATION_XY:
            cam->SetFocalPoint(0,0,0);
            cam->SetPosition(0,0,1);
            cam->SetViewUp(0,1,0);
            break;
        case vtkImageViewer2::SLICE_ORIENTATION_XZ:
            cam->SetFocalPoint(0,0,0);
            cam->SetPosition(0,-1,0);
            cam->SetViewUp(0,0,1);
            break;
        case vtkImageViewer2::SLICE_ORIENTATION_YZ:
            cam->SetFocalPoint(0,0,0);
            cam->SetPosition(1,0,0);
            cam->SetViewUp(0,0,1);
            break;
        }
    }
}

vtkResliceCursor *MyVtkResliceImageViewer::GetResliceCursor()
{
    if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
        return rep->GetResliceCursor();
    return nullptr;
}

void MyVtkResliceImageViewer::SetResliceCursor(vtkResliceCursor *rc)
{
    vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->GetResliceCursorWidget()->GetRepresentation());
    rep->GetCursorAlgorithm()->SetResliceCursor(rc);
    // this->Measurements->SetResliceImageViewer(this);            //这里需要重新vtkResliceImageViewerMeasurements
}

void MyVtkResliceImageViewer::SetLookupTable(vtkScalarsToColors *l)
{
    if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
        rep->SetLookupTable(l);
    if(this->WindowLevel)
    {
        this->WindowLevel->SetLookupTable(l);
        this->WindowLevel->SetOutputFormatToRGBA();
        this->WindowLevel->PassAlphaToOutputOn();
    }
}

void MyVtkResliceImageViewer::UpdateDisplayExtent()
{
    if(this->ResliceMode == RESLICE_AXIS_ALIGNED)
        this->Superclass::UpdateDisplayExtent();
}

void MyVtkResliceImageViewer::UpdataPointPlacer()
{
    if(this->ResliceMode == RESLICE_OBLIQUE)
    {
        this->PointPlacer->SetProjectionNormalToOblique();
        if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
        {
            const int planeOrientation = rep->GetCursorAlgorithm()->GetReslicePlaneNormal();
            vtkPlane *plane = this->GetResliceCursor()->GetPlane(planeOrientation);
            this->PointPlacer->SetObliquePlane(plane);
        }
    }
    else
    {
        if(!this->WindowLevel->GetInput())
            return;


        vtkImageData *input = this->ImageActor->GetInput();
        if(!input)
            return;

        double spacing[3];
        input->GetSpacing(spacing);

        double origin[3];
        input->GetOrigin(origin);

        double bounds[6];
        this->ImageActor->GetBounds(bounds);

        int displayExtent[6];
        this->ImageActor->GetDisplayExtent(displayExtent);

        int axis = vtkBoundedPlanePointPlacer::XAxis;
        double  position = 0.0;

        if(displayExtent[0] == displayExtent[1])
        {
            axis = vtkBoundedPlanePointPlacer::XAxis;
            position = origin[0] + displayExtent[0] * spacing[0];
        }
        else if (displayExtent[2] == displayExtent[3]) {
            axis = vtkBoundedPlanePointPlacer::YAxis;
            position = origin[1] + displayExtent[2] * spacing[1];
        }
        else if (displayExtent[4] == displayExtent[5]) {
            axis = vtkBoundedPlanePointPlacer::ZAxis;
            position = origin[2] + displayExtent[4] * spacing[2];
        }

        this->PointPlacer->SetProjectionNormal(axis);
        this->PointPlacer->SetProjectionPosition(position);
    }
}

vtkPlane *MyVtkResliceImageViewer::GetReslicePlane()
{
    if(vtkResliceCursorRepresentation *rep = vtkResliceCursorRepresentation::SafeDownCast(this->ResliceCursorWidget->GetRepresentation()))
    {
        const int planeOrientation = rep->GetCursorAlgorithm()->GetReslicePlaneNormal();
        vtkPlane *plane = this->GetResliceCursor()->GetPlane(planeOrientation);
        return plane;
    }

    return nullptr;
}

double MyVtkResliceImageViewer::GetInterSliceSpacingInResliceMode()
{
    double n[3],imageSpacing[3],resliceSpacing = 0;
    if(vtkPlane *plane = this->GetReslicePlane())
    {
        plane->GetNormal(n);
        this->GetResliceCursor()->GetImage()->GetSpacing(imageSpacing);
        resliceSpacing = fabs(vtkMath::Dot(n,imageSpacing));
    }
    return resliceSpacing;
}

