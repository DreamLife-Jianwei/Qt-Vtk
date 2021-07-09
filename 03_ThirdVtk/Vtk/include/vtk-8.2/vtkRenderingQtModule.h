
#ifndef VTKRENDERINGQT_EXPORT_H
#define VTKRENDERINGQT_EXPORT_H

#ifdef VTKRENDERINGQT_STATIC_DEFINE
#  define VTKRENDERINGQT_EXPORT
#  define VTKRENDERINGQT_NO_EXPORT
#else
#  ifndef VTKRENDERINGQT_EXPORT
#    ifdef vtkRenderingQt_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGQT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGQT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGQT_NO_EXPORT
#    define VTKRENDERINGQT_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGQT_DEPRECATED
#  define VTKRENDERINGQT_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGQT_DEPRECATED_EXPORT VTKRENDERINGQT_EXPORT __declspec(deprecated)
#  define VTKRENDERINGQT_DEPRECATED_NO_EXPORT VTKRENDERINGQT_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGQT_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingLabelModule.h"

#endif
