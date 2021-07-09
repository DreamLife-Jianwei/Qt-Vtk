
#ifndef VTKRENDERINGVOLUME_EXPORT_H
#define VTKRENDERINGVOLUME_EXPORT_H

#ifdef VTKRENDERINGVOLUME_STATIC_DEFINE
#  define VTKRENDERINGVOLUME_EXPORT
#  define VTKRENDERINGVOLUME_NO_EXPORT
#else
#  ifndef VTKRENDERINGVOLUME_EXPORT
#    ifdef vtkRenderingVolume_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGVOLUME_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGVOLUME_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGVOLUME_NO_EXPORT
#    define VTKRENDERINGVOLUME_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGVOLUME_DEPRECATED
#  define VTKRENDERINGVOLUME_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGVOLUME_DEPRECATED_EXPORT VTKRENDERINGVOLUME_EXPORT __declspec(deprecated)
#  define VTKRENDERINGVOLUME_DEPRECATED_NO_EXPORT VTKRENDERINGVOLUME_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGVOLUME_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"

/* AutoInit implementations.  */
#if defined(vtkRenderingVolume_INCLUDE)
# include vtkRenderingVolume_INCLUDE
#endif
#if defined(vtkRenderingVolume_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkRenderingVolume)
#endif

#endif
