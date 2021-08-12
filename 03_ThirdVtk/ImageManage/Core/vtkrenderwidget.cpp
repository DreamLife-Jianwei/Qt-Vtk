#include "vtkrenderwidget.h"
#include "ui_vtkrenderwidget.h"
#include <QtDebug>
VTKRenderWidget::VTKRenderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VTKRenderWidget)
{
    ui->setupUi(this);
    connect(ui->openGLWidget,&MyQVTKOpenGLNativeWidget::signal_mouseDoubleClicked,this,[=](){emit signal_mouseDoubleClicked();});

    m_OpenFolderText = new QLabel(this);
    m_OpenFolderText->setText("Please Open Directory");
    m_OpenFolderText->setStyleSheet("QLabel{color: rgb(136, 136, 136);}QLabel{font: 36pt '黑体';}");
    m_OpenFolderText->raise();
    m_Menu_1 = new QMenu(this);
    test = new QAction(m_Menu_1);
    test->setText("ABC");
    test->setCheckable(true);
    test1 = new QAction(m_Menu_1);
    test1->setText("EFG");
    test1->setCheckable(true);
    m_Menu_1->addAction(test);
    m_Menu_1->addAction(test1);
    ui->pushButton_1->setMenu(m_Menu_1);
    ui->pushButton_2->setMenu(m_Menu_1);
    ui->pushButton_3->setMenu(m_Menu_1);

    ui->pushButton_1->setStyleSheet("QPushButton::menu-indicator{image:none;}"      //不显示下拉图标
                                    "QPushButton{border-image:url(:/ImageManage/Images/ImageManage/btn_n_1.png);}"
                                    "QPushButton:hover{border-image:url(:/ImageManage/Images/ImageManage/btn_p_1.png);}"
                                    "QPushButton:pressed{border-image:url(:/ImageManage/Images/ImageManage/btn_n_1.png);}");
    ui->pushButton_2->setStyleSheet("QPushButton::menu-indicator{image:none;}"      //不显示下拉图标
                                    "QPushButton{border-image:url(:/ImageManage/Images/ImageManage/btn_n_2.png);}"
                                    "QPushButton:hover{border-image:url(:/ImageManage/Images/ImageManage/btn_p_2.png);}"
                                    "QPushButton:pressed{border-image:url(:/ImageManage/Images/ImageManage/btn_n_2.png);}");
    ui->pushButton_3->setStyleSheet("QPushButton::menu-indicator{image:none;}"      //不显示下拉图标
                                    "QPushButton{border-image:url(:/ImageManage/Images/ImageManage/btn_n_3.png);}"
                                    "QPushButton:hover{border-image:url(:/ImageManage/Images/ImageManage/btn_p_3.png);}"
                                    "QPushButton:pressed{border-image:url(:/ImageManage/Images/ImageManage/btn_n_3.png);}");
    ui->pushButton_1->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

}

VTKRenderWidget::~VTKRenderWidget()
{
    delete ui;
}

void VTKRenderWidget::set_BackGroundColor(int r, int g, int b, int a)
{
    m_BackGroundColor.setRgb(r,g,b,a);
    this->update();
}

void VTKRenderWidget::set_OpenFolderEnable(bool enable)
{
    if(enable)
        m_OpenFolderText->show();
    else
        m_OpenFolderText->hide();
}

vtkRenderWindow *VTKRenderWidget::renderWindow() const
{
    if(ui->openGLWidget)
        return ui->openGLWidget->renderWindow();
    return nullptr;
}

QVTKInteractor *VTKRenderWidget::interactor() const
{
    if(ui->openGLWidget)
        return ui->openGLWidget->interactor();
    else
        return nullptr;
}

void VTKRenderWidget::setRenderWindow(vtkGenericOpenGLRenderWindow *win)
{
    if(ui->openGLWidget)
        ui->openGLWidget->setRenderWindow(win);
}

void VTKRenderWidget::setRenderWindow(vtkRenderWindow *win)
{
    if(ui->openGLWidget)
        ui->openGLWidget->setRenderWindow(win);
}

void VTKRenderWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(m_BackGroundColor);
    p.drawRect(rect());
}

void VTKRenderWidget::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    ui->openGLWidget->move(2,2);
    ui->openGLWidget->resize(this->width()-4,this->height()-4);

    ui->pushButton_1->move(this->width()-ui->pushButton_1->width()-7,7);
    ui->pushButton_2->move(this->width()-ui->pushButton_1->width()*2-12,7);
    ui->pushButton_3->move(this->width()-ui->pushButton_1->width()*3-17,7);

    m_OpenFolderText->move((this->width()-m_OpenFolderText->width())/2,(this->height()-m_OpenFolderText->height())/2);
    m_OpenFolderText->raise();
}

void VTKRenderWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    ui->pushButton_1->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
}

void VTKRenderWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    ui->pushButton_1->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
}

