
#ifndef VTKFILTERSCORE_EXPORT_H
#define VTKFILTERSCORE_EXPORT_H

#ifdef VTKFILTERSCORE_STATIC_DEFINE
#  define VTKFILTERSCORE_EXPORT
#  define VTKFILTERSCORE_NO_EXPORT
#else
#  ifndef VTKFILTERSCORE_EXPORT
#    ifdef FiltersCore_EXPORTS
        /* We are building this library */
#      define VTKFILTERSCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSCORE_NO_EXPORT
#    define VTKFILTERSCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSCORE_DEPRECATED
#  define VTKFILTERSCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSCORE_DEPRECATED_EXPORT
#  define VTKFILTERSCORE_DEPRECATED_EXPORT VTKFILTERSCORE_EXPORT VTKFILTERSCORE_DEPRECATED
#endif

#ifndef VTKFILTERSCORE_DEPRECATED_NO_EXPORT
#  define VTKFILTERSCORE_DEPRECATED_NO_EXPORT VTKFILTERSCORE_NO_EXPORT VTKFILTERSCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSCORE_NO_DEPRECATED
#    define VTKFILTERSCORE_NO_DEPRECATED
#  endif
#endif

/* AutoInit implementations. */
#ifdef vtkFiltersCore_AUTOINIT_INCLUDE
#include vtkFiltersCore_AUTOINIT_INCLUDE
#endif
#ifdef vtkFiltersCore_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkFiltersCore)
#endif

#endif /* VTKFILTERSCORE_EXPORT_H */
