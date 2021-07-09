
#ifndef VTKRENDERINGLOD_EXPORT_H
#define VTKRENDERINGLOD_EXPORT_H

#ifdef VTKRENDERINGLOD_STATIC_DEFINE
#  define VTKRENDERINGLOD_EXPORT
#  define VTKRENDERINGLOD_NO_EXPORT
#else
#  ifndef VTKRENDERINGLOD_EXPORT
#    ifdef vtkRenderingLOD_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGLOD_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGLOD_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGLOD_NO_EXPORT
#    define VTKRENDERINGLOD_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGLOD_DEPRECATED
#  define VTKRENDERINGLOD_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGLOD_DEPRECATED_EXPORT VTKRENDERINGLOD_EXPORT __declspec(deprecated)
#  define VTKRENDERINGLOD_DEPRECATED_NO_EXPORT VTKRENDERINGLOD_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGLOD_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"

#endif
