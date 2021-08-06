#include "myqvtkopenglnativewidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QOpenGLContext>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLTexture>
#include <QPointer>
#include <QScopedValueRollback>
#include <QtDebug>

#include "QVTKInteractor.h"
#include "QVTKInteractorAdapter.h"
#include "QVTKRenderWindowAdapter.h"
#include "vtkCommand.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkOpenGLState.h"


MyQVTKOpenGLNativeWidget::MyQVTKOpenGLNativeWidget(QWidget* parentWdg, Qt::WindowFlags f) : MyQVTKOpenGLNativeWidget(vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New().GetPointer(), parentWdg, f)
{

}
MyQVTKOpenGLNativeWidget::MyQVTKOpenGLNativeWidget(vtkGenericOpenGLRenderWindow* renderWin, QWidget* parentWdg, Qt::WindowFlags f): Superclass(parentWdg, f)
  , RenderWindow(nullptr)
  , RenderWindowAdapter(nullptr)
  , EnableHiDPI(true)
  , UnscaledDPI(72)
  , DefaultCursor(QCursor(Qt::ArrowCursor))
{
    // default to strong focus
    this->setFocusPolicy(Qt::StrongFocus);
    this->setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);
    this->setMouseTracking(true);

    // we use `QOpenGLWidget::resized` instead of `resizeEvent` or `resizeGL` as
    // an indicator to resize our internal buffer size. This is done, since in
    // addition to widget resize,  `resized` gets fired when screen is changed
    // which causes devicePixelRatio changes.
    this->connect(this, SIGNAL(resized()), SLOT(updateSize()));

    this->setRenderWindow(renderWin);

    // enable qt gesture events
    this->grabGesture(Qt::PinchGesture);
    this->grabGesture(Qt::PanGesture);
    this->grabGesture(Qt::TapGesture);
    this->grabGesture(Qt::TapAndHoldGesture);
    this->grabGesture(Qt::SwipeGesture);
}

MyQVTKOpenGLNativeWidget::~MyQVTKOpenGLNativeWidget()
{
    this->makeCurrent();
    this->cleanupContext();
}
void MyQVTKOpenGLNativeWidget::setRenderWindow(vtkGenericOpenGLRenderWindow *win)
{
    if (this->RenderWindow == win)
    {
        return;
    }

    // this will release all OpenGL resources associated with the old render
    // window, if any.
    if (this->RenderWindowAdapter)
    {
        this->makeCurrent();
        this->RenderWindowAdapter.reset(nullptr);
    }
    this->RenderWindow = win;
    if (this->RenderWindow)
    {
        this->RenderWindow->SetReadyForRendering(false);

        // if an interactor wasn't provided, we'll make one by default
        if (!this->RenderWindow->GetInteractor())
        {
            // create a default interactor
            vtkNew<QVTKInteractor> iren;
            // iren->SetUseTDx(this->UseTDx);
            this->RenderWindow->SetInteractor(iren);
            iren->Initialize();

            // now set the default style
            vtkNew<vtkInteractorStyleTrackballCamera> style;
            iren->SetInteractorStyle(style);
        }

        if (this->isValid())
        {
            // this typically means that the render window is being changed after the
            // QVTKOpenGLNativeWidget has initialized itself in a previous update
            // pass, so we emulate the steps to ensure that the new vtkRenderWindow is
            // brought to the same state (minus the actual render).
            this->makeCurrent();
            this->initializeGL();
            this->updateSize();
        }
    }
}

void MyQVTKOpenGLNativeWidget::setRenderWindow(vtkRenderWindow *win)
{
    auto gwin = vtkGenericOpenGLRenderWindow::SafeDownCast(win);
    if (win != nullptr && gwin == nullptr)
    {
        qDebug() << "QVTKOpenGLNativeWidget requires a `vtkGenericOpenGLRenderWindow`. `"
               << win->GetClassName() << "` is not supported.";
    }
    this->setRenderWindow(gwin);
}

