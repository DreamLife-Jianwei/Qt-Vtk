#include "ambientspheres.h"
#include "ui_ambientspheres.h"
#include <QDebug>
/**
 * @brief AmbientSpheres::AmbientSpheres
 * @param parent
 * 照搬官方实例，有道翻译官方文件中内容如下
 * This examples demonstrates the effect of specular lighting.
 * 这个例子演示了镜面照明的效果。
 * 专业名词后面慢慢学习，代码先撸起来
 */
AmbientSpheres::AmbientSpheres(QWidget *parent) :QWidget(parent),ui(new Ui::AmbientSpheres)
{
    ui->setupUi(this);
    //创建一个球体
    sphere = vtkSmartPointer<vtkSphereSource>::New();
    sphere->SetThetaResolution(100);
    sphere->SetPhiResolution(50);
    //创建一个映射器
    sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphere->GetOutputPort());          //把球体的输出接口链接到映射器的输入接口
    //创建8个小球
    sphere1 = vtkSmartPointer<vtkActor>::New();
    sphere2 = vtkSmartPointer<vtkActor>::New();
    sphere3 = vtkSmartPointer<vtkActor>::New();
    sphere4 = vtkSmartPointer<vtkActor>::New();
    sphere5 = vtkSmartPointer<vtkActor>::New();
    sphere6 = vtkSmartPointer<vtkActor>::New();
    sphere7 = vtkSmartPointer<vtkActor>::New();
    sphere8 = vtkSmartPointer<vtkActor>::New();

    sphere1->SetMapper(sphereMapper);
    sphere1->GetProperty()->SetColor(1,0,0);            //颜色
    sphere1->GetProperty()->SetAmbient(0.125);          //环境光系数
    sphere1->GetProperty()->SetDiffuse(0.0);            //漫反射光系数
    sphere1->GetProperty()->SetSpecular(0.0);           //镜面反射系数
                                                        //镜面系数SetSpecularPower()


    sphere2->SetMapper(sphereMapper);
    sphere2->GetProperty()->SetColor(1,0,1);
    sphere2->GetProperty()->SetAmbient(0.25);
    sphere2->GetProperty()->SetDiffuse(0.0);
    sphere2->GetProperty()->SetSpecular(0.0);
    sphere2->AddPosition(1.25,0,0);


    sphere3->SetMapper(sphereMapper);
    sphere3->GetProperty()->SetColor(1,0.1,0);
    sphere3->GetProperty()->SetAmbient(0.375);
    sphere3->GetProperty()->SetDiffuse(0.0);
    sphere3->GetProperty()->SetSpecular(0.0);
    sphere3->AddPosition(2.5,0,0);

    sphere4->SetMapper(sphereMapper);
    sphere4->GetProperty()->SetColor(1,0,0);
    sphere4->GetProperty()->SetAmbient(0.5);
    sphere4->GetProperty()->SetDiffuse(0.0);
    sphere4->GetProperty()->SetSpecular(0.0);
    sphere4->AddPosition(3.75,0,0);


    sphere5->SetMapper(sphereMapper);
    sphere5->GetProperty()->SetColor(1,0,0);
    sphere5->GetProperty()->SetAmbient(0.625);
    sphere5->GetProperty()->SetDiffuse(0.0);
    sphere5->GetProperty()->SetSpecular(0.0);
    sphere5->AddPosition(0.0,1.25,0);


    sphere6->SetMapper(sphereMapper);
    sphere6->GetProperty()->SetColor(1,0,0);
    sphere6->GetProperty()->SetAmbient(0.75);
    sphere6->GetProperty()->SetDiffuse(0.0);
    sphere6->GetProperty()->SetSpecular(0.0);
    sphere6->AddPosition(1.25,1.25,0);

    sphere7->SetMapper(sphereMapper);
    sphere7->GetProperty()->SetColor(1,0,0);
    sphere7->GetProperty()->SetAmbient(0.875);
    sphere7->GetProperty()->SetDiffuse(0.0);
    sphere7->GetProperty()->SetSpecular(0.0);
    sphere7->AddPosition(2.5,1.25,0);

    sphere8->SetMapper(sphereMapper);
    sphere8->GetProperty()->SetColor(1,0,0);
    sphere8->GetProperty()->SetAmbient(1.0);
    sphere8->GetProperty()->SetDiffuse(0.0);
    sphere8->GetProperty()->SetSpecular(0.0);
    sphere8->AddPosition(3.75,1.25,0);


    renderer = vtkSmartPointer<vtkRenderer>::New();         //窗口渲染器
    renderer->AddActor(sphere1);
    renderer->AddActor(sphere2);
    renderer->AddActor(sphere3);
    renderer->AddActor(sphere4);
    renderer->AddActor(sphere5);
    renderer->AddActor(sphere6);
    renderer->AddActor(sphere7);
    renderer->AddActor(sphere8);
    renderer->SetBackground(0.1,0.2,0.4);               //设置背景颜色
    ui->openGLWidget->renderWindow()->AddRenderer(renderer);   //

    light = vtkSmartPointer<vtkLight>::New();               //创建光照
    light->SetFocalPoint(1.875,0.6125,0);                   //设置灯光焦点
    light->SetPosition(0.875,1.6125,1);                     //设置灯光位置
                                                            //设置灯光强度SetIntensity()
                                                            //设置灯光锥角SetConeAngle()
                                                            //选择设置平行光或者聚光PositionalOff/On()
    renderer->AddLight(light);
    //GetActiveCamera()获取vtkRenderer里的默认相机
    renderer->GetActiveCamera()->SetFocalPoint(0,0,0);      //设置相机焦点
    renderer->GetActiveCamera()->SetPosition(0,0,1);        //设置相机位置
    renderer->GetActiveCamera()->SetViewUp(0,1,0);          //设置图像正方向
    renderer->GetActiveCamera()->ParallelProjectionOn();    //平行投影/透视投影
    renderer->ResetCamera();
    renderer->GetActiveCamera()->SetParallelScale(4.0);

}

AmbientSpheres::~AmbientSpheres()
{
    delete ui;
}
