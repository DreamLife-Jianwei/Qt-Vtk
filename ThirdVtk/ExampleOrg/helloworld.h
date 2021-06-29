#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QWidget>
#include "vtkGraphLayoutView.h"
#include "vtkRandomGraphSource.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
namespace Ui {
class HelloWorld;
}

class HelloWorld : public QWidget
{
    Q_OBJECT

public:
    explicit HelloWorld(QWidget *parent = 0);
    ~HelloWorld();

private:
    Ui::HelloWorld *ui;
};

#endif // HELLOWORLD_H
