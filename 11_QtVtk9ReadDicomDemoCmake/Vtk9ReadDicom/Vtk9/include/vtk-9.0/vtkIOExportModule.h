
#ifndef VTKIOEXPORT_EXPORT_H
#define VTKIOEXPORT_EXPORT_H

#ifdef VTKIOEXPORT_STATIC_DEFINE
#  define VTKIOEXPORT_EXPORT
#  define VTKIOEXPORT_NO_EXPORT
#else
#  ifndef VTKIOEXPORT_EXPORT
#    ifdef IOExport_EXPORTS
        /* We are building this library */
#      define VTKIOEXPORT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOEXPORT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOEXPORT_NO_EXPORT
#    define VTKIOEXPORT_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOEXPORT_DEPRECATED
#  define VTKIOEXPORT_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOEXPORT_DEPRECATED_EXPORT
#  define VTKIOEXPORT_DEPRECATED_EXPORT VTKIOEXPORT_EXPORT VTKIOEXPORT_DEPRECATED
#endif

#ifndef VTKIOEXPORT_DEPRECATED_NO_EXPORT
#  define VTKIOEXPORT_DEPRECATED_NO_EXPORT VTKIOEXPORT_NO_EXPORT VTKIOEXPORT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOEXPORT_NO_DEPRECATED
#    define VTKIOEXPORT_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkIOImageModule.h"
#include "vtkRenderingContext2DModule.h"
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingFreeTypeModule.h"


/* AutoInit implementations. */
#ifdef vtkIOExport_AUTOINIT_INCLUDE
#include vtkIOExport_AUTOINIT_INCLUDE
#endif
#ifdef vtkIOExport_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIOExport)
#endif

#endif /* VTKIOEXPORT_EXPORT_H */