vtkRenderWindow *MyQVTKOpenGLNativeWidget::renderWindow() const
{
    return this->RenderWindow;
}

QVTKInteractor *MyQVTKOpenGLNativeWidget::interactor() const
{
    return this->RenderWindow ? QVTKInteractor::SafeDownCast(this->RenderWindow->GetInteractor()) : nullptr;
}

QSurfaceFormat MyQVTKOpenGLNativeWidget::defaultFormat(bool stereo_capable)
{
    return QVTKRenderWindowAdapter::defaultFormat(stereo_capable);
}

void MyQVTKOpenGLNativeWidget::setEnableHiDPI(bool enable)
{
    this->EnableHiDPI = enable;
    if (this->RenderWindowAdapter)
    {
        this->RenderWindowAdapter->setEnableHiDPI(enable);
    }
}

void MyQVTKOpenGLNativeWidget::setUnscaledDPI(int dpi)
{
    this->UnscaledDPI = dpi;
    if (this->RenderWindowAdapter)
    {
        this->RenderWindowAdapter->setUnscaledDPI(dpi);
    }
}

void MyQVTKOpenGLNativeWidget::setDefaultCursor(const QCursor &cursor)
{
    this->DefaultCursor = cursor;
    if (this->RenderWindowAdapter)
    {
        this->RenderWindowAdapter->setDefaultCursor(cursor);
    }
}

void MyQVTKOpenGLNativeWidget::cleanupContext()
{
    this->RenderWindowAdapter.reset(nullptr);
}

void MyQVTKOpenGLNativeWidget::updateSize()
{
    if (this->RenderWindowAdapter)
    {
        this->RenderWindowAdapter->resize(this->width(), this->height());
    }
}

bool MyQVTKOpenGLNativeWidget::event(QEvent *evt)
{
    if (this->RenderWindowAdapter)
    {
        this->RenderWindowAdapter->handleEvent(evt);
    }
    return this->Superclass::event(evt);
}

void MyQVTKOpenGLNativeWidget::initializeGL()
{
    this->Superclass::initializeGL();
    if (this->RenderWindow)
    {
        Q_ASSERT(this->RenderWindowAdapter.data() == nullptr);

        // When a QOpenGLWidget is told to use a QSurfaceFormat with samples > 0,
        // QOpenGLWidget doesn't actually create a context with multi-samples and
        // internally changes the QSurfaceFormat to be samples=0. Thus, we can't
        // rely on the QSurfaceFormat to indicate to us if multisampling is being
        // used. We should use glGetRenderbufferParameteriv(..) to get
        // GL_RENDERBUFFER_SAMPLES to determine the samples used. This is done by
        // in recreateFBO().
        this->RenderWindowAdapter.reset(
                    new QVTKRenderWindowAdapter(this->context(), this->RenderWindow, this));
        this->RenderWindowAdapter->setDefaultCursor(this->defaultCursor());
        this->RenderWindowAdapter->setEnableHiDPI(this->EnableHiDPI);
        this->RenderWindowAdapter->setUnscaledDPI(this->UnscaledDPI);
    }
    this->connect(this->context(), SIGNAL(aboutToBeDestroyed()), SLOT(cleanupContext()),
                  static_cast<Qt::ConnectionType>(Qt::UniqueConnection | Qt::DirectConnection));
}

