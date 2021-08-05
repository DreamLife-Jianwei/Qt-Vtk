
#ifndef VTKIOEXPORTPDF_EXPORT_H
#define VTKIOEXPORTPDF_EXPORT_H

#ifdef VTKIOEXPORTPDF_STATIC_DEFINE
#  define VTKIOEXPORTPDF_EXPORT
#  define VTKIOEXPORTPDF_NO_EXPORT
#else
#  ifndef VTKIOEXPORTPDF_EXPORT
#    ifdef IOExportPDF_EXPORTS
        /* We are building this library */
#      define VTKIOEXPORTPDF_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOEXPORTPDF_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOEXPORTPDF_NO_EXPORT
#    define VTKIOEXPORTPDF_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOEXPORTPDF_DEPRECATED
#  define VTKIOEXPORTPDF_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOEXPORTPDF_DEPRECATED_EXPORT
#  define VTKIOEXPORTPDF_DEPRECATED_EXPORT VTKIOEXPORTPDF_EXPORT VTKIOEXPORTPDF_DEPRECATED
#endif

#ifndef VTKIOEXPORTPDF_DEPRECATED_NO_EXPORT
#  define VTKIOEXPORTPDF_DEPRECATED_NO_EXPORT VTKIOEXPORTPDF_NO_EXPORT VTKIOEXPORTPDF_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOEXPORTPDF_NO_DEPRECATED
#    define VTKIOEXPORTPDF_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkIOExportModule.h"
#include "vtkRenderingContext2DModule.h"


/* AutoInit implementations. */
#ifdef vtkIOExportPDF_AUTOINIT_INCLUDE
#include vtkIOExportPDF_AUTOINIT_INCLUDE
#endif
#ifdef vtkIOExportPDF_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkIOExportPDF)
#endif

#endif /* VTKIOEXPORTPDF_EXPORT_H */
