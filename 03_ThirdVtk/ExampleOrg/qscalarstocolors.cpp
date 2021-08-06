#include "qscalarstocolors.h"
#include "ui_qscalarstocolors.h"

QScalarsToColors::QScalarsToColors(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QScalarsToColors)
{
    ui->setupUi(this);


    qvtkWidget = new QVTKOpenGLNativeWidget(ui->openGLWidget);


    qvtkWidget->setRenderWindow(renderWindow);

    view->SetRenderWindow(qvtkWidget->renderWindow());
    view->SetInteractor(qvtkWidget->interactor());


    vtkNew<vtkChartXY> chart;
    chart->SetTitle("Chart");
    view->GetScene()->AddItem(chart);

    vtkNew<vtkColorTransferFunction> colorTransferFunction;
    colorTransferFunction->AddHSVSegment(0.,0.,1.,1.,0.3333,0.3333,1.,1.);
    colorTransferFunction->AddHSVSegment(0.3333,0.3333,1.,1.,0.6666,0.6666,1.,1.);
    colorTransferFunction->AddHSVSegment(0.6666,0.6666,1.,1.,1.,0.,1.,1.);
    colorTransferFunction->Build();

    vtkNew<vtkPiecewiseFunction> opacityFunction;
    opacityFunction->AddPoint(0.,0.);
    opacityFunction->AddPoint(0.5,0.5);
    opacityFunction->AddPoint(1.,1.);

    vtkNew<vtkCompositeTransferFunctionItem> item3;
    item3->SetColorTransferFunction(colorTransferFunction);
    item3->SetOpacityFunction(opacityFunction);
    item3->SetOpacity(0.2);
    item3->SetMaskAboveCurve(true);
    chart->AddPlot(item3);
}

QScalarsToColors::~QScalarsToColors()
{
    delete ui;
}

void QScalarsToColors::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    qvtkWidget->resize(ui->openGLWidget->size());
}
