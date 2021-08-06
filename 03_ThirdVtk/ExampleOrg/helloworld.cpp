#include "helloworld.h"
#include "ui_helloworld.h"

HelloWorld::HelloWorld(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelloWorld)
{
    ui->setupUi(this);

    vtkRandomGraphSource *source = vtkRandomGraphSource::New();

    vtkGraphLayoutView *view = vtkGraphLayoutView::New();
    view->SetRepresentationFromInputConnection(source->GetOutputPort());
    view->SetRenderWindow(ui->openGLWidget->renderWindow());
    view->ResetCamera();
    view->Render();

}

HelloWorld::~HelloWorld()
{
    delete ui;
}
