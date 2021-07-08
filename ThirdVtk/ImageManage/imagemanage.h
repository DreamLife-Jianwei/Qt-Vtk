#ifndef IMAGEMANAGE_H
#define IMAGEMANAGE_H

#include <QWidget>
#include <QSplitter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QResizeEvent>
#include <QEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include "QVTKOpenGLWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkDICOMImageReader.h"
#include "vtkSmartPointer.h"
#include "vtkImageData.h"
#include "vtkImageActor.h"
#include "vtkResliceImageViewer.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkCellPicker.h"
#include "vtkProperty.h"
#include "vtkImagePlaneWidget.h"
#include "vtkCommand.h"
#include "vtkPlaneSource.h"
#include "vtkInteractorStyleImage.h"
#include "vtkImageMapToColors.h"

class vtkResliceCursorCallback : public vtkCommand
{
public:
  static vtkResliceCursorCallback *New()
  { return new vtkResliceCursorCallback; }

  void Execute( vtkObject *caller, unsigned long ev,void *callData ) override
  {

//    if (ev == vtkResliceCursorWidget::WindowLevelEvent ||ev == vtkCommand::WindowLevelEvent ||ev == vtkResliceCursorWidget::ResliceThicknessChangedEvent)
//    {
//      // Render everything
//      for (int i = 0; i < 3; i++)
//      {
//        this->RCW[i]->Render();
//      }
//      this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
//      return;
//    }

//    vtkImagePlaneWidget* ipw =
//      dynamic_cast< vtkImagePlaneWidget* >( caller );
//    if (ipw)
//    {
//      double* wl = static_cast<double*>( callData );

//      if ( ipw == this->IPW[0] )
//      {
//        this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
//        this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
//      }
//      else if( ipw == this->IPW[1] )
//      {
//        this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
//        this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
//      }
//      else if (ipw == this->IPW[2])
//      {
//        this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
//        this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
//      }
//    }

    vtkResliceCursorWidget *rcw = dynamic_cast<
      vtkResliceCursorWidget * >(caller);
    if (rcw)
    {
      vtkResliceCursorLineRepresentation *rep = dynamic_cast<vtkResliceCursorLineRepresentation * >(rcw->GetRepresentation());
      // Although the return value is not used, we keep the get calls
      // in case they had side-effects
      rep->GetResliceCursorActor()->GetCursorAlgorithm()->GetResliceCursor();
      for (int i = 0; i < 3; i++)
      {
        vtkPlaneSource *ps = static_cast< vtkPlaneSource * >(this->IPW[i]->GetPolyDataAlgorithm());
        ps->SetOrigin(this->RCW[i]->GetResliceCursorRepresentation()->GetPlaneSource()->GetOrigin());
        ps->SetPoint1(this->RCW[i]->GetResliceCursorRepresentation()->GetPlaneSource()->GetPoint1());
        ps->SetPoint2(this->RCW[i]->GetResliceCursorRepresentation()->GetPlaneSource()->GetPoint2());

        // If the reslice plane has modified, update it on the 3D widget
        this->IPW[i]->UpdatePlacement();
      }
    }

    // Render everything
//    for (int i = 0; i < 3; i++)
//    {
//      this->RCW[i]->Render();
//    }
//    this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
  }

  vtkResliceCursorCallback() {}
  vtkImagePlaneWidget* IPW[3];
  vtkResliceCursorWidget *RCW[3];
};




namespace Ui {
class ImageManage;
}

class ImageManage : public QWidget
{
    Q_OBJECT

public:
    explicit ImageManage(QWidget *parent = nullptr);
    ~ImageManage();
    void setCurrentTab(int temp =0);
public slots:
    /**
     * @brief slot_ReaderDICOMImage
     * @param fn
     * 读取DICOM文件
     */
    void slot_ReaderDICOMImage(const char* fn);
protected:
    void resizeEvent(QResizeEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event)override;
private:
    Ui::ImageManage *ui;
    QSplitter *mSplitterMain = nullptr;
    QSplitter *mSplitterVertical = nullptr;
    QSplitter *mSplitterUp = nullptr;
    QSplitter *mSplitterDown = nullptr;
    double color[3] = {0,0,0};
    vtkSmartPointer<vtkDICOMImageReader> imageReader = nullptr;
    int imageDims[3] = {0};
    vtkSmartPointer<vtkResliceImageViewer> riw[3];
    vtkSmartPointer<vtkCellPicker> picker;
//    vtkSmartPointer<vtkProperty> ipwProp;
    vtkSmartPointer<vtkRenderer> render;
    vtkSmartPointer<vtkRenderWindowInteractor> iren;
    vtkSmartPointer<vtkImagePlaneWidget> planeWidget[3];
    vtkSmartPointer<vtkResliceCursorCallback> cbk = nullptr;
};

#endif // IMAGEMANAGE_H
