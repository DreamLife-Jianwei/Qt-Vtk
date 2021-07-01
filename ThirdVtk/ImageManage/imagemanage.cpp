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


    ui->widget_1->installEventFilter(this);
    ui->widget_2->installEventFilter(this);
    ui->widget_3->installEventFilter(this);
    ui->widget_4->installEventFilter(this);
    ui->widget_5->installEventFilter(this);

    ui->label->installEventFilter(this);

}

ImageManage::~ImageManage()
{
    delete ui;
}

void ImageManage::setCurrentTab(int temp)
{
    Q_UNUSED(temp);
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




