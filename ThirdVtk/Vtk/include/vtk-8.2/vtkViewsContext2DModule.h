
#ifndef VTKVIEWSCONTEXT2D_EXPORT_H
#define VTKVIEWSCONTEXT2D_EXPORT_H

#ifdef VTKVIEWSCONTEXT2D_STATIC_DEFINE
#  define VTKVIEWSCONTEXT2D_EXPORT
#  define VTKVIEWSCONTEXT2D_NO_EXPORT
#else
#  ifndef VTKVIEWSCONTEXT2D_EXPORT
#    ifdef vtkViewsContext2D_EXPORTS
        /* We are building this library */
#      define VTKVIEWSCONTEXT2D_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKVIEWSCONTEXT2D_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKVIEWSCONTEXT2D_NO_EXPORT
#    define VTKVIEWSCONTEXT2D_NO_EXPORT 
#  endif
#endif

#ifndef VTKVIEWSCONTEXT2D_DEPRECATED
#  define VTKVIEWSCONTEXT2D_DEPRECATED __declspec(deprecated)
#  define VTKVIEWSCONTEXT2D_DEPRECATED_EXPORT VTKVIEWSCONTEXT2D_EXPORT __declspec(deprecated)
#  define VTKVIEWSCONTEXT2D_DEPRECATED_NO_EXPORT VTKVIEWSCONTEXT2D_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKVIEWSCONTEXT2D_NO_DEPRECATED
#endif

/* AutoInit dependencies.  */
#include "vtkRenderingCoreModule.h"
#include "vtkViewsCoreModule.h"

#endif
