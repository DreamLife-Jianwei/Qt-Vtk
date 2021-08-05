
#ifndef VTKFILTERSPARALLEL_EXPORT_H
#define VTKFILTERSPARALLEL_EXPORT_H

#ifdef VTKFILTERSPARALLEL_STATIC_DEFINE
#  define VTKFILTERSPARALLEL_EXPORT
#  define VTKFILTERSPARALLEL_NO_EXPORT
#else
#  ifndef VTKFILTERSPARALLEL_EXPORT
#    ifdef FiltersParallel_EXPORTS
        /* We are building this library */
#      define VTKFILTERSPARALLEL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSPARALLEL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSPARALLEL_NO_EXPORT
#    define VTKFILTERSPARALLEL_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSPARALLEL_DEPRECATED
#  define VTKFILTERSPARALLEL_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSPARALLEL_DEPRECATED_EXPORT
#  define VTKFILTERSPARALLEL_DEPRECATED_EXPORT VTKFILTERSPARALLEL_EXPORT VTKFILTERSPARALLEL_DEPRECATED
#endif

#ifndef VTKFILTERSPARALLEL_DEPRECATED_NO_EXPORT
#  define VTKFILTERSPARALLEL_DEPRECATED_NO_EXPORT VTKFILTERSPARALLEL_NO_EXPORT VTKFILTERSPARALLEL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSPARALLEL_NO_DEPRECATED
#    define VTKFILTERSPARALLEL_NO_DEPRECATED
#  endif
#endif
/* AutoInit dependencies. */
#include "vtkFiltersCoreModule.h"


/* AutoInit implementations. */
#ifdef vtkFiltersParallel_AUTOINIT_INCLUDE
#include vtkFiltersParallel_AUTOINIT_INCLUDE
#endif
#ifdef vtkFiltersParallel_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkFiltersParallel)
#endif

#endif /* VTKFILTERSPARALLEL_EXPORT_H */
