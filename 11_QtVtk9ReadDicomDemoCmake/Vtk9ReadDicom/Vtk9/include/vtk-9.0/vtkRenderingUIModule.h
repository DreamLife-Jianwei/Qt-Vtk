
#ifndef VTKRENDERINGUI_EXPORT_H
#define VTKRENDERINGUI_EXPORT_H

#ifdef VTKRENDERINGUI_STATIC_DEFINE
#  define VTKRENDERINGUI_EXPORT
#  define VTKRENDERINGUI_NO_EXPORT
#else
#  ifndef VTKRENDERINGUI_EXPORT
#    ifdef RenderingUI_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGUI_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGUI_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGUI_NO_EXPORT
#    define VTKRENDERINGUI_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGUI_DEPRECATED
#  define VTKRENDERINGUI_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGUI_DEPRECATED_EXPORT
#  define VTKRENDERINGUI_DEPRECATED_EXPORT VTKRENDERINGUI_EXPORT VTKRENDERINGUI_DEPRECATED
#endif

#ifndef VTKRENDERINGUI_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGUI_DEPRECATED_NO_EXPORT VTKRENDERINGUI_NO_EXPORT VTKRENDERINGUI_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGUI_NO_DEPRECATED
#    define VTKRENDERINGUI_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingUI_AUTOINIT_INCLUDE
#include vtkRenderingUI_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingUI_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingUI)
#endif

#endif /* VTKRENDERINGUI_EXPORT_H */
