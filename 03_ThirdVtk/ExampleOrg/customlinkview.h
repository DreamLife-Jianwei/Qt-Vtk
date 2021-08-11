#ifndef CUSTOMLINKVIEW_H
#define CUSTOMLINKVIEW_H

#include <QWidget>
#include "QVTKOpenGLNativeWidget.h"
namespace Ui {
class CustomLinkView;
}

class CustomLinkView : public QWidget
{
    Q_OBJECT

public:
    explicit CustomLinkView(QWidget *parent = nullptr);
    ~CustomLinkView();

private:
    Ui::CustomLinkView *ui;
};

#endif // CUSTOMLINKVIEW_H
