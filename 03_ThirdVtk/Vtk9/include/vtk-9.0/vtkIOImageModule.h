
#ifndef VTKIOIMAGE_EXPORT_H
#define VTKIOIMAGE_EXPORT_H

#ifdef VTKIOIMAGE_STATIC_DEFINE
#  define VTKIOIMAGE_EXPORT
#  define VTKIOIMAGE_NO_EXPORT
#else
#  ifndef VTKIOIMAGE_EXPORT
#    ifdef IOImage_EXPORTS
        /* We are building this library */
#      define VTKIOIMAGE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOIMAGE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOIMAGE_NO_EXPORT
#    define VTKIOIMAGE_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOIMAGE_DEPRECATED
#  define VTKIOIMAGE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOIMAGE_DEPRECATED_EXPORT
#  define VTKIOIMAGE_DEPRECATED_EXPORT VTKIOIMAGE_EXPORT VTKIOIMAGE_DEPRECATED
#endif

#ifndef VTKIOIMAGE_DEPRECATED_NO_EXPORT
#  define VTKIOIMAGE_DEPRECATED_NO_EXPORT VTKIOIMAGE_NO_EXPORT VTKIOIMAGE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOIMAGE_NO_DEPRECATED
#    define VTKIOIMAGE_NO_DEPRECATED
#  endif
#endif

/* AutoInit implementations. */
#ifdef vtkIOImage_AUTOINIT_INCLUDE
#include vtkIOImage_AUTOINIT_INCLUDE
#endif
#ifdef vtkIOImage_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIOImage)
#endif

#endif /* VTKIOIMAGE_EXPORT_H */
