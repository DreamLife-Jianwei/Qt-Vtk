#include "cone3.h"
#include "ui_cone3.h"

Cone3::Cone3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cone3)
{
    ui->setupUi(this);


    cone = vtkConeSource::New();    //新建对象

    cone->SetHeight(3.0);           //设置高度
    cone->SetRadius(1.0);           //设置半径
    cone->SetResolution(20);        //翻译为设置分辨率，其实这个是设置椎体的面数的

    coneMapper = vtkPolyDataMapper::New();          //新建映射器
    coneMapper->SetInputConnection(cone->GetOutputPort());  //设置Cone输出coneMapper数据输入

    //新建Actor，并设置映射器
    coneActor = vtkActor::New();
    coneActor->SetMapper(coneMapper);
    //新建渲染器并设置Actor和背景颜色
    coneRender1 = vtkRenderer::New();
    coneRender1->AddActor(coneActor);
    coneRender1->SetBackground(0.1,0.2,0.3);
    coneRender1->SetViewport(0.0,0.0,0.5,1.0);

    coneRender2 = vtkRenderer::New();
    coneRender2->AddActor(coneActor);
    coneRender2->SetBackground(0.7,0.1,0.1);
    coneRender2->SetViewport(0.5,0.0,1.0,1.0);
    //获取渲染窗口

    ui->openGLWidget->renderWindow()->AddRenderer(coneRender1);
    ui->openGLWidget->renderWindow()->AddRenderer(coneRender2);
    //旋转椎体
    rotationTimer = new QTimer();
    connect(rotationTimer,&QTimer::timeout,this,[=](){
        coneRender1->GetActiveCamera()->Azimuth(1);
        coneRender2->GetActiveCamera()->Azimuth(2);
        ui->openGLWidget->renderWindow()->Render();//注意这句话，要加上呀，不然人不给你转，惰性渲染。
    });

    rotationTimer->start(25);

}

Cone3::~Cone3()
{
    rotationTimer->stop();
    delete ui;
}
