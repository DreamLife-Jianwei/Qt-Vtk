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
    imageReader->SetDirectoryName(fn);                              //这里主要，是文件夹哈，不是文件名
    imageReader->Update();                                          //得更新呀，惰性渲染
    imageReader->GetOutput()->GetDimensions(imageDims);             //还不理解,翻译为获取维度,注释掉以后三维中有影响




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
        rep->GetResliceCursorActor()->GetCursorAlgorithm()->SetReslicePlaneNormal(i);
        riw[i]->SetInputData(imageReader->GetOutput());             //数据输入源
        riw[i]->SetResliceCursor(riw[0]->GetResliceCursor());       //设置为同一个对象，以便实现视图同步
        riw[i]->SetSliceOrientation(i);                             //设置切片方向
        riw[i]->GetRenderer()->SetBackground(0,0,0);                //设置背景
        riw[i]->SetResliceModeToAxisAligned();                      //设置切片模式为轴对齐

    }

    //拾取器
    picker = vtkSmartPointer<vtkCellPicker>::New();
    picker->SetTolerance(0.005);            //设置公差
    //    ipwProp = vtkSmartPointer<vtkProperty>::New();        //属性
    render = vtkSmartPointer<vtkRenderer>::New();           //渲染器
    ui->widget_4->GetRenderWindow()->AddRenderer(render);
    for(auto i = 0;i<3;i++)
    {
        //VTKImagePlaneWidget 是一个3D交互部件，用来重切图像数据
        planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
        planeWidget[i]->SetInteractor(ui->widget_4->GetInteractor());
        planeWidget[i]->SetPicker(picker);
        planeWidget[i]->RestrictPlaneToVolumeOn();
        color[0] = color[1] = color[2] = 0;
        color[i] = 1;
        planeWidget[i]->GetPlaneProperty()->SetColor(color);
        //        planeWidget[i]->SetTexturePlaneProperty(ipwProp);
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


    cbk = vtkSmartPointer<vtkResliceCursorCallback>::New();

    for (int i = 0; i < 3; i++)
    {
        cbk->IPW[i] = planeWidget[i];
        cbk->RCW[i] = riw[i]->GetResliceCursorWidget();
        riw[i]->GetResliceCursorWidget()->AddObserver(vtkResliceCursorWidget::ResliceAxesChangedEvent, cbk );
        riw[i]->GetResliceCursorWidget()->AddObserver(vtkResliceCursorWidget::WindowLevelEvent, cbk );
        riw[i]->GetResliceCursorWidget()->AddObserver(vtkResliceCursorWidget::ResliceThicknessChangedEvent, cbk );
        riw[i]->GetResliceCursorWidget()->AddObserver(vtkResliceCursorWidget::ResetCursorEvent, cbk );
        riw[i]->GetInteractorStyle()->AddObserver(vtkCommand::WindowLevelEvent, cbk );

        // Make them all share the same color map.
        riw[i]->SetLookupTable(riw[0]->GetLookupTable());
        planeWidget[i]->GetColorMap()->SetLookupTable(riw[0]->GetLookupTable());
        //planeWidget[i]->GetColorMap()->SetInput(riw[i]->GetResliceCursorWidget()->GetResliceCursorRepresentation()->GetColorMap()->GetInput());
        planeWidget[i]->SetColorMap(riw[i]->GetResliceCursorWidget()->GetResliceCursorRepresentation()->GetColorMap());

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
/**
 * @brief ImageManage::eventFilter
 * @param watched
 * @param event
 * @return
 * Qt绘制函数，在QVTKQidget中好像不好使。
 */
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


