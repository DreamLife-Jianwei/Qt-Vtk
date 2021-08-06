#include "cone5.h"
#include "ui_cone5.h"

Cone5::Cone5(QWidget *parent) :QWidget(parent),ui(new Ui::Cone5)
{
    ui->setupUi(this);

    cone = vtkConeSource::New();
    cone->SetRadius(1);
    cone->SetResolution(100);
    cone->SetHeight(5);


    mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection(cone->GetOutputPort());


    actor = vtkActor::New();
    actor->SetMapper(mapper);


    render = vtkRenderer::New();
    render->AddActor(actor);
    render->SetBackground(0,1,0);


    ui->openGLWidget->renderWindow()->AddRenderer(render);


    iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(ui->openGLWidget->renderWindow());


    style = vtkInteractorStyleTrackballCamera::New();
    iren->SetInteractorStyle(style);

//    iren->Initialize();
//    iren->Start();                //在Qt中无法跑起来，这里需要看下Start的源码
    /*
    void vtkRenderWindowInteractor::Start()
    {
      // Let the compositing handle the event loop if it wants to.
      if (this->HasObserver(vtkCommand::StartEvent) && !this->HandleEventLoop)
      {
        this->InvokeEvent(vtkCommand::StartEvent,nullptr);
        return;
      }

      // As a convenience, initialize if we aren't initialized yet.
      if (!this->Initialized)
      {
        this->Initialize();

        if (!this->Initialized)
        {
          return;
        }
      }

      // Pass execution to the subclass which will run the event loop,
      // this will not return until TerminateApp is called.
      this->StartEventLoop();
    }
*/
}

Cone5::~Cone5()
{
    delete ui;
}

void Cone5::startiren()
{
    iren->Start();
}

void Cone5::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)


}
