#ifndef THEME_H
#define THEME_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"               //新版本，旧版QVTKWidget
#include "vtkAutoInit.h"
#include "vtkGraphLayoutView.h"
#include "vtkRandomGraphSource.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkViewTheme.h"
namespace Ui {
class Theme;
}

class Theme : public QWidget
{
    Q_OBJECT

public:
    explicit Theme(QWidget *parent = 0);
    ~Theme();

private:
    Ui::Theme *ui;
    vtkRandomGraphSource* source = nullptr;
    vtkGraphLayoutView* view = nullptr;
    vtkViewTheme* theme = nullptr;
};

#endif // THEME_H
