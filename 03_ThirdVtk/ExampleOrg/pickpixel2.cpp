#include "pickpixel2.h"
#include "ui_pickpixel2.h"
#include <QDebug>

template <typename T>
void vtkValueMessageTemplate(vtkImageData* image, int* position,
                             std::string& message)
{
    T* tuple = ((T*)image->GetScalarPointer(position));
    int components = image->GetNumberOfScalarComponents();
    for (int c = 0; c < components; ++c)
    {
        message += vtkVariant(tuple[c]).ToString();
        if (c != (components - 1))
        {
            message += ", ";
        }
    }
    message += " )";
}


class vtkImageInteractionCallback : public vtkCommand
{
public:
    static vtkImageInteractionCallback* New()
    {



        return new vtkImageInteractionCallback;
    }

    vtkImageInteractionCallback()
    {
        this->Viewer = NULL;
        this->Picker = NULL;
        this->Annotation = NULL;
    }

    ~vtkImageInteractionCallback()
    {
        this->Viewer = NULL;
        this->Picker = NULL;
        this->Annotation = NULL;
    }

    void SetPicker(vtkPropPicker* picker)
    {
        this->Picker = picker;
    }

    void SetAnnotation(vtkCornerAnnotation* annotation)
    {
        this->Annotation = annotation;
    }

    void SetViewer(vtkImageViewer2* viewer)
    {
        this->Viewer = viewer;
    }

    virtual void Execute(vtkObject*, unsigned long vtkNotUsed(event), void*)
    {

        qDebug() << "asd";

        vtkRenderWindowInteractor* interactor = this->Viewer->GetRenderWindow()->GetInteractor();
        vtkRenderer* renderer = this->Viewer->GetRenderer();
        vtkImageActor* actor = this->Viewer->GetImageActor();
        vtkImageData* image = this->Viewer->GetInput();
        vtkInteractorStyle* style = dynamic_cast<vtkInteractorStyle*>(interactor->GetInteractorStyle());

        // Pick at the mouse location provided by the interactor
       qDebug() << this->Picker->Pick(interactor->GetEventPosition()[0],interactor->GetEventPosition()[1], 0.0, renderer);

        // There could be other props assigned to this picker, so
        // make sure we picked the image actor
        vtkAssemblyPath* path = this->Picker->GetPath();
        bool validPick = false;

        if (path)
        {
            vtkCollectionSimpleIterator sit;
            path->InitTraversal(sit);
            for (int i = 0; i < path->GetNumberOfItems() && !validPick; ++i)
            {
                auto node = path->GetNextNode(sit);
                if (actor == dynamic_cast<vtkImageActor*>(node->GetViewProp()))
                {
                    validPick = true;
                }
            }
        }

        if (!validPick)
        {
            this->Annotation->SetText(0, "Off Image");
            interactor->Render();
            // Pass the event further on
            style->OnMouseMove();
            return;
        }

        // Get the world coordinates of the pick
        double pos[3];
        this->Picker->GetPickPosition(pos);

        int image_coordinate[3];

        int axis = this->Viewer->GetSliceOrientation();
        switch (axis)
        {
        case vtkImageViewer2::SLICE_ORIENTATION_XZ:
            image_coordinate[0] = vtkMath::Round(pos[0]);
            image_coordinate[1] = this->Viewer->GetSlice();
            image_coordinate[2] = vtkMath::Round(pos[2]);
            break;
        case vtkImageViewer2::SLICE_ORIENTATION_YZ:
            image_coordinate[0] = this->Viewer->GetSlice();
            image_coordinate[1] = vtkMath::Round(pos[0]);
            image_coordinate[2] = vtkMath::Round(pos[1]);
            break;
        default: // vtkImageViewer2::SLICE_ORIENTATION_XY
            image_coordinate[0] = vtkMath::Round(pos[0]);
            image_coordinate[1] = vtkMath::Round(pos[1]);
            image_coordinate[2] = this->Viewer->GetSlice();
            break;
        }

        std::string message = "Location: ( ";
        message += vtkVariant(image_coordinate[0]).ToString();
        message += ", ";
        message += vtkVariant(image_coordinate[1]).ToString();
        message += ", ";
        message += vtkVariant(image_coordinate[2]).ToString();
        message += " )\nValue: ( ";

        switch (image->GetScalarType())
        {
        vtkTemplateMacro(
                    (vtkValueMessageTemplate<VTK_TT>(image, image_coordinate, message)));

        default:
            return;
        }

        this->Annotation->SetText(0, message.c_str());
        interactor->Render();
        style->OnMouseMove();
    }

private:
    vtkImageViewer2* Viewer;         // Pointer to the viewer
    vtkPropPicker* Picker;           // Pointer to the picker
    vtkCornerAnnotation* Annotation; // Pointer to the annotation
};




PickPixel2::PickPixel2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PickPixel2)
{
    ui->setupUi(this);


    noiseSource->SetWholeExtent(0, 512, 0, 512, 0, 512);
    noiseSource->SetMinimum(0.0);
    noiseSource->SetMaximum(255.0);

    imageCast->SetInputConnection(noiseSource->GetOutputPort());
    imageCast->SetOutputScalarTypeToUnsignedChar();
    imageCast->Update();
    imageViewer->SetInputConnection(imageCast->GetOutputPort());
    propPicker->PickFromListOn();

    imageActor = vtkSmartPointer<vtkImageActor>::New();
    imageActor = imageViewer->GetImageActor();
    propPicker->AddPickList(imageActor);
    imageActor->InterpolateOff();

    vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
      imageViewer->SetupInteractor(renderWindowInteractor);


    cornerAnnotation->SetLinearFontScaleFactor(2);
    cornerAnnotation->SetNonlinearFontScaleFactor(1);
    cornerAnnotation->SetMaximumFontSize(20);
    cornerAnnotation->SetText(0, "Off Image");
    cornerAnnotation->SetText(3, "<window>\n<level>");
    cornerAnnotation->GetTextProperty()->SetColor(
                colors->GetColor3d("LightGoldenrodYellow").GetData());
    imageViewer->GetRenderer()->AddViewProp(cornerAnnotation);

    renderer = imageViewer->GetRenderer();
    renderer->ResetCamera();
    renderer->GradientBackgroundOn();
    renderer->SetBackground(colors->GetColor3d("DarkSlateGray").GetData());
    renderer->SetBackground2(colors->GetColor3d("LightSlateGray").GetData());

    callback->SetViewer(imageViewer);
    callback->SetAnnotation(cornerAnnotation);
    callback->SetPicker(propPicker);


    imageStyle = imageViewer->GetInteractorStyle();
    if(imageStyle)
        imageStyle->AddObserver(vtkCommand::MouseMoveEvent, callback);
    renderWindowInteractor->Initialize();
    renderWindowInteractor->Start();
    imageViewer->SetRenderWindow(ui->openGLWidget->renderWindow());





}

PickPixel2::~PickPixel2()
{
    delete ui;
}
