#include "bestopenglwindow.h"
// VTK headers include
#include "QVTKInteractor.h"
#include "QVTKInteractorAdapter.h"
#include "vtkEventQtSlotConnect.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkRenderWindowInteractor.h"

#ifdef __APPLE__
#include "vtkOpenGLState.h"
#endif

// Qt headers include
#include <QMouseEvent>
#include <QtGui/QOffscreenSurface>
#include <QOpenGLFunctions>
#include <QResizeEvent>
#include <QSurfaceFormat>

//-----------------------------------------------------------------------------
BESTOpenGLWindow::BESTOpenGLWindow() : BESTOpenGLWindow(nullptr, QOpenGLContext::currentContext(), NoPartialUpdate, Q_NULLPTR)
{}

//-----------------------------------------------------------------------------
BESTOpenGLWindow::BESTOpenGLWindow(QOpenGLContext *shareContext,UpdateBehavior updateBehavior, QWindow *parent)
    : BESTOpenGLWindow(nullptr, shareContext, updateBehavior, parent)
{}

//-----------------------------------------------------------------------------
BESTOpenGLWindow::BESTOpenGLWindow(vtkGenericOpenGLRenderWindow* w,
                                   QOpenGLContext *shareContext, UpdateBehavior updateBehavior, QWindow *parent)
    : QOpenGLWindow(shareContext, updateBehavior, parent)
    , EnableHiDPI(false)
    , OriginalDPI(0)
    , OffscreenSurface(nullptr)
{
    this->IrenAdapter = new QVTKInteractorAdapter(this);
    this->IrenAdapter->SetDevicePixelRatio(this->devicePixelRatio());
    this->EventSlotConnector = vtkSmartPointer<vtkEventQtSlotConnect>::New();
    this->SetRenderWindow(w);

}

//-----------------------------------------------------------------------------
BESTOpenGLWindow::~BESTOpenGLWindow()
{
    // get rid of the VTK window
    this->SetRenderWindow(nullptr);

    // destroy the offscreen surface if any
    // it must be destroyed after previous call to SetRenderWindow because
    // this function might create a new offscreen surface.
    if (this->OffscreenSurface)
    {
        this->OffscreenSurface->destroy();
        delete this->OffscreenSurface;
    }
}

