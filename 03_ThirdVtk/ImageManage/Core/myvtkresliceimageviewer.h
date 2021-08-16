#ifndef MYVTKRESLICEIMAGEVIEWER_H
#define MYVTKRESLICEIMAGEVIEWER_H

#include "vtkImageViewer2.h"
#include "vtkInteractionImageModule.h"


class vtkResliceCursorWidget;
class vtkResliceCursor;
class vtkScalarsToColors;
class vtkBoundedPlanePointPlacer;
class vtkResliceImageViewerMeasurements;
class vtkResliceImageViewerScrollCallback;
class vtkPlane;


class MyVtkResliceImageViewer : public vtkImageViewer2
{

public:

    static MyVtkResliceImageViewer *New();
    vtkTypeMacro(MyVtkResliceImageViewer,vtkImageViewer2);
    void PrintSelf(ostream& os,vtkIndent indent) override;

    void Render() override;

    void SetInputData(vtkImageData *in) override;
    void SetInputConnection(vtkAlgorithmOutput *input) override;

    void SetColorWindow(double s) override;
    void SetColorLevel(double s) override;

    vtkGetObjectMacro(ResliceCursorWidget,vtkResliceCursorWidget);
    enum
    {
        RESLICE_AXIS_ALIGNED = 0,
        RESLICE_OBLIQUE = 1
    };
    vtkGetMacro(ResliceMode,int);
    virtual void SetResliceMode(int resliceMode);
    virtual void SetResliceModeToAxisAligned();
    virtual void SetResliceModeToOblique();
    vtkResliceCursor* GetResliceCursor();
    void SetResliceCursor(vtkResliceCursor *rc);
    virtual void SetLookupTable(vtkScalarsToColors *l);
    vtkScalarsToColors* GetLookupTable();
    virtual void SetThickMode(int mode);
    virtual int GetThickMode();
    virtual void Reset();
    vtkGetObjectMacro(PointPlacer,vtkBoundedPlanePointPlacer);
    vtkGetObjectMacro(Measurements,vtkResliceImageViewerMeasurements);
    vtkGetObjectMacro(Interactor,vtkRenderWindowInteractor);
    vtkSetMacro(SliceScrollOnMouseWheel,vtkTypeBool);
    vtkGetMacro(SliceScrollOnMouseWheel, vtkTypeBool);
    vtkBooleanMacro(SliceScrollOnMouseWheel, vtkTypeBool);
    virtual void IncrementSlice(int inc);
    enum
    {
        SliceChangedEvent = 1001
    };






protected:

    MyVtkResliceImageViewer();

    void UpdateDisplayExtent() override;
    virtual void UpdataPointPlacer();



    vtkPlane* GetReslicePlane();
    double GetInterSliceSpacingInResliceMode();


    vtkResliceCursorWidget *ResliceCursorWidget;
    vtkBoundedPlanePointPlacer *PointPlacer;
    int ResliceMode;
    vtkResliceImageViewerMeasurements *Measurements;
    vtkTypeBool SliceScrollOnMouseWheel;
    vtkRenderWindowInteractor *Interactor;
    vtkResliceImageViewerScrollCallback *ScrollCallback;

};

#endif // MYVTKRESLICEIMAGEVIEWER_H
