
#ifndef VTKFILTERSGENERAL_EXPORT_H
#define VTKFILTERSGENERAL_EXPORT_H

#ifdef VTKFILTERSGENERAL_STATIC_DEFINE
#  define VTKFILTERSGENERAL_EXPORT
#  define VTKFILTERSGENERAL_NO_EXPORT
#else
#  ifndef VTKFILTERSGENERAL_EXPORT
#    ifdef vtkFiltersGeneral_EXPORTS
        /* We are building this library */
#      define VTKFILTERSGENERAL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSGENERAL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSGENERAL_NO_EXPORT
#    define VTKFILTERSGENERAL_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSGENERAL_DEPRECATED
#  define VTKFILTERSGENERAL_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSGENERAL_DEPRECATED_EXPORT VTKFILTERSGENERAL_EXPORT __declspec(deprecated)
#  define VTKFILTERSGENERAL_DEPRECATED_NO_EXPORT VTKFILTERSGENERAL_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSGENERAL_NO_DEPRECATED
#endif



#endif
