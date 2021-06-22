
#ifndef VTKRENDERINGFREETYPE_EXPORT_H
#define VTKRENDERINGFREETYPE_EXPORT_H

#ifdef VTKRENDERINGFREETYPE_STATIC_DEFINE
#  define VTKRENDERINGFREETYPE_EXPORT
#  define VTKRENDERINGFREETYPE_NO_EXPORT
#else
#  ifndef VTKRENDERINGFREETYPE_EXPORT
#    ifdef vtkRenderingFreeType_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGFREETYPE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGFREETYPE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGFREETYPE_NO_EXPORT
#    define VTKRENDERINGFREETYPE_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGFREETYPE_DEPRECATED
#  define VTKRENDERINGFREETYPE_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGFREETYPE_DEPRECATED_EXPORT VTKRENDERINGFREETYPE_EXPORT __declspec(deprecated)
#  define VTKRENDERINGFREETYPE_DEPRECATED_NO_EXPORT VTKRENDERINGFREETYPE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGFREETYPE_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingCoreModule.h"

/* AutoInit implementations.  */
#if defined(vtkRenderingFreeType_INCLUDE)
# include vtkRenderingFreeType_INCLUDE
#endif
#if defined(vtkRenderingFreeType_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkRenderingFreeType)
#endif

#endif
