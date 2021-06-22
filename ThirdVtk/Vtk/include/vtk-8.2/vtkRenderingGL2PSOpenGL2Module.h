
#ifndef VTKRENDERINGGL2PSOPENGL2_EXPORT_H
#define VTKRENDERINGGL2PSOPENGL2_EXPORT_H

#ifdef VTKRENDERINGGL2PSOPENGL2_STATIC_DEFINE
#  define VTKRENDERINGGL2PSOPENGL2_EXPORT
#  define VTKRENDERINGGL2PSOPENGL2_NO_EXPORT
#else
#  ifndef VTKRENDERINGGL2PSOPENGL2_EXPORT
#    ifdef vtkRenderingGL2PSOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGGL2PSOPENGL2_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGGL2PSOPENGL2_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGGL2PSOPENGL2_NO_EXPORT
#    define VTKRENDERINGGL2PSOPENGL2_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGGL2PSOPENGL2_DEPRECATED
#  define VTKRENDERINGGL2PSOPENGL2_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGGL2PSOPENGL2_DEPRECATED_EXPORT VTKRENDERINGGL2PSOPENGL2_EXPORT __declspec(deprecated)
#  define VTKRENDERINGGL2PSOPENGL2_DEPRECATED_NO_EXPORT VTKRENDERINGGL2PSOPENGL2_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGGL2PSOPENGL2_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingOpenGL2Module.h"
#include "vtkRenderingOpenGL2Module.h"

/* AutoInit implementations.  */
#if defined(vtkRenderingGL2PSOpenGL2_INCLUDE)
# include vtkRenderingGL2PSOpenGL2_INCLUDE
#endif
#if defined(vtkRenderingGL2PSOpenGL2_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkRenderingGL2PSOpenGL2)
#endif

#endif
