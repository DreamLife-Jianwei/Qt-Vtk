
#ifndef VTKRENDERINGOPENGL2_EXPORT_H
#define VTKRENDERINGOPENGL2_EXPORT_H

#ifdef VTKRENDERINGOPENGL2_STATIC_DEFINE
#  define VTKRENDERINGOPENGL2_EXPORT
#  define VTKRENDERINGOPENGL2_NO_EXPORT
#else
#  ifndef VTKRENDERINGOPENGL2_EXPORT
#    ifdef RenderingOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGOPENGL2_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGOPENGL2_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGOPENGL2_NO_EXPORT
#    define VTKRENDERINGOPENGL2_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGOPENGL2_DEPRECATED
#  define VTKRENDERINGOPENGL2_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGOPENGL2_DEPRECATED_EXPORT
#  define VTKRENDERINGOPENGL2_DEPRECATED_EXPORT VTKRENDERINGOPENGL2_EXPORT VTKRENDERINGOPENGL2_DEPRECATED
#endif

#ifndef VTKRENDERINGOPENGL2_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGOPENGL2_DEPRECATED_NO_EXPORT VTKRENDERINGOPENGL2_NO_EXPORT VTKRENDERINGOPENGL2_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGOPENGL2_NO_DEPRECATED
#    define VTKRENDERINGOPENGL2_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingUIModule.h"


/* AutoInit implementations. */
#ifdef vtkRenderingOpenGL2_AUTOINIT_INCLUDE
#include vtkRenderingOpenGL2_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingOpenGL2_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingOpenGL2)
#endif

#endif /* VTKRENDERINGOPENGL2_EXPORT_H */
