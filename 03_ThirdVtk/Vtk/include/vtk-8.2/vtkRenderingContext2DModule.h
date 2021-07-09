
#ifndef VTKRENDERINGCONTEXT2D_EXPORT_H
#define VTKRENDERINGCONTEXT2D_EXPORT_H

#ifdef VTKRENDERINGCONTEXT2D_STATIC_DEFINE
#  define VTKRENDERINGCONTEXT2D_EXPORT
#  define VTKRENDERINGCONTEXT2D_NO_EXPORT
#else
#  ifndef VTKRENDERINGCONTEXT2D_EXPORT
#    ifdef vtkRenderingContext2D_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGCONTEXT2D_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGCONTEXT2D_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGCONTEXT2D_NO_EXPORT
#    define VTKRENDERINGCONTEXT2D_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGCONTEXT2D_DEPRECATED
#  define VTKRENDERINGCONTEXT2D_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGCONTEXT2D_DEPRECATED_EXPORT VTKRENDERINGCONTEXT2D_EXPORT __declspec(deprecated)
#  define VTKRENDERINGCONTEXT2D_DEPRECATED_NO_EXPORT VTKRENDERINGCONTEXT2D_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGCONTEXT2D_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"

/* AutoInit implementations.  */
#if defined(vtkRenderingContext2D_INCLUDE)
# include vtkRenderingContext2D_INCLUDE
#endif
#if defined(vtkRenderingContext2D_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkRenderingContext2D)
#endif

#endif
