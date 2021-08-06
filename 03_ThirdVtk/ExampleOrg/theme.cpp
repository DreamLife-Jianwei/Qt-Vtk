#include "theme.h"
#include "ui_theme.h"

Theme::Theme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Theme)
{
    ui->setupUi(this);
    source = vtkRandomGraphSource::New();
    view = vtkGraphLayoutView::New();
    view->SetRepresentationFromInputConnection(source->GetOutputPort());
    theme = vtkViewTheme::CreateMellowTheme();
    view->ApplyViewTheme(theme);
    theme->Delete();
    view->SetRenderWindow(ui->openGLWidget->renderWindow());
    view->SetVertexColorArrayName("VertexDegree");
    view->SetColorVertices(true);
    view->SetVertexLabelArrayName("VertexDegree");
    view->SetVertexLabelVisibility(true);
    view->ResetCamera();
    view->Render();
}

Theme::~Theme()
{
    delete ui;
}
