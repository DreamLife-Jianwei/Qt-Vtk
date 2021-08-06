#include "cone2.h"
#include "ui_cone2.h"

Cone2::Cone2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cone2)
{
    ui->setupUi(this);
    cone = vtkConeSource::New();    //新建对象

    cone->SetHeight(3.0);           //设置高度
    cone->SetRadius(1.0);           //设置半径
    cone->SetResolution(10000000);        //翻译为设置分辨率，不过实际应该不是

    coneMapper = vtkPolyDataMapper::New();          //新建映射器
    coneMapper->SetInputConnection(cone->GetOutputPort());  //设置Cone输出coneMapper数据输入

    //新建Actor，并设置映射器
    coneActor = vtkActor::New();
    coneActor->SetMapper(coneMapper);
    //新建渲染器并设置Actor和背景颜色
    coneRender = vtkRenderer::New();
    coneRender->AddActor(coneActor);
    coneRender->SetBackground(0.1,0.2,0.3);

    myCallBack = vtkMyCallback::New();
    myCallBack->textBrowser = ui->textBrowser;
    coneRender->AddObserver(vtkCommand::StartEvent,myCallBack);

    //获取渲染窗口
    ui->openGLWidget->renderWindow()->AddRenderer(coneRender);


    //    while (1) {
    //        ui->widget->GetRenderWindow()->Render();
    //        coneRender->GetActiveCamera()->Azimuth(1);
    //    }
    //旋转椎体
    rotationTimer = new QTimer();
    connect(rotationTimer,&QTimer::timeout,this,[=](){
        coneRender->GetActiveCamera()->Azimuth(1);
        ui->openGLWidget->renderWindow()->Render();            //注意这句话，要加上呀，不然人不给你转，惰性渲染。
    });

    rotationTimer->start(25);

}

Cone2::~Cone2()
{
    rotationTimer->stop();
    delete ui;
}

void vtkMyCallback::Execute(vtkObject *caller, unsigned long, void *)
{
    vtkRenderer *renderer = reinterpret_cast<vtkRenderer*>(caller);
    textBrowser->append("Camera Position:");
    textBrowser->append(QString::number((renderer->GetActiveCamera()->GetPosition()[0]),'g',6));
    textBrowser->append(QString::number((renderer->GetActiveCamera()->GetPosition()[1]),'g',6));
    textBrowser->append(QString::number((renderer->GetActiveCamera()->GetPosition()[2]),'g',6));
}

