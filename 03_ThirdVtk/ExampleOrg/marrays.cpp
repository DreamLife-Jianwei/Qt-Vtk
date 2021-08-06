#include "marrays.h"
#include "ui_marrays.h"
#include <QDebug>
MArrays::MArrays(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MArrays)
{
    ui->setupUi(this);


    colors->SetColor("TestColor",1.0,0.0,0.0);


    pcoords->SetNumberOfComponents(3);          //实例中说是设置其组件数为3，默认为1，这里还不明白
    pcoords->SetNumberOfTuples(4);              //设置pcoords可以容纳4个Tuples数据

    for (auto i = 0ul;i<pts.size();++i) {       //把数据加进去
        pcoords->SetTuple(i,pts[i].data());
    }

    points->SetData(pcoords);                   //我理解就是数据放进这个点数组里面

    strips->InsertNextCell(4);                  //这个干啥还不清楚
    strips->InsertCellPoint(0);
    strips->InsertCellPoint(1);
    strips->InsertCellPoint(2);
    strips->InsertCellPoint(3);

//    temperature->SetName("Temperature");      //这个为啥要设置名字，咱也不懂，先撸为敬
                                                //测试这个和颜色有关系
    temperature->InsertNextValue(10);
    temperature->InsertNextValue(20);
    temperature->InsertNextValue(50);
    temperature->InsertNextValue(80);

//    vorticity->SetName("Vorticity");          //这个为啥要设置名字，咱也不懂，先撸为敬
    vorticity->InsertNextValue(1.0);
    vorticity->InsertNextValue(1.0);
    vorticity->InsertNextValue(1.0);
    vorticity->InsertNextValue(1.0);

    polydata->SetPoints(points);
    polydata->SetStrips(strips);
    polydata->GetPointData()->SetScalars(temperature);      //官方文档中就一句话，设置标量数据，啥是标量数据呀，咋就能修改颜色了
    polydata->GetPointData()->AddArray(vorticity);

    mapper->SetInputData(polydata);         //映射器输入数据
    mapper->SetScalarRange(0,80);           //又一个Scalar 也能影响颜色，这尼玛，这个好像是要区我们temperature中的区一部分吧

    actor->SetMapper(mapper);               //

    render->AddActor(actor);                //添加actor
    render->SetBackground(colors->GetColor3d("TestColor").GetData());   //设置渲染背景

    ui->openGLWidget->renderWindow()->AddRenderer(render);         //添加渲染器

}

MArrays::~MArrays()
{
    delete ui;
}
