#ifndef BESTOPENGLWIDGET_H
#define BESTOPENGLWIDGET_H

#include "vtkGUISupportQtModule.h"
#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>
// Forward Qt class declarations
class QSurfaceFormat;
class QOpenGLContext;
//class QVTKInteractor;
class QVTKInteractorAdapter;
class QVTKOpenGLWindow;
class vtkGenericOpenGLRenderWindow;
class vtkRenderWindow;
class vtkRenderWindowInteractor;

enum MBackGroundColor
{
    Normal=0,
    Axial,
    Sagittal,
    Coronal,
    ThreeD
};

class BESTOpenGLWidget : public QWidget
{
    Q_OBJECT
    typedef QWidget Superclass;
public:
    BESTOpenGLWidget(QWidget* parent = Q_NULLPTR,
                     Qt::WindowFlags f = Qt::WindowFlags());
    BESTOpenGLWidget(QOpenGLContext *shareContext, QWidget* parent = Q_NULLPTR,
                     Qt::WindowFlags f = Qt::WindowFlags());
    BESTOpenGLWidget(vtkGenericOpenGLRenderWindow* w,
                     QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    BESTOpenGLWidget(vtkGenericOpenGLRenderWindow* w, QOpenGLContext *shareContext,
                     QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~BESTOpenGLWidget() override;


    void SetWindowPaintColor(int type);


    /**
   * Set the VTK render window for the internal QVTKOpenGLWindow.
   */
    void SetRenderWindow(vtkGenericOpenGLRenderWindow* win);
    void SetRenderWindow(vtkRenderWindow* win);

    /**
   * Get the VTK render window from the internal QVTKOpenGLWindow.
   */
    virtual vtkRenderWindow* GetRenderWindow();

    /**
   * Get the VTK render window interactor from the internal QVTKOpenGLWindow.
   */
    virtual vtkRenderWindowInteractor* GetInteractor();

    /**
   * Get the QEvent to VTK events translator.
   */
    virtual QVTKInteractorAdapter* GetInteractorAdapter();

    /**
   * Returns a typical QSurfaceFormat suitable for most applications using
   * QVTKOpenGLWidget. Note that this is not the QSurfaceFormat that gets used
   * if none is specified. That is set using `QSurfaceFormat::setDefaultFormat`.
   */
    static QSurfaceFormat defaultFormat();

    /**
   * Set the QSurfaceFormat used to create the OpenGL context.
   */
    void setFormat(const QSurfaceFormat& format);

    /**
   * Enable or disable support for HiDPI displays.
   */
    virtual void setEnableHiDPI(bool enable);
    virtual bool enableHiDPI() { return this->EnableHiDPI; }

    /**
   * Set the cursor on this widget.
   */
    void setQVTKCursor(const QCursor &cursor);

    /**
   * Returns true if the internal QOpenGLWindow's is valid, i.e. if OpenGL
   * resources, like the context, have been successfully initialized.
   */
    virtual bool isValid();

    /**
   * Forward events to the internal QVTKOpenGLWindow when events are
   * explicitly sent to the widget. This is required due to QTBUG-61836 that
   * prevents the use of the flag Qt::TransparentForMouseInput.
   * This flag indicates that the internal window let events pass through.
   * When this misbehavior gets fixed, events will be forwarded to this widget's
   * event() callback, that will then forward them back to the window.
   */
    virtual bool testingEvent(QEvent* e);

    /**
   * Expose internal QVTKOpenGLWindow::grabFramebuffer(). Renders and returns
   * a 32-bit RGB image of the framebuffer.
   */
    QImage grabFramebuffer();

signals:
    /**
   * This signal will be emitted whenever a mouse event occurs within the QVTK window.
   */
    void mouseEvent(QMouseEvent* event);

    /**
   * This signal will be emitted whenever a resize event occurs within the QVTK window.
   */
    void resized();

    /**
   * Forward events to the internal QVTK window.
   */
    void widgetEvent(QEvent* e);

private slots:
    /**
   * called as a response to `QVTKOpenGLWindow::event` to forward the signal.
   */
    void windowEvent(QEvent* event);

protected:
    virtual void resizeEvent(QResizeEvent* event) Q_DECL_OVERRIDE;
    virtual bool event(QEvent* e) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *);
    bool EnableHiDPI = true;

private:
    QVTKOpenGLWindow* qVTKOpenGLWindowInternal;
    int mPaintType = MBackGroundColor::Normal;

};

#endif // BESTOPENGLWIDGET_H
