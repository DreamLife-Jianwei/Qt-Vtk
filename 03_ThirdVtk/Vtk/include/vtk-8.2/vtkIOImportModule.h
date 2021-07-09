
#ifndef VTKIOIMPORT_EXPORT_H
#define VTKIOIMPORT_EXPORT_H

#ifdef VTKIOIMPORT_STATIC_DEFINE
#  define VTKIOIMPORT_EXPORT
#  define VTKIOIMPORT_NO_EXPORT
#else
#  ifndef VTKIOIMPORT_EXPORT
#    ifdef vtkIOImport_EXPORTS
        /* We are building this library */
#      define VTKIOIMPORT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOIMPORT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOIMPORT_NO_EXPORT
#    define VTKIOIMPORT_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOIMPORT_DEPRECATED
#  define VTKIOIMPORT_DEPRECATED __declspec(deprecated)
#  define VTKIOIMPORT_DEPRECATED_EXPORT VTKIOIMPORT_EXPORT __declspec(deprecated)
#  define VTKIOIMPORT_DEPRECATED_NO_EXPORT VTKIOIMPORT_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOIMPORT_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"

#endif
