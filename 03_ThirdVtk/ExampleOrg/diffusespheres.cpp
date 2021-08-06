#include "diffusespheres.h"
#include "ui_diffusespheres.h"

DiffuseSpheres::DiffuseSpheres(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiffuseSpheres)
{
    ui->setupUi(this);

    sphere = vtkSphereSource::New();
    sphere->SetThetaResolution(100);
    sphere->SetPhiResolution(50);


    mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection(sphere->GetOutputPort());


    sphere1 = vtkActor::New();
    sphere2 = vtkActor::New();
    sphere3 = vtkActor::New();
    sphere4 = vtkActor::New();
    sphere5 = vtkActor::New();
    sphere6 = vtkActor::New();
    sphere7 = vtkActor::New();
    sphere8 = vtkActor::New();

    sphere1->SetMapper(mapper);
    sphere2->SetMapper(mapper);
    sphere3->SetMapper(mapper);
    sphere4->SetMapper(mapper);
    sphere5->SetMapper(mapper);
    sphere6->SetMapper(mapper);
    sphere7->SetMapper(mapper);
    sphere8->SetMapper(mapper);


    sphere1->GetProperty()->SetColor(1,0,0);
    sphere1->GetProperty()->SetAmbient(0.3);
    sphere1->GetProperty()->SetDiffuse(0.0);
    sphere1->GetProperty()->SetSpecular(0.0);
    sphere1->GetProperty()->SetSpecularPower(5.0);

    sphere2->GetProperty()->SetColor(1,0,0);
    sphere2->GetProperty()->SetAmbient(0.3);
    sphere2->GetProperty()->SetDiffuse(0.125);
    sphere2->GetProperty()->SetSpecular(0.0);
    sphere2->GetProperty()->SetSpecularPower(10.0);
    sphere2->AddPosition(1.25,0,0);

    sphere3->GetProperty()->SetColor(1,0,0);
    sphere3->GetProperty()->SetAmbient(0.3);
    sphere3->GetProperty()->SetDiffuse(0.25);
    sphere3->GetProperty()->SetSpecular(0.0);
    sphere3->AddPosition(2.5,0,0);

    sphere4->GetProperty()->SetColor(1,0,0);
    sphere4->GetProperty()->SetAmbient(0.3);
    sphere4->GetProperty()->SetDiffuse(0.375);
    sphere4->GetProperty()->SetSpecular(0.0);
    sphere4->AddPosition(3.75,0,0);

    sphere5->GetProperty()->SetColor(1,0,0);
    sphere5->GetProperty()->SetAmbient(0.3);
    sphere5->GetProperty()->SetDiffuse(0.5);
    sphere5->GetProperty()->SetSpecular(0.0);
    sphere5->AddPosition(0.0,1.25,0);

    sphere6->GetProperty()->SetColor(1,0,0);
    sphere6->GetProperty()->SetAmbient(0.3);
    sphere6->GetProperty()->SetDiffuse(0.625);
    sphere6->GetProperty()->SetSpecular(0.0);
    sphere6->AddPosition(1.25,1.25,0);

    sphere7->GetProperty()->SetColor(1,0,0);
    sphere7->GetProperty()->SetAmbient(0.3);
    sphere7->GetProperty()->SetDiffuse(0.75);
    sphere7->GetProperty()->SetSpecular(0.0);
    sphere7->AddPosition(2.5,1.25,0);

    sphere8->GetProperty()->SetColor(1,0,0);
    sphere8->GetProperty()->SetAmbient(0.3);
    sphere8->GetProperty()->SetDiffuse(0.875);
    sphere8->GetProperty()->SetSpecular(0.0);
    sphere8->AddPosition(3.75,1.25,0);


    render = vtkRenderer::New();
    render->AddActor(sphere1);
    render->AddActor(sphere2);
    render->AddActor(sphere3);
    render->AddActor(sphere4);
    render->AddActor(sphere5);
    render->AddActor(sphere6);
    render->AddActor(sphere7);
    render->AddActor(sphere8);


    ui->openGLWidget->renderWindow()->AddRenderer(render);




}

DiffuseSpheres::~DiffuseSpheres()
{
    delete ui;
}
