
#ifndef VTKINTERACTIONWIDGETS_EXPORT_H
#define VTKINTERACTIONWIDGETS_EXPORT_H

#ifdef VTKINTERACTIONWIDGETS_STATIC_DEFINE
#  define VTKINTERACTIONWIDGETS_EXPORT
#  define VTKINTERACTIONWIDGETS_NO_EXPORT
#else
#  ifndef VTKINTERACTIONWIDGETS_EXPORT
#    ifdef vtkInteractionWidgets_EXPORTS
        /* We are building this library */
#      define VTKINTERACTIONWIDGETS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKINTERACTIONWIDGETS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKINTERACTIONWIDGETS_NO_EXPORT
#    define VTKINTERACTIONWIDGETS_NO_EXPORT 
#  endif
#endif

#ifndef VTKINTERACTIONWIDGETS_DEPRECATED
#  define VTKINTERACTIONWIDGETS_DEPRECATED __declspec(deprecated)
#  define VTKINTERACTIONWIDGETS_DEPRECATED_EXPORT VTKINTERACTIONWIDGETS_EXPORT __declspec(deprecated)
#  define VTKINTERACTIONWIDGETS_DEPRECATED_NO_EXPORT VTKINTERACTIONWIDGETS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKINTERACTIONWIDGETS_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"

#endif
