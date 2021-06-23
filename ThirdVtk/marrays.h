#ifndef MARRAYS_H
#define MARRAYS_H

#include <QWidget>
#include "QVTKOpenGLWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
namespace Ui {
class MArrays;
}

class MArrays : public QWidget
{
    Q_OBJECT

public:
    explicit MArrays(QWidget *parent = 0);
    ~MArrays();

private:
    Ui::MArrays *ui;
};

#endif // MARRAYS_H
