#include "imagemanage.h"
#include "ui_imagemanage.h"

class vtkResliceCursorCallback : public vtkCommand
{
public:
  static vtkResliceCursorCallback *New()
  { return new vtkResliceCursorCallback; }
  void Execute( vtkObject *caller, unsigned long ev, void *callData ) override
  {
    if (ev == vtkResliceCursorWidget::WindowLevelEvent || ev == vtkCommand::WindowLevelEvent || ev == vtkResliceCursorWidget::ResliceThicknessChangedEvent)
    {
      // Render everything
      for (int i = 0; i < 3; i++)
      {
        this->RCW[i]->Render();
      }
      this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
      return;
    }
    vtkImagePlaneWidget* ipw = dynamic_cast< vtkImagePlaneWidget* >( caller );
//    qDebug() << "11" << caller << ipw;
    if (ipw)
    {
      double* wl = static_cast<double*>( callData );

      if ( ipw == this->IPW[0] )
      {
        this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
        this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
      }
      else if( ipw == this->IPW[1] )
      {
        this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
        this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
      }
      else if (ipw == this->IPW[2])
      {
        this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
        this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
      }
    }

    vtkResliceCursorWidget *rcw = dynamic_cast<vtkResliceCursorWidget * >(caller);
//    qDebug() << "22" << caller << rcw;
    if (rcw)
    {
      vtkResliceCursorLineRepresentation *rep = dynamic_cast<
        vtkResliceCursorLineRepresentation * >(rcw->GetRepresentation());
      // Although the return value is not used, we keep the get calls
      // in case they had side-effects
      rep->GetResliceCursorActor()->GetCursorAlgorithm()->GetResliceCursor();
      for (int i = 0; i < 3; i++)
      {
        vtkPlaneSource *ps = static_cast< vtkPlaneSource * >(this->IPW[i]->GetPolyDataAlgorithm());
        ps->SetOrigin(this->RCW[i]->GetResliceCursorRepresentation()->GetPlaneSource()->GetOrigin());
        ps->SetPoint1(this->RCW[i]->GetResliceCursorRepresentation()-> GetPlaneSource()->GetPoint1());
        ps->SetPoint2(this->RCW[i]->GetResliceCursorRepresentation()->GetPlaneSource()->GetPoint2());
        // If the reslice plane has modified, update it on the 3D widget
        this->IPW[i]->UpdatePlacement();
      }
    }

    // Render everything
    for (int i = 0; i < 3; i++)
    {
      this->RCW[i]->Render();
    }
    this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
  }

  vtkResliceCursorCallback() {}
  vtkImagePlaneWidget* IPW[3];
  vtkResliceCursorWidget *RCW[3];
};


ImageManage::ImageManage(QWidget *parent) :QWidget(parent),ui(new Ui::ImageManage)
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
    update();
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
    if(!reader)
    {
        reader = vtkSmartPointer<vtkDICOMImageReader>::New();
    }
    reader->SetDirectoryName(fn);                              //这里主要，是文件夹哈，不是文件名
    reader->SetDataByteOrderToLittleEndian();
    reader->Update();                                          //得更新呀，惰性渲染
    reader->GetOutput()->GetDimensions(imageDims);             //还不理解,翻译为获取维度,注释掉以后三维中有影响

    for (auto i = 0; i < 3; i++)
    {
      riw[i] = vtkSmartPointer< vtkResliceImageViewer >::New();
      vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
      riw[i]->SetRenderWindow(renderWindow);
    }
//    ui->widget_1->SetRenderWindow(riw[0]->GetRenderWindow());
    riw[0]->SetupInteractor(ui->widget_1->GetRenderWindow()->GetInteractor());
    riw[0]->SetRenderWindow(ui->widget_1->GetRenderWindow());
//    ui->widget_2->SetRenderWindow(riw[1]->GetRenderWindow());
    riw[1]->SetupInteractor(ui->widget_2->GetRenderWindow()->GetInteractor());
    riw[1]->SetRenderWindow(ui->widget_2->GetRenderWindow());
//    ui->widget_3->SetRenderWindow(riw[2]->GetRenderWindow());
    riw[2]->SetRenderWindow(ui->widget_3->GetRenderWindow());
    riw[2]->SetupInteractor(ui->widget_3->GetRenderWindow()->GetInteractor());
    for (int i = 0; i < 3; i++)
    {
      // make them all share the same reslice cursor object.
      vtkResliceCursorLineRepresentation *rep =vtkResliceCursorLineRepresentation::SafeDownCast(riw[i]->GetResliceCursorWidget()->GetRepresentation());
      riw[i]->SetResliceCursor(riw[0]->GetResliceCursor());
      rep->GetResliceCursorActor()->GetCursorAlgorithm()->SetReslicePlaneNormal(i);
      riw[i]->SetInputData(reader->GetOutput());
      riw[i]->SetSliceOrientation(i);
      riw[i]->SetResliceModeToAxisAligned();
    }
    picker = vtkSmartPointer<vtkCellPicker>::New();
    picker->SetTolerance(0.005);
    ipwProp = vtkSmartPointer<vtkProperty>::New();
    ren = vtkSmartPointer< vtkRenderer >::New();
    ui->widget_4->GetRenderWindow()->AddRenderer(ren);
    for (int i = 0; i < 3; i++)
    {
      planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
      planeWidget[i]->SetInteractor( ui->widget_4->GetInteractor());
      planeWidget[i]->SetPicker(picker);
      planeWidget[i]->RestrictPlaneToVolumeOn();
      color[0] = 0;
      color[1] = 0;
      color[2] = 0;
      color[i] = 1;
      planeWidget[i]->GetPlaneProperty()->SetColor(color);
      color[0] = 0;
      color[1] = 0;
      color[2] = 0;
      riw[i]->GetRenderer()->SetBackground( color );
      planeWidget[i]->SetTexturePlaneProperty(ipwProp);
      planeWidget[i]->TextureInterpolateOff();
      planeWidget[i]->SetResliceInterpolateToLinear();
      planeWidget[i]->SetInputConnection(reader->GetOutputPort());
      planeWidget[i]->SetPlaneOrientation(i);
      planeWidget[i]->SetSliceIndex(imageDims[i]/2);
      planeWidget[i]->DisplayTextOn();
      planeWidget[i]->SetDefaultRenderer(ren);
      planeWidget[i]->SetWindowLevel(1358, 0);
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
//    ui->widget_1->GetRenderWindow()->Render();
//    ui->widget_2->GetRenderWindow()->Render();
//    ui->widget_3->GetRenderWindow()->Render();
//    ui->widget_4->GetRenderWindow()->Render();

    //十字线
    for (int i = 0; i < 3; i++)
      {
        riw[i]->SetResliceMode(1);
        riw[i]->GetRenderer()->ResetCamera();
        riw[i]->Render();
      }
// 还不知道干啥
//    for (int i = 0; i < 3; i++)
//      {
//        riw[i]->SetThickMode(1);
//        riw[i]->Render();
//      }

//    for (int i = 0; i < 3; i++)
//      {
//        vtkImageSlabReslice *thickSlabReslice = vtkImageSlabReslice::SafeDownCast(
//            vtkResliceCursorThickLineRepresentation::SafeDownCast(
//              riw[i]->GetResliceCursorWidget()->GetRepresentation())->GetReslice());
//        thickSlabReslice->SetBlendMode(1);
//        riw[i]->Render();
//      }


}

void ImageManage::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    mSplitterMain->resize(this->size());
}



