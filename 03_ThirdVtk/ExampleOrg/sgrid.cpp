#include "sgrid.h"
#include "ui_sgrid.h"

SGrid::SGrid(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SGrid)
{
    ui->setupUi(this);
    sgrid->SetDimensions(dims.data());
    vectors->SetNumberOfComponents(3);
    vectors->SetNumberOfTuples(dims[0] * dims[1] * dims[2]);
    points->Allocate(dims[0] * dims[1] * dims[2]);
    deltaZ = 2.0 / (dims[2] - 1);
    deltaRad = (rMax - rMin) / (dims[1] - 1);
    float x[3], v[3];
    v[2] = 0.0;
    for (auto k = 0; k < dims[2]; k++)
    {
        x[2] = -1.0 + k * deltaZ;
        int kOffset = k * dims[0] * dims[1];
        for (auto j = 0; j < dims[1]; j++)
        {
            float radius = rMin + j * deltaRad;
            int jOffset = j * dims[0];
            for (auto i = 0; i < dims[0]; i++)
            {
                float theta = i * vtkMath::RadiansFromDegrees(15.0);
                x[0] = radius * cos(theta);
                x[1] = radius * sin(theta);
                v[0] = -x[1];
                v[1] = x[0];
                int offset = i + jOffset + kOffset;
                points->InsertPoint(offset, x);
                vectors->InsertTuple(offset, v);
            }
        }
    }
    sgrid->SetPoints(points);
    sgrid->GetPointData()->SetVectors(vectors);
    hedgehog->SetInputData(sgrid);
    hedgehog->SetScaleFactor(0.1);
    sgridMapper->SetInputConnection(hedgehog->GetOutputPort());
    sgridActor->SetMapper(sgridMapper);
    sgridActor->GetProperty()->SetColor(colors->GetColor3d("Indigo").GetData());
    renderer->AddActor(sgridActor);
    renderer->SetBackground(colors->GetColor3d("Cornsilk").GetData());
    renderer->ResetCamera();
    renderer->GetActiveCamera()->Elevation(60.0);
    renderer->GetActiveCamera()->Azimuth(30.0);
    renderer->GetActiveCamera()->Zoom(1.0);
    ui->openGLWidget->renderWindow()->AddRenderer(renderer);
}

SGrid::~SGrid()
{
    delete ui;
}
