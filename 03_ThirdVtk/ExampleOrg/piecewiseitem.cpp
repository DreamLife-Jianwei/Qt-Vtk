#include "piecewiseitem.h"
#include "ui_piecewiseitem.h"

PiecewiseItem::PiecewiseItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PiecewiseItem)
{
    ui->setupUi(this);


    view = vtkSmartPointer<vtkContextView>::New();
    view->SetRenderWindow(ui->openGLWidget->renderWindow());
    view->GetRenderer()->SetBackground(0,0,1);

    source = vtkSmartPointer<vtkPiecewiseFunction>::New();
    source->AddPoint(0,0);
    source->AddPoint(200,200);
    source->AddPoint(400,600);
    source->AddPoint(700,500);

    item = vtkSmartPointer<vtkPiecewiseControlPointsItem>::New();
    item->SetPiecewiseFunction(source);

    view->GetScene()->AddItem(item);



}

PiecewiseItem::~PiecewiseItem()
{
    delete ui;
}
