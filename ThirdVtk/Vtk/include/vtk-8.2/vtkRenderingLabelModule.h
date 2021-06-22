
#ifndef VTKRENDERINGLABEL_EXPORT_H
#define VTKRENDERINGLABEL_EXPORT_H

#ifdef VTKRENDERINGLABEL_STATIC_DEFINE
#  define VTKRENDERINGLABEL_EXPORT
#  define VTKRENDERINGLABEL_NO_EXPORT
#else
#  ifndef VTKRENDERINGLABEL_EXPORT
#    ifdef vtkRenderingLabel_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGLABEL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGLABEL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGLABEL_NO_EXPORT
#    define VTKRENDERINGLABEL_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGLABEL_DEPRECATED
#  define VTKRENDERINGLABEL_DEPRECATED __declspec(deprecated)
#  define VTKRENDERINGLABEL_DEPRECATED_EXPORT VTKRENDERINGLABEL_EXPORT __declspec(deprecated)
#  define VTKRENDERINGLABEL_DEPRECATED_NO_EXPORT VTKRENDERINGLABEL_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKRENDERINGLABEL_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingFreeTypeModule.h"

#endif
