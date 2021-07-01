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



protected:
    void resizeEvent(QResizeEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event)override;

private:
    Ui::ImageManage *ui;
    QSplitter *mSplitterMain = nullptr;
    QSplitter *mSplitterVertical = nullptr;
    QSplitter *mSplitterUp = nullptr;
    QSplitter *mSplitterDown = nullptr;
//    QPainter *painter_1 = nullptr;

};

#endif // IMAGEMANAGE_H
