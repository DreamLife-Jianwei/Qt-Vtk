#include "multiview.h"
#include "ui_multiview.h"

MultiView::MultiView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiView)
{
    ui->setupUi(this);

    graph = vtkMutableDirectedGraph::New();
    vtkIdType a = graph->AddVertex();
    vtkIdType b = graph->AddChild(a);
    vtkIdType c = graph->AddChild(a);
    vtkIdType d = graph->AddChild(b);
    vtkIdType e = graph->AddChild(c);
    vtkIdType f = graph->AddChild(c);

    labels = vtkStringArray::New();
    labels->SetName("Label");
    labels->InsertValue(a, "a");
    labels->InsertValue(b, "b");
    labels->InsertValue(c, "c");
    labels->InsertValue(d, "d");
    labels->InsertValue(e, "e");
    labels->InsertValue(f, "f");
    graph->GetVertexData()->AddArray(labels);


    tree = vtkTree::New();
    bool validTree = tree->CheckedShallowCopy(graph);
    if (!validTree)
    {
        std::cout << "ERROR: Invalid tree" << std::endl;
        graph->Delete();
        labels->Delete();
        tree->Delete();
    }

    view = vtkGraphLayoutView::New();
    view->SetRenderWindow(ui->openGLWidget->renderWindow());
    vtkDataRepresentation* rep =view->SetRepresentationFromInput(tree);
    vtkViewTheme* theme = vtkViewTheme::CreateMellowTheme();
    view->ApplyViewTheme(theme);
    view->SetVertexColorArrayName("VertexDegree");
    view->SetColorVertices(true);
    view->SetVertexLabelArrayName("Label");
    view->SetVertexLabelVisibility(true);

    view2 = vtkGraphLayoutView::New();
    vtkDataRepresentation* rep2 =view2->SetRepresentationFromInput(tree);
    view2->SetVertexLabelArrayName("Label");
    view2->SetVertexLabelVisibility(true);

    link = vtkAnnotationLink::New();
    rep->SetAnnotationLink(link);
    rep2->SetAnnotationLink(link);

    update = ViewUpdater::New();
    update->AddView(view);
    update->AddView(view2);

}

MultiView::~MultiView()
{
    delete ui;
}
