
#ifndef VTKFILTERSFLOWPATHS_EXPORT_H
#define VTKFILTERSFLOWPATHS_EXPORT_H

#ifdef VTKFILTERSFLOWPATHS_STATIC_DEFINE
#  define VTKFILTERSFLOWPATHS_EXPORT
#  define VTKFILTERSFLOWPATHS_NO_EXPORT
#else
#  ifndef VTKFILTERSFLOWPATHS_EXPORT
#    ifdef vtkFiltersFlowPaths_EXPORTS
        /* We are building this library */
#      define VTKFILTERSFLOWPATHS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSFLOWPATHS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSFLOWPATHS_NO_EXPORT
#    define VTKFILTERSFLOWPATHS_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSFLOWPATHS_DEPRECATED
#  define VTKFILTERSFLOWPATHS_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSFLOWPATHS_DEPRECATED_EXPORT VTKFILTERSFLOWPATHS_EXPORT __declspec(deprecated)
#  define VTKFILTERSFLOWPATHS_DEPRECATED_NO_EXPORT VTKFILTERSFLOWPATHS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSFLOWPATHS_NO_DEPRECATED
#endif

/* AutoInit implementations.  */
#if defined(vtkFiltersFlowPaths_INCLUDE)
# include vtkFiltersFlowPaths_INCLUDE
#endif
#if defined(vtkFiltersFlowPaths_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkFiltersFlowPaths)
#endif

#endif
