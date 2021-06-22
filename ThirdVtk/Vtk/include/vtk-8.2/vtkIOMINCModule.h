
#ifndef VTKIOMINC_EXPORT_H
#define VTKIOMINC_EXPORT_H

#ifdef VTKIOMINC_STATIC_DEFINE
#  define VTKIOMINC_EXPORT
#  define VTKIOMINC_NO_EXPORT
#else
#  ifndef VTKIOMINC_EXPORT
#    ifdef vtkIOMINC_EXPORTS
        /* We are building this library */
#      define VTKIOMINC_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOMINC_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOMINC_NO_EXPORT
#    define VTKIOMINC_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOMINC_DEPRECATED
#  define VTKIOMINC_DEPRECATED __declspec(deprecated)
#  define VTKIOMINC_DEPRECATED_EXPORT VTKIOMINC_EXPORT __declspec(deprecated)
#  define VTKIOMINC_DEPRECATED_NO_EXPORT VTKIOMINC_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOMINC_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkIOImageModule.h"

#endif
