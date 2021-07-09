
#ifndef VTKFILTERSAMR_EXPORT_H
#define VTKFILTERSAMR_EXPORT_H

#ifdef VTKFILTERSAMR_STATIC_DEFINE
#  define VTKFILTERSAMR_EXPORT
#  define VTKFILTERSAMR_NO_EXPORT
#else
#  ifndef VTKFILTERSAMR_EXPORT
#    ifdef vtkFiltersAMR_EXPORTS
        /* We are building this library */
#      define VTKFILTERSAMR_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSAMR_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSAMR_NO_EXPORT
#    define VTKFILTERSAMR_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSAMR_DEPRECATED
#  define VTKFILTERSAMR_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSAMR_DEPRECATED_EXPORT VTKFILTERSAMR_EXPORT __declspec(deprecated)
#  define VTKFILTERSAMR_DEPRECATED_NO_EXPORT VTKFILTERSAMR_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSAMR_NO_DEPRECATED
#endif



#endif
