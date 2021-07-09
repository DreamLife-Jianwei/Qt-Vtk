
#ifndef VTKRENDERINGIMAGE_EXPORT_H
#define VTKRENDERINGIMAGE_EXPORT_H

#ifdef VTKRENDERINGIMAGE_STATIC_DEFINE
#  define VTKRENDERINGIMAGE_EXPORT
#  define VTKRENDERINGIMAGE_NO_EXPORT
#else
#  ifndef VTKRENDERINGIMAGE_EXPORT
#    ifdef vtkRenderingImage_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGIMAGE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGIMAGE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGIMAGE_NO_EXPORT
#    define VTKRENDERINGIMAGE_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGIMAGE_DEPRECATED
#  define VTKRENDERINGIMAGE_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGIMAGE_DEPRECATED_EXPORT VTKRENDERINGIMAGE_EXPORT __declspec(deprecated)
#  define VTKRENDERINGIMAGE_DEPRECATED_NO_EXPORT VTKRENDERINGIMAGE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGIMAGE_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"

#endif
