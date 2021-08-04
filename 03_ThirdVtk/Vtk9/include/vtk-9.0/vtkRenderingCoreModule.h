
#ifndef VTKRENDERINGCORE_EXPORT_H
#define VTKRENDERINGCORE_EXPORT_H

#ifdef VTKRENDERINGCORE_STATIC_DEFINE
#  define VTKRENDERINGCORE_EXPORT
#  define VTKRENDERINGCORE_NO_EXPORT
#else
#  ifndef VTKRENDERINGCORE_EXPORT
#    ifdef RenderingCore_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGCORE_NO_EXPORT
#    define VTKRENDERINGCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGCORE_DEPRECATED
#  define VTKRENDERINGCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGCORE_DEPRECATED_EXPORT
#  define VTKRENDERINGCORE_DEPRECATED_EXPORT VTKRENDERINGCORE_EXPORT VTKRENDERINGCORE_DEPRECATED
#endif

#ifndef VTKRENDERINGCORE_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGCORE_DEPRECATED_NO_EXPORT VTKRENDERINGCORE_NO_EXPORT VTKRENDERINGCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGCORE_NO_DEPRECATED
#    define VTKRENDERINGCORE_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkFiltersCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingCore_AUTOINIT_INCLUDE
#include vtkRenderingCore_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingCore_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingCore)
#endif

#endif /* VTKRENDERINGCORE_EXPORT_H */
