#include "cone6.h"
#include "ui_cone6.h"

Cone6::Cone6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cone6)
{
    ui->setupUi(this);


    cone = vtkConeSource::New();
    cone->SetRadius(1);
    cone->SetResolution(20);
    cone->SetHeight(3);



    mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection(cone->GetOutputPort());



    actor = vtkActor::New();
    actor->SetMapper(mapper);


    render = vtkRenderer::New();
    render->AddActor(actor);
    render->SetBackground(0,0,1);


    ui->openGLWidget->renderWindow()->AddRenderer(render);


    iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(ui->openGLWidget->renderWindow());



    style = vtkInteractorStyleTrackballCamera::New();
    iren->SetInteractorStyle(style);


    boxWidget = vtkBoxWidget::New();
    boxWidget->SetInteractor(iren);
    boxWidget->SetPlaceFactor(1.25);

    boxWidget->SetProp3D(actor);
    boxWidget->PlaceWidget();


    callback = vtkMyCallBack::New();
    boxWidget->AddObserver(vtkCommand::InteractionEvent,callback);
    boxWidget->On();
}

Cone6::~Cone6()
{
    delete ui;
}

void Cone6::startInteractor()
{
    iren->Start();
}

void vtkMyCallBack::Execute(vtkObject *caller, unsigned long eventId, void *callData)
{
    Q_UNUSED(caller);
    Q_UNUSED(eventId);
    Q_UNUSED(callData);
    vtkTransform *t = vtkTransform::New();
    vtkBoxWidget *widget = reinterpret_cast<vtkBoxWidget*>(caller);
    widget->GetTransform(t);
    widget->GetProp3D()->SetUserTransform(t);
    t->Delete();
}
