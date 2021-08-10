#ifndef MYQVTKOPENGLNATIVEWIDGET_H
#define MYQVTKOPENGLNATIVEWIDGET_H

#include <QObject>
#include <QOpenGLWidget>
#include <QScopedPointer> // for QScopedPointer.
#include <QMouseEvent>
#include "QVTKInteractor.h"        // needed for QVTKInteractor
#include "vtkGUISupportQtModule.h" // for export macro
#include "vtkNew.h"                // needed for vtkNew
#include "vtkSmartPointer.h"       // needed for vtkSmartPointer

class QVTKInteractor;
class QVTKInteractorAdapter;
class QVTKRenderWindowAdapter;
class vtkGenericOpenGLRenderWindow;

class MyQVTKOpenGLNativeWidget : public QOpenGLWidget
{
    Q_OBJECT
    typedef QOpenGLWidget Superclass;
public:
    MyQVTKOpenGLNativeWidget(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    MyQVTKOpenGLNativeWidget(vtkGenericOpenGLRenderWindow* window, QWidget* parent = nullptr,
                             Qt::WindowFlags f = Qt::WindowFlags());
    ~MyQVTKOpenGLNativeWidget() override;


    void setRenderWindow(vtkGenericOpenGLRenderWindow* win);
    void setRenderWindow(vtkRenderWindow* win);

    vtkRenderWindow* renderWindow() const;

    QVTKInteractor* interactor() const;

    static QSurfaceFormat defaultFormat(bool stereo_capable = false);

    void setEnableHiDPI(bool enable);
    bool enableHiDPI() const { return this->EnableHiDPI; }

    void setUnscaledDPI(int dpi);
    int unscaledDPI() const { return this->UnscaledDPI; }

    void setDefaultCursor(const QCursor& cursor);
    const QCursor& defaultCursor() const { return this->DefaultCursor; }

    VTK_LEGACY(void SetRenderWindow(vtkGenericOpenGLRenderWindow* win));
    VTK_LEGACY(void SetRenderWindow(vtkRenderWindow* win));

    VTK_LEGACY(vtkRenderWindow* GetRenderWindow());
    VTK_LEGACY(QVTKInteractor* GetInteractor());

    VTK_LEGACY(QVTKInteractorAdapter* GetInteractorAdapter());

    VTK_LEGACY(void setQVTKCursor(const QCursor& cursor));

    VTK_LEGACY(void setDefaultQVTKCursor(const QCursor& cursor));

signals:
    void signal_mouseDoubleClicked();


protected slots:
    virtual void cleanupContext();
    void updateSize();

protected:
    bool event(QEvent* evt) override;
    void initializeGL() override;
    void paintGL() override;
    void mouseDoubleClickEvent(QMouseEvent *event)override;

protected:
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> RenderWindow;
    QScopedPointer<QVTKRenderWindowAdapter> RenderWindowAdapter;
private:
    Q_DISABLE_COPY(MyQVTKOpenGLNativeWidget);

    bool EnableHiDPI;
    int UnscaledDPI;
    QCursor DefaultCursor;

};

#endif // MYQVTKOPENGLNATIVEWIDGET_H
