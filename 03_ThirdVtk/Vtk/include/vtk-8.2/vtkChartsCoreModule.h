
#ifndef VTKCHARTSCORE_EXPORT_H
#define VTKCHARTSCORE_EXPORT_H

#ifdef VTKCHARTSCORE_STATIC_DEFINE
#  define VTKCHARTSCORE_EXPORT
#  define VTKCHARTSCORE_NO_EXPORT
#else
#  ifndef VTKCHARTSCORE_EXPORT
#    ifdef vtkChartsCore_EXPORTS
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
#  define VTKCHARTSCORE_DEPRECATED_EXPORT VTKCHARTSCORE_EXPORT __declspec(deprecated)
#  define VTKCHARTSCORE_DEPRECATED_NO_EXPORT VTKCHARTSCORE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKCHARTSCORE_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingContext2DModule.h"
#include "vtkRenderingCoreModule.h"

/* AutoInit implementations.  */
#if defined(vtkChartsCore_INCLUDE)
# include vtkChartsCore_INCLUDE
#endif
#if defined(vtkChartsCore_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkChartsCore)
#endif

#endif
