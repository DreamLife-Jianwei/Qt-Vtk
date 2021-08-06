#include "qcharttable.h"
#include "ui_qcharttable.h"

QChartTable::QChartTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QChartTable)
{
    ui->setupUi(this);

    qvtkWidget = new QVTKOpenGLNativeWidget(ui->openGLWidget);

    qvtkWidget->setRenderWindow(renderWidow);


    view->SetRenderWindow(renderWidow);

    view->SetInteractor(renderWidow->GetInteractor());


    arrX->SetName("X Axis");
    table->AddColumn(arrX);

    arrC->SetName("Cosine");
    table->AddColumn(arrC);

    arrS->SetName("Sine");
    table->AddColumn(arrS);



    int numPoints = 29;
    float inc = 7.0 / (numPoints - 1);
    table->SetNumberOfRows(numPoints);
    for(auto i = 0;i< numPoints;i++)
    {
        table->SetValue(i,0,i * inc);
        table->SetValue(i,1,cos(i * inc)+0.0);
        table->SetValue(i,2,sin(i * inc)+0.0);
    }

    view->GetScene()->AddItem(chart);

    line = chart->AddPlot(vtkChart::LINE);
    line->SetInputData(table,0,1);
    line->SetColor(1,0,1);
    line = chart->AddPlot(vtkChart::LINE);
    line->SetInputData(table,0,2);
    line->SetColor(0,1,1);
    line->SetWidth(2.0);


    tableview->SetSplitMultiComponentColumns(true);
    tableview->AddRepresentationFromInput(table);
    tableview->Update();
    QHBoxLayout *layout = new QHBoxLayout(ui->openGLWidget);
    layout->addWidget(qvtkWidget, 2);
    layout->addWidget(tableview->GetWidget());






}

QChartTable::~QChartTable()
{
    delete ui;
}

void QChartTable::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
//    qvtkWidget->resize(ui->widget->size());
}
