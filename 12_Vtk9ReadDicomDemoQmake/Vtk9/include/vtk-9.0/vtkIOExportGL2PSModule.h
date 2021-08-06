
#ifndef VTKIOEXPORTGL2PS_EXPORT_H
#define VTKIOEXPORTGL2PS_EXPORT_H

#ifdef VTKIOEXPORTGL2PS_STATIC_DEFINE
#  define VTKIOEXPORTGL2PS_EXPORT
#  define VTKIOEXPORTGL2PS_NO_EXPORT
#else
#  ifndef VTKIOEXPORTGL2PS_EXPORT
#    ifdef IOExportGL2PS_EXPORTS
        /* We are building this library */
#      define VTKIOEXPORTGL2PS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOEXPORTGL2PS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOEXPORTGL2PS_NO_EXPORT
#    define VTKIOEXPORTGL2PS_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOEXPORTGL2PS_DEPRECATED
#  define VTKIOEXPORTGL2PS_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOEXPORTGL2PS_DEPRECATED_EXPORT
#  define VTKIOEXPORTGL2PS_DEPRECATED_EXPORT VTKIOEXPORTGL2PS_EXPORT VTKIOEXPORTGL2PS_DEPRECATED
#endif

#ifndef VTKIOEXPORTGL2PS_DEPRECATED_NO_EXPORT
#  define VTKIOEXPORTGL2PS_DEPRECATED_NO_EXPORT VTKIOEXPORTGL2PS_NO_EXPORT VTKIOEXPORTGL2PS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOEXPORTGL2PS_NO_DEPRECATED
#    define VTKIOEXPORTGL2PS_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkIOExportModule.h"
#include "vtkRenderingGL2PSOpenGL2Module.h"


/* AutoInit implementations. */
#ifdef vtkIOExportGL2PS_AUTOINIT_INCLUDE
#include vtkIOExportGL2PS_AUTOINIT_INCLUDE
#endif
#ifdef vtkIOExportGL2PS_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIOExportGL2PS)
#endif

#endif /* VTKIOEXPORTGL2PS_EXPORT_H */
