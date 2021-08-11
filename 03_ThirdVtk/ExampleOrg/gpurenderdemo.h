#ifndef GPURENDERDEMO_H
#define GPURENDERDEMO_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"
namespace Ui {
class GPURenderDemo;
}

class GPURenderDemo : public QWidget
{
    Q_OBJECT

public:
    explicit GPURenderDemo(QWidget *parent = nullptr);
    ~GPURenderDemo();

private:
    Ui::GPURenderDemo *ui;
};

#endif // GPURENDERDEMO_H
