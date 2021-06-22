
#ifndef VTKFILTERSPOINTS_EXPORT_H
#define VTKFILTERSPOINTS_EXPORT_H

#ifdef VTKFILTERSPOINTS_STATIC_DEFINE
#  define VTKFILTERSPOINTS_EXPORT
#  define VTKFILTERSPOINTS_NO_EXPORT
#else
#  ifndef VTKFILTERSPOINTS_EXPORT
#    ifdef vtkFiltersPoints_EXPORTS
        /* We are building this library */
#      define VTKFILTERSPOINTS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSPOINTS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSPOINTS_NO_EXPORT
#    define VTKFILTERSPOINTS_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSPOINTS_DEPRECATED
#  define VTKFILTERSPOINTS_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSPOINTS_DEPRECATED_EXPORT VTKFILTERSPOINTS_EXPORT __declspec(deprecated)
#  define VTKFILTERSPOINTS_DEPRECATED_NO_EXPORT VTKFILTERSPOINTS_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSPOINTS_NO_DEPRECATED
#endif



#endif
