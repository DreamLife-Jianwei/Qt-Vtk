#include "cube.h"
#include "ui_cube.h"

Cube::Cube(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cube)
{
    ui->setupUi(this);


    pts = {{{{0, 0, 0}},
            {{1, 0, 0}},
            {{1, 1, 0}},
            {{0, 1, 0}},
            {{0, 0, 1}},
            {{1, 0, 1}},
            {{1, 1, 1}},
            {{0, 1, 1}}}};

    ordering = {{{{0, 1, 2, 3}},
                 {{4, 5, 6, 7}},
                 {{0, 1, 5, 4}},
                 {{1, 2, 6, 5}},
                 {{2, 3, 7, 6}},
                 {{3, 0, 4, 7}}}};



    cube = vtkPolyData::New();
    points = vtkPoints::New();
    polys = vtkCellArray::New();
    scalars = vtkFloatArray::New();


    for(auto i =0;i<pts.size();++i)
    {
        points->InsertPoint(i,pts[i].data());
        scalars->InsertTuple1(i,i);
    }

    for(auto && i : ordering)
        polys->InsertNextCell(vtkIdType(i.size()),i.data());


    cube->SetPoints(points);
    cube->SetPolys(polys);
    cube->GetPointData()->SetScalars(scalars);

    mapper = vtkPolyDataMapper::New();
    mapper->SetInputData(cube);
    mapper->SetScalarRange(cube->GetScalarRange());

    actor = vtkActor::New();
    actor->SetMapper(mapper);


    render = vtkRenderer::New();
    render->AddActor(actor);
    colors = vtkNamedColors::New();
    render->SetBackground(colors->GetColor3d("black").GetData());


    ui->openGLWidget->renderWindow()->AddRenderer(render);






}

Cube::~Cube()
{
    delete ui;
}