//-----------------------------------------------------------------------------
vtkGenericOpenGLRenderWindow* BESTOpenGLWindow::GetRenderWindow()
{
    if (!this->RenderWindow)
    {
        // create a default vtk window
        vtkNew<vtkGenericOpenGLRenderWindow> win;
        this->SetRenderWindow(win);
    }

    return this->RenderWindow;
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::SetRenderWindow(vtkGenericOpenGLRenderWindow* w)
{
    // do nothing if we don't have to
    if(w == this->RenderWindow)
    {
        return;
    }

    // unregister previous window
    if(this->RenderWindow)
    {
        this->RenderWindow->Finalize();
        this->RenderWindow->SetReadyForRendering(false);
        this->RenderWindow->SetMapped(0);
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::WindowMakeCurrentEvent,this, SLOT(MakeCurrent()));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::WindowIsCurrentEvent, this, SLOT(IsCurrent(vtkObject*, unsigned long, void*, void*)));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::WindowFrameEvent, this, SLOT(Frame()));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::StartEvent, this, SLOT(Start()));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::EndEvent, this, SLOT(End()));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::WindowIsDirectEvent, this, SLOT(IsDirect(vtkObject*, unsigned long, void*, void*)));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::WindowSupportsOpenGLEvent, this, SLOT(SupportsOpenGL(vtkObject*, unsigned long, void*, void*)));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::WindowStereoTypeChangedEvent, this, SLOT(UpdateStereoType(vtkObject*, unsigned long, void*, void*)));
        this->EventSlotConnector->Disconnect(this->RenderWindow, vtkCommand::WindowResizeEvent, this, SLOT(ResizeToVTKWindow()));
    }

    // now set the window
    this->RenderWindow = w;

    if(this->RenderWindow == nullptr)
    {
        return;
    }

    // window is not ready until initializeGL() is called
    this->RenderWindow->SetReadyForRendering(false);

    this->RenderWindow->SetForceMaximumHardwareLineWidth(1);
    // if it is mapped somewhere else, unmap it
    this->RenderWindow->Finalize();
    this->RenderWindow->SetMapped(1);

    // tell the vtk window what the size of this window is
    const qreal devicePixelRatio_ = this->devicePixelRatio();
    const QSize widgetSize = this->size();
    const QSize deviceSize = widgetSize * devicePixelRatio_;

    this->IrenAdapter->SetDevicePixelRatio(devicePixelRatio_);

    if (vtkRenderWindowInteractor* iren = this->RenderWindow->GetInteractor())
    {
        iren->SetSize(deviceSize.width(), deviceSize.height());
    }
    this->RenderWindow->SetScreenSize(deviceSize.width(), deviceSize.height());
    this->RenderWindow->SetSize(deviceSize.width(), deviceSize.height());
    this->RenderWindow->SetPosition(this->x() * devicePixelRatio_, this->y() * devicePixelRatio_);

    // if an interactor wasn't provided, we'll make one by default
    if (!this->RenderWindow->GetInteractor())
    {
        // create a default interactor
        vtkNew<QVTKInteractor> iren;
        //iren->SetUseTDx(this->UseTDx); //TODO: handle TDx
        this->RenderWindow->SetInteractor(iren);
        iren->Initialize();

        // now set the default style
        vtkNew<vtkInteractorStyleTrackballCamera> s;
        iren->SetInteractorStyle(s);
    }

    // tell the interactor the size of this window
    this->RenderWindow->GetInteractor()->SetSize(this->width(), this->height());

    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::WindowMakeCurrentEvent, this, SLOT(MakeCurrent()));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::WindowIsCurrentEvent, this, SLOT(IsCurrent(vtkObject*, unsigned long, void*, void*)));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::WindowFrameEvent, this, SLOT(Frame()));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::StartEvent, this, SLOT(Start()));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::EndEvent, this, SLOT(End()));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::WindowIsDirectEvent, this, SLOT(IsDirect(vtkObject*, unsigned long, void*, void*)));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::WindowSupportsOpenGLEvent, this, SLOT(SupportsOpenGL(vtkObject*, unsigned long, void*, void*)));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::WindowStereoTypeChangedEvent, this, SLOT(UpdateStereoType(vtkObject*, unsigned long, void*, void*)));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::WindowResizeEvent, this, SLOT(ResizeToVTKWindow()));
    this->EventSlotConnector->Connect(this->RenderWindow, vtkCommand::CursorChangedEvent, this, SLOT(ChangeCursor(vtkObject*, unsigned long, void*, void*)));
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::initializeGL()
{
    if(!this->RenderWindow)
    {
        return;
    }

    // Update render window according to the format
    BESTOpenGLWindow::copyFromFormat(this->format(), this->RenderWindow);

    this->RenderWindow->OpenGLInitContext();
    // context has been created, allow the window to render
    this->RenderWindow->SetReadyForRendering(true);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::paintGL()
{
    // do not render if the window is not valid and exposed
    if (!this->RenderWindow || !this->isValid() || !this->isExposed())
    {
        return;
    }

    vtkRenderWindowInteractor* iren = this->RenderWindow->GetInteractor();
    if (iren != nullptr && iren->GetEnabled())
    {
        // Don't swap when Qt wants to render otherwise the first draw shows an
        // undefined framebuffer on Windows and Mac.
        bool swapBuffers = this->RenderWindow->GetSwapBuffers();
        this->RenderWindow->SetSwapBuffers(false);
        iren->Render();
        this->RenderWindow->SetSwapBuffers(swapBuffers);
    }
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::Frame()
{
    // do not swap buffers when the window is not exposed
    if(!this->isExposed())
    {
        return;
    }

    // VTK just did a render, tell Qt to swap buffers
    if(this->RenderWindow->GetSwapBuffers() || this->RenderWindow->GetDoubleBuffer() == 0)
    {
        this->context()->makeCurrent(this->context()->surface());
        this->context()->swapBuffers(this->context()->surface());
    }
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::Start()
{
    this->RenderWindow->OpenGLInitState();
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::MakeCurrent()
{
    // Qt uses thread storage based caching that we need to account for.
    // Specifically its version of isCurrent doesn't actually check
    // OpenGL for the current context but rather looks at Qt's local
    // thread storage to see what context Qt most recently set to
    // current.
    //
    // When mixed with VTK this can cause problems. Classes such as
    // importers instantiate renderwindows which in turn can change the
    // current context without Qt knowing about it
    //
    // The end result is that MakeCurrent should not rely on
    // Qt's version of isCurrent to short circuit as it cannot be trusted.
    //
    if (!this->context())
    {
        return;
    }

    // The following reimplements QOpenGLWindow::makeCurrent() logic without
    // binding the default framebuffer.
    // If this window is registered in Qt's windowing system, use it as a surface
    // to make the context current. Otherwise create and use an offscreen surface.
    if (this->handle())
    {
        this->context()->makeCurrent(this);
    }
    else
    {
        if (!this->OffscreenSurface)
        {
            this->OffscreenSurface = new QOffscreenSurface();
            this->OffscreenSurface->setFormat(this->context()->format());
            this->OffscreenSurface->create();
        }
        this->context()->makeCurrent(this->OffscreenSurface);
    }

    // Reset the viewport on the OpenGL state. This is necessary only on
    // MacOS when HiDPI is supported. Enabling HiDPI has the side effect that
    // Cocoa will start overriding any glViewport calls in application code.
    // For reference, see QCocoaWindow::initialize().
#ifdef __APPLE__
    vtkOpenGLState *ostate = this->RenderWindow->GetState();
    ostate->ResetGlViewportState();
#endif

}

//-----------------------------------------------------------------------------
// Note this only checks Qt's local thread storage, not OpenGL and
// therefore may not return the correct value.
//
void BESTOpenGLWindow::IsCurrent(vtkObject*, unsigned long, void*,
                                 void* call_data)
{
    bool* ptr = reinterpret_cast<bool*>(call_data);
    *ptr = this->isCurrent();
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::IsDirect(vtkObject*, unsigned long, void*,
                                void* call_data)
{
    int* ptr = reinterpret_cast<int*>(call_data);
    // QGLFormat::directRendering() being deprecated, return true.
    *ptr = true;
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::SupportsOpenGL(vtkObject*, unsigned long, void*,
                                      void* call_data)
{
    int* ptr = reinterpret_cast<int*>(call_data);
    *ptr = true;
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::UpdateStereoType(vtkObject*, unsigned long, void*, void*)
{
    // VTK_STEREO_CRYSTAL_EYES requires 'stereo' to be enabled on the
    // QSurfaceFormat used for OpenGL context creation. This enables quad-buffer
    // stereo. Every other stereo format should set this boolean to false.

    QSurfaceFormat fmt = this->format();

    bool stereo = (this->RenderWindow->GetStereoType() == VTK_STEREO_CRYSTAL_EYES);
    if(this->format().stereo() == stereo)
    {
        return;
    }

    // request quad-buffer stereo if needed
    fmt.setStereo(stereo);
    this->setFormat(fmt);

    // the format set above only takes effect when create() is called on the
    // widget. To allow switching from one stereo type to another, we explicitly
    // destroy and recreate the widget, in order to recreate the context.
    this->destroy();
    this->show();
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::ResizeToVTKWindow()
{
    // Resize this to its internal render window size. This is necessary only on
    // MacOS when HiDPI is supported. Enabling HiDPI has the side effect that
    // Cocoa will start overriding any glViewport calls in application code.
    // For reference, see QCocoaWindow::initialize().
#ifdef __APPLE__
    this->MakeCurrent();
    int* rwSize = this->RenderWindow->GetSize();
    this->resize(rwSize[0], rwSize[1]);
#endif
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::widgetEvent(QEvent* e)
{
    this->event(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::moveEvent(QMoveEvent* e)
{
    Superclass::moveEvent(e);

    if(this->RenderWindow)
    {
        this->RenderWindow->SetPosition(this->x(), this->y());
    }
}

//-----------------------------------------------------------------------------
bool BESTOpenGLWindow::event(QEvent* e)
{
    // Forward event to the Widget containing this window. This is required
    // due to QTBUG-61836 that prevents the use of the flag
    // Qt::TransparentForMouseInput. This flag should indicate that this window
    // should not catch any event and let them pass through to the widget.
    // The containing widget should then forward back only the required events for
    // this window (such as mouse events and resize events).
    // Until this misbehavior is fixed, we have to handle forwarding of events.
    emit(windowEvent(e));

    if(e->type() == QEvent::TouchBegin ||
            e->type() == QEvent::TouchUpdate ||
            e->type() == QEvent::TouchEnd)
    {
        if(this->RenderWindow)
        {
            this->IrenAdapter->ProcessEvent(e, this->RenderWindow->GetInteractor());
            if (e->isAccepted())
            {
                return true;
            }
        }
    }
    this->makeCurrent();
    return Superclass::event(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::mousePressEvent(QMouseEvent* e)
{
    // do not transmit a MouseButtonPress that generates a double click
    // see QTBUG-25831
    if ((e->type() != QEvent::MouseButtonPress)
            || !(e->flags().testFlag(Qt::MouseEventCreatedDoubleClick)))
    {
        this->ProcessEvent(e);
    }
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::mouseReleaseEvent(QMouseEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::mouseMoveEvent(QMouseEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::mouseDoubleClickEvent(QMouseEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::enterEvent(QEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::leaveEvent(QEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::keyPressEvent(QKeyEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::keyReleaseEvent(QKeyEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::wheelEvent(QWheelEvent* e)
{
    this->ProcessEvent(e);
}

//-----------------------------------------------------------------------------
bool BESTOpenGLWindow::ProcessEvent(QEvent* e)
{
    if (this->RenderWindow && this->RenderWindow->GetReadyForRendering())
    {
        return this->IrenAdapter->ProcessEvent(e, this->RenderWindow->GetInteractor());
    }

    return false;
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::copyFromFormat(const QSurfaceFormat& format, vtkRenderWindow* win)
{
    if (vtkOpenGLRenderWindow* oglWin = vtkOpenGLRenderWindow::SafeDownCast(win))
    {
        oglWin->SetStereoCapableWindow(format.stereo() ? 1 : 0);
        oglWin->SetMultiSamples(format.samples());
        oglWin->SetStencilCapable(format.stencilBufferSize() > 0);
    }
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::copyToFormat(vtkRenderWindow* win, QSurfaceFormat& format)
{
    if (vtkOpenGLRenderWindow* oglWin = vtkOpenGLRenderWindow::SafeDownCast(win))
    {
        format.setStereo(oglWin->GetStereoCapableWindow());
        format.setSamples(oglWin->GetMultiSamples());
        format.setStencilBufferSize(oglWin->GetStencilCapable() ? 8 : 0);
    }
}

//-----------------------------------------------------------------------------
QSurfaceFormat BESTOpenGLWindow::defaultFormat()
{
    QSurfaceFormat fmt;
    fmt.setRenderableType(QSurfaceFormat::OpenGL);
    fmt.setVersion(3, 2);
    fmt.setProfile(QSurfaceFormat::CoreProfile);
    fmt.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    fmt.setRedBufferSize(8);
    fmt.setGreenBufferSize(8);
    fmt.setBlueBufferSize(8);
    fmt.setDepthBufferSize(24);
    fmt.setStencilBufferSize(8);
    fmt.setAlphaBufferSize(0);
    fmt.setStereo(false);
    fmt.setSamples(vtkOpenGLRenderWindow::GetGlobalMaximumNumberOfMultiSamples());
#ifdef DEBUG_QVTKOPENGL_WIDGET
    fmt.setOption(QSurfaceFormat::DebugContext);
#endif
    return fmt;
}

//-----------------------------------------------------------------------------
QVTKInteractorAdapter* BESTOpenGLWindow::GetInteractorAdapter()
{
    return this->IrenAdapter;
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::setEnableHiDPI(bool enable)
{
    this->EnableHiDPI = enable;
    if (this->RenderWindow)
    {
        if (this->OriginalDPI == 0)
        {
            this->OriginalDPI = this->RenderWindow->GetDPI();
        }
        if (this->EnableHiDPI)
        {
            this->RenderWindow->SetDPI(this->OriginalDPI * this->devicePixelRatio());
        }
        else
        {
            this->RenderWindow->SetDPI(this->OriginalDPI);
        }
    }
}

//-----------------------------------------------------------------------------
bool BESTOpenGLWindow::isValid()
{
    // Check for an existing context()
    if (!this->context())
    {
        return false;
    }

    // Check for QOpenGLWindow::isValid()
    if (!Superclass::isValid())
    {
        return false;
    }

    // Check for a valid framebuffer. paraview bug 0013947.
    // Test if the window has a valid drawable. This is
    // currently only an issue on Mac OS X where rendering
    // to an invalid drawable results in all OpenGL calls to fail
    // with "invalid framebuffer operation".
    this->MakeCurrent();
    QOpenGLFunctions* f = this->context()->functions();
    if (f == nullptr)
    {
        return false;
    }
    GLenum e = f->glCheckFramebufferStatus(GL_DRAW_FRAMEBUFFER);
    if (e != GL_FRAMEBUFFER_COMPLETE)
    {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
bool BESTOpenGLWindow::isCurrent()
{
    // Check for an existing context()
    if (!this->context())
    {
        return false;
    }

    return QOpenGLContext::currentContext() == this->context();
}

//-----------------------------------------------------------------------------
void BESTOpenGLWindow::ChangeCursor(vtkObject*, unsigned long, void*,
                                    void* call_data)
{
    if (!this->RenderWindow)
    {
        return;
    }

    int* cShape = reinterpret_cast<int*> (call_data);
    if (!cShape)
    {
        return;
    }

    switch (*cShape)
    {
    case VTK_CURSOR_CROSSHAIR:
        this->setCursor(QCursor(Qt::CrossCursor));
        break;
    case VTK_CURSOR_SIZEALL:
        this->setCursor(QCursor(Qt::SizeAllCursor));
        break;
    case VTK_CURSOR_SIZENS:
        this->setCursor(QCursor(Qt::SizeVerCursor));
        break;
    case VTK_CURSOR_SIZEWE:
        this->setCursor(QCursor(Qt::SizeHorCursor));
        break;
    case VTK_CURSOR_SIZENE:
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
        break;
    case VTK_CURSOR_SIZENW:
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
        break;
    case VTK_CURSOR_SIZESE:
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
        break;
    case VTK_CURSOR_SIZESW:
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
        break;
    case VTK_CURSOR_HAND:
        this->setCursor(QCursor(Qt::PointingHandCursor));
        break;
    case VTK_CURSOR_ARROW:
    default:
        this->setCursor(QCursor(Qt::ArrowCursor));
        break;
    }
}
