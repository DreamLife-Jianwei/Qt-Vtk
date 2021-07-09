
#ifndef VTKFILTERSGENERIC_EXPORT_H
#define VTKFILTERSGENERIC_EXPORT_H

#ifdef VTKFILTERSGENERIC_STATIC_DEFINE
#  define VTKFILTERSGENERIC_EXPORT
#  define VTKFILTERSGENERIC_NO_EXPORT
#else
#  ifndef VTKFILTERSGENERIC_EXPORT
#    ifdef vtkFiltersGeneric_EXPORTS
        /* We are building this library */
#      define VTKFILTERSGENERIC_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSGENERIC_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSGENERIC_NO_EXPORT
#    define VTKFILTERSGENERIC_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSGENERIC_DEPRECATED
#  define VTKFILTERSGENERIC_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSGENERIC_DEPRECATED_EXPORT VTKFILTERSGENERIC_EXPORT __declspec(deprecated)
#  define VTKFILTERSGENERIC_DEPRECATED_NO_EXPORT VTKFILTERSGENERIC_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSGENERIC_NO_DEPRECATED
#endif



#endif
