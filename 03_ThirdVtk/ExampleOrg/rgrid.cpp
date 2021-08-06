#include "rgrid.h"
#include "ui_rgrid.h"

RGrid::RGrid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RGrid)
{
    ui->setupUi(this);



    for(auto&& i : x)
        xCoords->InsertNextValue(i);
    for(auto&& i : y)
        yCoords->InsertNextValue(i);
    for(auto&& i : z)
        zCoords->InsertNextValue(i);

    rgrid->SetDimensions(int(x.size()),int(y.size()),int(z.size()));
    rgrid->SetXCoordinates(xCoords);
    rgrid->SetYCoordinates(yCoords);
    rgrid->SetZCoordinates(zCoords);


    plane->SetInputData(rgrid);
    plane->SetExtent(0,46,16,16,0,43);


    mapper->SetInputConnection(plane->GetOutputPort());


    actor->SetMapper(mapper);
    actor->GetProperty()->SetRepresentationToWireframe();
    actor->GetProperty()->SetColor(colors->GetColor3d("red").GetData());

    vtkRenderer *render =  vtkRenderer::New();
    render->AddActor(actor);
    ui->openGLWidget->renderWindow()->AddRenderer(render);

}

RGrid::~RGrid()
{
    delete ui;
}
