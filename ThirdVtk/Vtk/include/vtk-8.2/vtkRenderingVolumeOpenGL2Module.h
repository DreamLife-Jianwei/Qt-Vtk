
#ifndef VTKRENDERINGVOLUMEOPENGL2_EXPORT_H
#define VTKRENDERINGVOLUMEOPENGL2_EXPORT_H

#ifdef VTKRENDERINGVOLUMEOPENGL2_STATIC_DEFINE
#  define VTKRENDERINGVOLUMEOPENGL2_EXPORT
#  define VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT
#else
#  ifndef VTKRENDERINGVOLUMEOPENGL2_EXPORT
#    ifdef vtkRenderingVolumeOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGVOLUMEOPENGL2_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGVOLUMEOPENGL2_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT
#    define VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGVOLUMEOPENGL2_DEPRECATED
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_EXPORT VTKRENDERINGVOLUMEOPENGL2_EXPORT __declspec(deprecated)
#  define VTKRENDERINGVOLUMEOPENGL2_DEPRECATED_NO_EXPORT VTKRENDERINGVOLUMEOPENGL2_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGVOLUMEOPENGL2_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingOpenGL2Module.h"
#include "vtkRenderingVolumeModule.h"
#include "vtkRenderingVolumeModule.h"

/* AutoInit implementations.  */
#if defined(vtkRenderingVolumeOpenGL2_INCLUDE)
# include vtkRenderingVolumeOpenGL2_INCLUDE
#endif
#if defined(vtkRenderingVolumeOpenGL2_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkRenderingVolumeOpenGL2)
#endif

#endif
