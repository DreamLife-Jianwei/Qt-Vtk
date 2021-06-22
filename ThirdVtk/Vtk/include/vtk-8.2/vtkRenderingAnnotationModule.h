
#ifndef VTKRENDERINGANNOTATION_EXPORT_H
#define VTKRENDERINGANNOTATION_EXPORT_H

#ifdef VTKRENDERINGANNOTATION_STATIC_DEFINE
#  define VTKRENDERINGANNOTATION_EXPORT
#  define VTKRENDERINGANNOTATION_NO_EXPORT
#else
#  ifndef VTKRENDERINGANNOTATION_EXPORT
#    ifdef vtkRenderingAnnotation_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGANNOTATION_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGANNOTATION_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGANNOTATION_NO_EXPORT
#    define VTKRENDERINGANNOTATION_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGANNOTATION_DEPRECATED
#  define VTKRENDERINGANNOTATION_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGANNOTATION_DEPRECATED_EXPORT VTKRENDERINGANNOTATION_EXPORT __declspec(deprecated)
#  define VTKRENDERINGANNOTATION_DEPRECATED_NO_EXPORT VTKRENDERINGANNOTATION_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGANNOTATION_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"

#endif
