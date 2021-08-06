#include "cone4.h"
#include "ui_cone4.h"

Cone4::Cone4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cone4)
{
    ui->setupUi(this);
    cone = vtkConeSource::New();
    cone->SetRadius(1);
    cone->SetResolution(300);
    cone->SetHeight(4.0);
    mapper = vtkPolyDataMapper::New();
    mapper->SetInputConnection(cone->GetOutputPort());
    actor1 = vtkActor::New();
    actor1->SetMapper(mapper);
    actor1->GetProperty()->SetColor(1.0,0.0,0.0);
    actor1->GetProperty()->SetDiffuse(0.7);     //漫反射
    actor1->GetProperty()->SetSpecular(0.4);    //高光，镜面光
    actor1->GetProperty()->SetSpecularPower(20);//高光强度
    actor1->GetProperty()->SetRepresentationToWireframe();          //网格渲染
    property = vtkProperty::New();
    property->SetColor(0.0,0.0,1.0);
    property->SetDiffuse(0.5);
    property->SetSpecular(0.6);
    property->SetSpecularPower(30);
    actor2 = vtkActor::New();
    actor2->SetMapper(mapper);
    actor2->GetProperty()->SetColor(0.0,1.0,0.0);
    actor2->SetProperty(property);
    actor2->SetPosition(0,2,0);
    render = vtkRenderer::New();
    render->AddActor(actor1);
    render->AddActor(actor2);
    render->SetBackground(0,0,0);
    ui->openGLWidget->renderWindow()->AddRenderer(render);
    rotateTimer = new QTimer;
    connect(rotateTimer,&QTimer::timeout,this,[=](){
        render->GetActiveCamera()->Azimuth(1);
        ui->openGLWidget->renderWindow()->Render();
    });
    rotateTimer->start(10);

}

Cone4::~Cone4()
{
    rotateTimer->stop();
    delete ui;
}




