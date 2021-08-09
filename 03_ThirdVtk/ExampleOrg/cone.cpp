#include "cone.h"
#include "ui_cone.h"

Cone::Cone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cone)
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
    coneRender = vtkRenderer::New();
    coneRender->AddActor(coneActor);
    coneRender->SetBackground(0.1,0.2,0.3);
    //获取渲染窗口
    ui->openGLWidget->renderWindow()->AddRenderer(coneRender);
    //旋转椎体
    rotationTimer = new QTimer();
    connect(rotationTimer,&QTimer::timeout,this,[=](){coneRender->GetActiveCamera()->Azimuth(1);ui->openGLWidget->renderWindow()->Render();});  //注意这句话，要加上呀，不然人不给你转，惰性渲染。
    rotationTimer->start(25);
}

Cone::~Cone()
{
    rotationTimer->stop();
    delete ui;
}
