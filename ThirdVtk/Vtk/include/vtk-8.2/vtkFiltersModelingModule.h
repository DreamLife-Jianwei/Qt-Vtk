
#ifndef VTKFILTERSMODELING_EXPORT_H
#define VTKFILTERSMODELING_EXPORT_H

#ifdef VTKFILTERSMODELING_STATIC_DEFINE
#  define VTKFILTERSMODELING_EXPORT
#  define VTKFILTERSMODELING_NO_EXPORT
#else
#  ifndef VTKFILTERSMODELING_EXPORT
#    ifdef vtkFiltersModeling_EXPORTS
        /* We are building this library */
#      define VTKFILTERSMODELING_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSMODELING_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSMODELING_NO_EXPORT
#    define VTKFILTERSMODELING_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSMODELING_DEPRECATED
#  define VTKFILTERSMODELING_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSMODELING_DEPRECATED_EXPORT VTKFILTERSMODELING_EXPORT __declspec(deprecated)
#  define VTKFILTERSMODELING_DEPRECATED_NO_EXPORT VTKFILTERSMODELING_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSMODELING_NO_DEPRECATED
#endif



#endif
