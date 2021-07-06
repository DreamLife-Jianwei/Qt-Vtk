#include "imagemanage.h"
#include "ui_imagemanage.h"
#include <QtDebug>
static QPoint lastPos;
ImageManage::ImageManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageManage)
{
    ui->setupUi(this);

    /******************窗口大小分割*************************/
    mSplitterMain = new QSplitter(Qt::Horizontal,this);
    mSplitterVertical = new QSplitter(Qt::Vertical,mSplitterMain);
    mSplitterUp = new QSplitter(Qt::Horizontal,mSplitterVertical);
    mSplitterUp->addWidget(ui->widget_1);
    mSplitterUp->addWidget(ui->widget_2);
    mSplitterUp->setStretchFactor(0,1);
    mSplitterUp->setStretchFactor(1,1);
    mSplitterDown = new QSplitter(Qt::Horizontal,mSplitterVertical);
    mSplitterDown->addWidget(ui->widget_3);
    mSplitterDown->addWidget(ui->widget_4);
    mSplitterDown->setStretchFactor(0,1);
    mSplitterDown->setStretchFactor(1,1);
    mSplitterMain->insertWidget(0,mSplitterVertical);
    mSplitterMain->insertWidget(1,ui->widget_5);
    mSplitterMain->setStretchFactor(0,1);               //很魔性啊
}

ImageManage::~ImageManage()
{
    delete ui;
}

void ImageManage::setCurrentTab(int temp)
{
    Q_UNUSED(temp);
}

void ImageManage::slot_ReaderDICOMImage(const char *fn)
{
    if(!imageReader)
    {
        imageReader = vtkSmartPointer<vtkDICOMImageReader>::New();
    }
    imageReader->SetFileName(fn);
    imageReader->Update();
    imageReader->GetOutput()->GetDimensions(imageDims);             //还不理解

    for(auto i = 0;i<3;i++)
    {
        riw[i] = vtkSmartPointer<vtkResliceImageViewer>::New();
    }

    /*这里需要修改一下代码，不然编译会把报错*/
    riw[0]->SetRenderWindow(ui->widget_1->GetRenderWindow());
    riw[0]->SetupInteractor(ui->widget_1->GetRenderWindow()->GetInteractor());

    riw[1]->SetRenderWindow(ui->widget_2->GetRenderWindow());
    riw[1]->SetupInteractor(ui->widget_2->GetRenderWindow()->GetInteractor());

    riw[2]->SetRenderWindow(ui->widget_3->GetRenderWindow());
    riw[2]->SetupInteractor(ui->widget_3->GetRenderWindow()->GetInteractor());

    for(auto i = 0;i<3;i++)
    {
        vtkResliceCursorLineRepresentation *rep = vtkResliceCursorLineRepresentation::SafeDownCast(riw[i]->GetResliceCursorWidget()->GetRepresentation());
        riw[i]->SetResliceCursor(riw[0]->GetResliceCursor());
        rep->GetResliceCursorActor()->GetCursorAlgorithm()->SetReslicePlaneNormal(i);
        riw[i]->SetInputData(imageReader->GetOutput());
        riw[i]->SetSliceOrientation(i);
        riw[i]->SetResliceModeToAxisAligned();
    }

    picker = vtkSmartPointer<vtkCellPicker>::New();
    picker->SetTolerance(0.005);

    ipwProp = vtkSmartPointer<vtkProperty>::New();

    render = vtkSmartPointer<vtkRenderer>::New();

    ui->widget_4->GetRenderWindow()->AddRenderer(render);

    iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    iren  = ui->widget_4->GetInteractor();

    for(auto i = 0;i<3;i++)
    {
        planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
        planeWidget[i]->SetInteractor(iren);
        planeWidget[i]->SetPicker(picker);
        planeWidget[i]->RestrictPlaneToVolumeOn();
        color[i] = 1;
        planeWidget[i]->GetPlaneProperty()->SetColor(color);
        color[0] /= 4.0;
        color[1] /= 4.0;
        color[2] /= 4.0;
        riw[i]->GetRenderer()->SetBackground(color);
        planeWidget[i]->SetTexturePlaneProperty(ipwProp);
        planeWidget[i]->TextureInterpolateOn();
        planeWidget[i]->SetResliceInterpolateToLinear();
        planeWidget[i]->SetInputConnection(imageReader->GetOutputPort());
        planeWidget[i]->SetPlaneOrientation(i);
        planeWidget[i]->SetSliceIndex(imageDims[i]/2);
        planeWidget[i]->DisplayTextOn();
        planeWidget[i]->SetDefaultRenderer(render);
        planeWidget[i]->SetWindowLevel(1358,-27);
        planeWidget[i]->On();
        planeWidget[i]->InteractionOn();
    }

    ui->widget_1->GetRenderWindow()->Render();
    ui->widget_2->GetRenderWindow()->Render();
    ui->widget_3->GetRenderWindow()->Render();
    ui->widget_4->GetRenderWindow()->Render();


}

void ImageManage::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    mSplitterMain->resize(this->size());

}

bool ImageManage::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->widget_1)
    {
        if(event->type() == QEvent::MouseMove)
        {
            QMouseEvent *temp = static_cast<QMouseEvent*>(event);
            lastPos = temp->pos();


            //            if(!painter_1)
            //            {
            //                QPainter *painter_1 = new QPainter(ui->widget_1);
            ////                QPen pen;
            ////                pen.setWidth(5);
            ////                pen.setColor(Qt::red);
            ////                painter_1->setPen(pen);
            ////                painter_1->drawLine(0,lastPos.y(),ui->widget_1->width(),lastPos.y());
            ////                painter_1->drawLine(lastPos.x(),0,lastPos.x(),ui->widget_1->height());
            //            }
            //            else
            //            {
            ////                painter_1->drawLine(0,lastPos.y(),ui->widget_1->width(),lastPos.y());
            ////                painter_1->drawLine(lastPos.x(),0,lastPos.x(),ui->widget_1->height());
            //            }

        }
    }
    return QWidget::eventFilter(watched,event);
}




