#include "graphitem.h"
#include "ui_graphitem.h"

GraphItem::GraphItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphItem)
{
    ui->setupUi(this);

    mview = vtkSmartPointer<vtkContextView>::New();
    mview->GetRenderer()->SetBackground(0.0, 1.0, 1.0);
    mview->GetRenderWindow()->SetSize(800, 600);

    source = vtkSmartPointer<vtkRandomGraphSource>::New();
    source->SetNumberOfVertices(100);
    source->SetNumberOfEdges(0);
    source->StartWithTreeOn();
    source->Update();
    item = vtkSmartPointer<vtkGraphItem>::New();
    item->SetGraph(source->GetOutput());
    mview->GetScene()->AddItem(item);

    anim = vtkSmartPointer<GraphAnimate>::New();

    anim->view = mview;
    anim->GraphItem = item;
    mview->SetRenderWindow(ui->openGLWidget->renderWindow());
    mview->GetRenderWindow()->GetInteractor()->Initialize();
    mview->GetRenderWindow()->GetInteractor()->CreateOneShotTimer(10);
    mview->GetRenderWindow()->GetInteractor()->AddObserver(vtkCommand::TimerEvent, anim);



}

GraphItem::~GraphItem()
{
    delete ui;
}

void GraphItem::startinteractor()
{
    //    view->GetRenderWindow()->GetInteractor()->Start();
}
