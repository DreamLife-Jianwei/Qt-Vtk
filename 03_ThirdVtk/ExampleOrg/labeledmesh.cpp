#include "labeledmesh.h"
#include "ui_labeledmesh.h"

LabeledMesh::LabeledMesh(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabeledMesh)
{
    ui->setupUi(this);




    int xmin = 200;
    xLength = 100;
    int xmax = xmin + xLength;

    int ymin = 200;
    yLength = 100;
    int ymax = xmin+yLength;

    pts = vtkSmartPointer<vtkPoints>::New();
    pts->InsertPoint(0,xmin,ymin,0);
    pts->InsertPoint(1,xmax,ymin,0);
    pts->InsertPoint(2,xmax,ymax,0);
    pts->InsertPoint(3,xmin,ymax,0);

    vtkSmartPointer<vtkCellArray> rect = vtkSmartPointer<vtkCellArray>::New();

    rect->InsertNextCell(5);
    rect->InsertCellPoint(0);
    rect->InsertCellPoint(1);
    rect->InsertCellPoint(2);
    rect->InsertCellPoint(3);
    rect->InsertCellPoint(0);

    vtkSmartPointer<vtkPolyData> selectRect = vtkSmartPointer<vtkPolyData>::New();
    selectRect->SetPoints(pts);
    selectRect->SetLines(rect);

    vtkSmartPointer<vtkPolyDataMapper2D> rectMapper = vtkSmartPointer<vtkPolyDataMapper2D>::New();

    rectMapper->SetInputData(selectRect);

    vtkSmartPointer<vtkActor2D> rectActor = vtkSmartPointer<vtkActor2D>::New();

    rectActor->SetMapper(rectMapper);

    vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
    vtkSmartPointer<vtkPolyDataMapper> sphereMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphere->GetOutputPort());


    vtkSmartPointer<vtkActor> sphereActor = vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);


    vtkSmartPointer<vtkIdFilter> ids = vtkSmartPointer<vtkIdFilter>::New();
    ids->SetInputConnection(sphere->GetOutputPort());
    ids->PointIdsOn();
    ids->CellIdsOn();
    ids->FieldDataOn();


    vtkSmartPointer<vtkRenderer> ren1 = vtkSmartPointer<vtkRenderer>::New();

    visPts = vtkSmartPointer<vtkSelectVisiblePoints>::New();
    visPts->SetInputConnection(ids->GetOutputPort());
    visPts->SetRenderer(ren1);
    visPts->SelectionWindowOn();
    visPts->SetSelection(xmin,xmin+xLength,ymin,ymin+yLength);



    vtkSmartPointer<vtkLabeledDataMapper> ldm = vtkSmartPointer<vtkLabeledDataMapper>::New();
    ldm->SetInputConnection(visPts->GetOutputPort());
    ldm->SetLabelModeToLabelFieldData();


    vtkSmartPointer<vtkActor2D> pointLabels = vtkSmartPointer<vtkActor2D>::New();
    pointLabels->SetMapper(ldm);


    vtkSmartPointer<vtkCellCenters> cc = vtkSmartPointer<vtkCellCenters>::New();
    cc->SetInputConnection(ids->GetOutputPort());

    visCells = vtkSmartPointer<vtkSelectVisiblePoints>::New();
    visCells->SetInputConnection(cc->GetOutputPort());
    visCells->SetRenderer(ren1);
    visCells->SelectionWindowOn();
    visCells->SetSelection(xmin,xmin+xLength,ymin,ymin+ yLength);



    vtkSmartPointer<vtkLabeledDataMapper> cellmapper = vtkSmartPointer<vtkLabeledDataMapper>::New();
    cellmapper->SetInputConnection(visCells->GetOutputPort());
    cellmapper->SetLabelModeToLabelFieldData();
    cellmapper->GetLabelTextProperty()->SetColor(0,1,0);



    vtkSmartPointer<vtkActor2D> cellLabels = vtkSmartPointer<vtkActor2D>::New();
    cellLabels->SetMapper(cellmapper);

    ui->openGLWidget->renderWindow()->AddRenderer(ren1);

    ren1->AddActor(sphereActor);
    ren1->AddActor2D(rectActor);
    ren1->AddActor2D(pointLabels);
    ren1->AddActor2D(cellLabels);


//    MoveWindow();
//    PlaceWindow(xmin,ymin);



}

LabeledMesh::~LabeledMesh()
{
    delete ui;
}

void LabeledMesh::PlaceWindow(int xmin, int ymin)
{
    int xmax = xmin + xLength;
    int ymax = ymin + yLength;

    visPts->SetSelection(xmin,xmax,ymin,ymax);

    visCells->SetSelection(xmin,xmax,ymin,ymax);


    pts->InsertPoint(0,xmin,ymin,0);
    pts->InsertPoint(1,xmin,ymin,0);
    pts->InsertPoint(2,xmin,ymin,0);
    pts->InsertPoint(3,xmin,ymin,0);

    pts->Modified();
    renwin->Render();
}

void LabeledMesh::MoveWindow()
{
    for(int y = 100;y<300;y+=25)
        for(int x = 100;x<300;x+=25)
            PlaceWindow(x,y);
}
