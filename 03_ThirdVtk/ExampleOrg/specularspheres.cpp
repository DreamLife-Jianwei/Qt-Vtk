#include "specularspheres.h"
#include "ui_specularspheres.h"

SpecularSpheres::SpecularSpheres(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpecularSpheres)
{
    ui->setupUi(this);

    sphere = vtkSmartPointer<vtkSphereSource>::New();
    sphere->SetThetaResolution(100);
    sphere->SetPhiResolution(50);
    sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphere->GetOutputPort());
    sphere1 = vtkSmartPointer<vtkActor>::New();
    sphere2 = vtkSmartPointer<vtkActor>::New();
    sphere3 = vtkSmartPointer<vtkActor>::New();
    sphere4 = vtkSmartPointer<vtkActor>::New();
    sphere5 = vtkSmartPointer<vtkActor>::New();
    sphere6 = vtkSmartPointer<vtkActor>::New();
    sphere7 = vtkSmartPointer<vtkActor>::New();
    sphere8 = vtkSmartPointer<vtkActor>::New();

    sphere1->SetMapper(sphereMapper);
    sphere1->GetProperty()->SetColor(1,0,0);
    sphere1->GetProperty()->SetAmbient(0.3);
    sphere1->GetProperty()->SetDiffuse(0.0);
    sphere1->GetProperty()->SetSpecular(1.0);
    sphere1->GetProperty()->SetSpecularPower(5.0);

    sphere2->SetMapper(sphereMapper);
    sphere2->GetProperty()->SetColor(1,0,0);
    sphere2->GetProperty()->SetAmbient(0.3);
    sphere2->GetProperty()->SetDiffuse(0.0);
    sphere2->GetProperty()->SetSpecular(1.0);
    sphere2->GetProperty()->SetSpecularPower(10.0);
    sphere2->AddPosition(1.25,0,0);

    sphere3->SetMapper(sphereMapper);
    sphere3->GetProperty()->SetColor(1,0,0);
    sphere3->GetProperty()->SetAmbient(0.3);
    sphere3->GetProperty()->SetDiffuse(0.0);
    sphere3->GetProperty()->SetSpecular(1.0);
    sphere3->GetProperty()->SetSpecularPower(20.0);
    sphere3->AddPosition(2.5,0,0);

    sphere4->SetMapper(sphereMapper);
    sphere4->GetProperty()->SetColor(1,0,0);
    sphere4->GetProperty()->SetAmbient(0.3);
    sphere4->GetProperty()->SetDiffuse(0.0);
    sphere4->GetProperty()->SetSpecular(1.0);
    sphere4->GetProperty()->SetSpecularPower(40.0);
    sphere4->AddPosition(3.75,0,0);

    sphere5->SetMapper(sphereMapper);
    sphere5->GetProperty()->SetColor(1,0,0);
    sphere5->GetProperty()->SetAmbient(0.3);
    sphere5->GetProperty()->SetDiffuse(0.0);
    sphere5->GetProperty()->SetSpecular(0.5);
    sphere5->GetProperty()->SetSpecularPower(5.0);
    sphere5->AddPosition(0.0,1.25,0);

    sphere6->SetMapper(sphereMapper);
    sphere6->GetProperty()->SetColor(1,0,0);
    sphere6->GetProperty()->SetAmbient(0.3);
    sphere6->GetProperty()->SetDiffuse(0.0);
    sphere6->GetProperty()->SetSpecular(0.5);
    sphere6->GetProperty()->SetSpecularPower(10.0);
    sphere6->AddPosition(1.25,1.25,0);

    sphere7->SetMapper(sphereMapper);
    sphere7->GetProperty()->SetColor(1,0,0);
    sphere7->GetProperty()->SetAmbient(0.3);
    sphere7->GetProperty()->SetDiffuse(0.0);
    sphere7->GetProperty()->SetSpecular(0.5);
    sphere7->GetProperty()->SetSpecularPower(20.0);
    sphere7->AddPosition(2.5,1.25,0);

    sphere8->SetMapper(sphereMapper);
    sphere8->GetProperty()->SetColor(1,0,0);
    sphere8->GetProperty()->SetAmbient(0.3);
    sphere8->GetProperty()->SetDiffuse(0.0);
    sphere8->GetProperty()->SetSpecular(0.5);
    sphere8->GetProperty()->SetSpecularPower(40.0);
    sphere8->AddPosition(3.75,1.25,0);

    render = vtkSmartPointer<vtkRenderer>::New();

    render->AddActor(sphere1);
    render->AddActor(sphere2);
    render->AddActor(sphere3);
    render->AddActor(sphere4);
    render->AddActor(sphere5);
    render->AddActor(sphere6);
    render->AddActor(sphere7);
    render->AddActor(sphere8);
    render->SetBackground(0.1, 0.2, 0.4);


    light = vtkSmartPointer<vtkLight>::New();
    light->SetFocalPoint(1.875,0.6125,0);
    light->SetPosition(0.875,1.6125,1);
    render->AddLight(light);

    render->GetActiveCamera()->SetFocalPoint(0,0,0);
    render->GetActiveCamera()->SetPosition(0,0,1);
    render->GetActiveCamera()->SetViewUp(0,1,0);
    render->GetActiveCamera()->ParallelProjectionOn();
    render->ResetCamera();
    render->GetActiveCamera()->SetParallelScale(3.0);

    ui->openGLWidget->renderWindow()->AddRenderer(render);

}

SpecularSpheres::~SpecularSpheres()
{
    delete ui;
}
