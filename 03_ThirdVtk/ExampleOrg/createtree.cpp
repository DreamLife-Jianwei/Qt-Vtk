#include "createtree.h"
#include "ui_createtree.h"
#include <QDebug>
CreateTree::CreateTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTree)
{
    ui->setupUi(this);


    graph = vtkMutableDirectedGraph::New();

    vtkIdType a = graph->AddVertex();
    vtkIdType b = graph->AddChild(a);
    vtkIdType c = graph->AddChild(a);
    vtkIdType d = graph->AddChild(b);
    vtkIdType e = graph->AddChild(c);
    vtkIdType f = graph->AddChild(c);

    lables = vtkStringArray::New();         //标签
    lables->SetName("JianweiLable");
    lables->InsertValue(a,"A-label");
    lables->InsertValue(b,"B-label");
    lables->InsertValue(c,"C-label");
    lables->InsertValue(d,"D-label");
    lables->InsertValue(e,"E-label");
    lables->InsertValue(f,"F-label");

    graph->GetVertexData()->AddArray(lables);

    tree = vtkTree::New();

    bool validTree = tree->CheckedShallowCopy(graph);

    if(!validTree)
    {
        qDebug() << "Faile";

    }



    theme = vtkViewTheme::CreateMellowTheme();
    theme->SetLineWidth(5);                     //线的宽度
    theme->SetCellOpacity(0.8);                 //cell的透明度
    theme->SetCellAlphaRange(0.5,0.5);          //cell的alpha的范围
    theme->SetPointSize(10);                    //点的大小
    theme->SetSelectedCellColor(1,0,1);         //选中边的颜色
    theme->SetSelectedPointColor(1,0,0);        //选中是点的颜色



    view = vtkGraphLayoutView::New();
    view->SetRepresentationFromInput(tree);
    view->ApplyViewTheme(theme);
    view->EdgeLabelVisibilityOn();                  //标签是否可见
    view->SetEdgeLabelArrayName("JianweiLable");
    view->SetVertexColorArrayName("VertexDegree");
    view->SetColorVertices(true);
    view->SetVertexLabelArrayName("JianweiLable");
    view->SetVertexLabelVisibility(true);
    view->Update();
    view->ResetCamera();
    view->SetRenderWindow(ui->openGLWidget->renderWindow());       //设置渲染窗口

}

CreateTree::~CreateTree()
{
    delete ui;
}

void CreateTree::startInteractor()
{
//    view->GetInteractor()->Start();
}
