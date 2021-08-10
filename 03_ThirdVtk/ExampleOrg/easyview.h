#ifndef EASYVIEW_H
#define EASYVIEW_H

#include <QWidget>

namespace Ui {
class EasyView;
}

class EasyView : public QWidget
{
    Q_OBJECT

public:
    explicit EasyView(QWidget *parent = nullptr);
    ~EasyView();

private:
    Ui::EasyView *ui;
};

#endif // EASYVIEW_H