void MyQVTKOpenGLNativeWidget::paintGL()
{
    this->Superclass::paintGL();
    if (this->RenderWindow)
    {
        Q_ASSERT(this->RenderWindowAdapter);
        this->RenderWindowAdapter->paint();

        // If render was triggered by above calls, that may change the current context
        // due to things like progress events triggering updates on other widgets
        // (e.g. progress bar). Hence we need to make sure to call makeCurrent()
        // before proceeding with blit-ing.
        this->makeCurrent();

        QOpenGLFunctions_3_2_Core* f =
                QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_2_Core>();
        if (f)
        {
            const QSize deviceSize = this->size() * this->devicePixelRatioF();
            this->RenderWindowAdapter->blit(
                        this->defaultFramebufferObject(), GL_COLOR_ATTACHMENT0, QRect(QPoint(0, 0), deviceSize));
        }
    }
    else
    {
        // no render window set, just fill with white.
        QOpenGLFunctions* f = QOpenGLContext::currentContext()->functions();
        f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        f->glClear(GL_COLOR_BUFFER_BIT);
    }
}
//-----------------------------------------------------------------------------
#if !defined(VTK_LEGACY_REMOVE)
void MyQVTKOpenGLNativeWidget::SetRenderWindow(vtkRenderWindow* win)
{
  VTK_LEGACY_REPLACED_BODY(
    QVTKOpenGLNativeWidget::SetRenderWindow, "VTK 9.0", QVTKOpenGLNativeWidget::setRenderWindow);
  vtkGenericOpenGLRenderWindow* gwin = vtkGenericOpenGLRenderWindow::SafeDownCast(win);
  if (gwin == nullptr && win != nullptr)
  {
    qDebug() << "QVTKOpenGLNativeWidget requires a `vtkGenericOpenGLRenderWindow`. `"
             << win->GetClassName() << "` is not supported.";
  }
  this->setRenderWindow(gwin);
}
#endif

//-----------------------------------------------------------------------------
#if !defined(VTK_LEGACY_REMOVE)
void MyQVTKOpenGLNativeWidget::SetRenderWindow(vtkGenericOpenGLRenderWindow* win)
{
  VTK_LEGACY_REPLACED_BODY(
    QVTKOpenGLNativeWidget::SetRenderWindow, "VTK 9.0", QVTKOpenGLNativeWidget::setRenderWindow);
  this->setRenderWindow(win);
}
#endif

//-----------------------------------------------------------------------------
#if !defined(VTK_LEGACY_REMOVE)
vtkRenderWindow* MyQVTKOpenGLNativeWidget::GetRenderWindow()
{
  VTK_LEGACY_REPLACED_BODY(
    QVTKOpenGLNativeWidget::GetRenderWindow, "VTK 9.0", QVTKOpenGLNativeWidget::renderWindow);
  return this->renderWindow();
}
#endif

//-----------------------------------------------------------------------------
#if !defined(VTK_LEGACY_REMOVE)
QVTKInteractorAdapter* MyQVTKOpenGLNativeWidget::GetInteractorAdapter()
{
  VTK_LEGACY_BODY(QVTKOpenGLNativeWidget::GetInteractorAdapter, "VTK 9.0");
  return nullptr;
}
#endif

//-----------------------------------------------------------------------------
#if !defined(VTK_LEGACY_REMOVE)
QVTKInteractor* MyQVTKOpenGLNativeWidget::GetInteractor()
{
  VTK_LEGACY_REPLACED_BODY(
    QVTKOpenGLNativeWidget::GetInteractor, "VTK 9.0", QVTKOpenGLNativeWidget::interactor);
  return this->interactor();
}
#endif

//-----------------------------------------------------------------------------
#if !defined(VTK_LEGACY_REMOVE)
void MyQVTKOpenGLNativeWidget::setQVTKCursor(const QCursor& cursor)
{
  VTK_LEGACY_REPLACED_BODY(
    QVTKOpenGLNativeWidget::setQVTKCursor, "VTK 9.0", QVTKOpenGLNativeWidget::setCursor);
  this->setCursor(cursor);
}
#endif

//-----------------------------------------------------------------------------
#if !defined(VTK_LEGACY_REMOVE)
void MyQVTKOpenGLNativeWidget::setDefaultQVTKCursor(const QCursor& cursor)
{
  VTK_LEGACY_REPLACED_BODY(QVTKOpenGLNativeWidget::setDefaultQVTKCursor, "VTK 9.0",
    QVTKOpenGLNativeWidget::setDefaultCursor);
  this->setDefaultCursor(cursor);
}
#endif
