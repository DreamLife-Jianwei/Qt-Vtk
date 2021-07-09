
#ifndef VTKRENDERINGOPENGL2_EXPORT_H
#define VTKRENDERINGOPENGL2_EXPORT_H

#ifdef VTKRENDERINGOPENGL2_STATIC_DEFINE
#  define VTKRENDERINGOPENGL2_EXPORT
#  define VTKRENDERINGOPENGL2_NO_EXPORT
#else
#  ifndef VTKRENDERINGOPENGL2_EXPORT
#    ifdef vtkRenderingOpenGL2_EXPORTS
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
#  define VTKRENDERINGOPENGL2_DEPRECATED_EXPORT VTKRENDERINGOPENGL2_EXPORT __declspec(deprecated)
#  define VTKRENDERINGOPENGL2_DEPRECATED_NO_EXPORT VTKRENDERINGOPENGL2_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGOPENGL2_NO_DEPRECATED
#endif

#include "vtkRenderingOpenGLConfigure.h"

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingCoreModule.h"

/* AutoInit implementations.  */
#if defined(vtkRenderingOpenGL2_INCLUDE)
# include vtkRenderingOpenGL2_INCLUDE
#endif
#if defined(vtkRenderingOpenGL2_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkRenderingOpenGL2)
#endif

#endif
