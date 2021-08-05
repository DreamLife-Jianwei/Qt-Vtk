
#ifndef VTKCHARTSCORE_EXPORT_H
#define VTKCHARTSCORE_EXPORT_H

#ifdef VTKCHARTSCORE_STATIC_DEFINE
#  define VTKCHARTSCORE_EXPORT
#  define VTKCHARTSCORE_NO_EXPORT
#else
#  ifndef VTKCHARTSCORE_EXPORT
#    ifdef ChartsCore_EXPORTS
        /* We are building this library */
#      define VTKCHARTSCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCHARTSCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCHARTSCORE_NO_EXPORT
#    define VTKCHARTSCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKCHARTSCORE_DEPRECATED
#  define VTKCHARTSCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKCHARTSCORE_DEPRECATED_EXPORT
#  define VTKCHARTSCORE_DEPRECATED_EXPORT VTKCHARTSCORE_EXPORT VTKCHARTSCORE_DEPRECATED
#endif

#ifndef VTKCHARTSCORE_DEPRECATED_NO_EXPORT
#  define VTKCHARTSCORE_DEPRECATED_NO_EXPORT VTKCHARTSCORE_NO_EXPORT VTKCHARTSCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKCHARTSCORE_NO_DEPRECATED
#    define VTKCHARTSCORE_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkRenderingContext2DModule.h"
#include "vtkRenderingCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkChartsCore_AUTOINIT_INCLUDE
#include vtkChartsCore_AUTOINIT_INCLUDE
#endif
#ifdef vtkChartsCore_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkChartsCore)
#endif

#endif /* VTKCHARTSCORE_EXPORT_H */
