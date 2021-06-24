#include "marrays.h"
#include "ui_marrays.h"

MArrays::MArrays(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MArrays)
{
    ui->setupUi(this);

    pcoords->SetNumberOfComponents(3);          //实例中说是设置其组件数为3，默认为1，这里还不明白
    pcoords->SetNumberOfTuples(4);              //设置pcoords可以容纳4个Tuples数据

    for (auto i = 0ul;i<pts.size();++i) {       //把数据加进去
        pcoords->SetTuple(i,pts[i].data());
    }

    points->SetData(pcoords);                   //我理解就是数据放进这个点数组里面

    strips->InsertNextCell(4);
    strips->InsertCellPoint(0);
    strips->InsertCellPoint(1);
    strips->InsertCellPoint(2);
    strips->InsertCellPoint(3);

    temperature->SetName("Temperature");
    temperature->InsertNextValue(10);
    temperature->InsertNextValue(20);
    temperature->InsertNextValue(30);
    temperature->InsertNextValue(40);

    vorticity->SetName("Vorticity");
    vorticity->InsertNextValue(2.7);
    vorticity->InsertNextValue(4.1);
    vorticity->InsertNextValue(5.3);
    vorticity->InsertNextValue(3.4);

    polydata->SetPoints(points);
    polydata->SetStrips(strips);
    polydata->GetPointData()->SetScalars(temperature);
    polydata->GetPointData()->AddArray(vorticity);


    mapper->SetInputData(polydata);
    mapper->SetScalarRange(0,40);

    actor->SetMapper(mapper);


    render->AddActor(actor);
    render->SetBackground(colors->GetColor3d("DarkSlateGray").GetData());

    ui->widget->GetRenderWindow()->AddRenderer(render);



}

MArrays::~MArrays()
{
    delete ui;
}
