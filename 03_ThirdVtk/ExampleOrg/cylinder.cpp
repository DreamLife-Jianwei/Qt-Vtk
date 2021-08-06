#include "cylinder.h"
#include "ui_cylinder.h"

Cylinder::Cylinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cylinder)
{
    ui->setupUi(this);

    cylinder = vtkCylinderSource::New();
    cylinder->SetResolution(80);
    cylinder->SetHeight(10);


    mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection(cylinder->GetOutputPort());


    actor = vtkActor::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(1.0,0.23,0.45);
    actor->RotateX(30.0);
    actor->RotateY(-45.0);


    render = vtkRenderer::New();
    render->AddActor(actor);

    ui->openGLWidget->renderWindow()->AddRenderer(render);

}

Cylinder::~Cylinder()
{
    delete ui;
}
