
#ifndef VTKIOENSIGHT_EXPORT_H
#define VTKIOENSIGHT_EXPORT_H

#ifdef VTKIOENSIGHT_STATIC_DEFINE
#  define VTKIOENSIGHT_EXPORT
#  define VTKIOENSIGHT_NO_EXPORT
#else
#  ifndef VTKIOENSIGHT_EXPORT
#    ifdef vtkIOEnSight_EXPORTS
        /* We are building this library */
#      define VTKIOENSIGHT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOENSIGHT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOENSIGHT_NO_EXPORT
#    define VTKIOENSIGHT_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOENSIGHT_DEPRECATED
#  define VTKIOENSIGHT_DEPRECATED __declspec(deprecated)
#  define VTKIOENSIGHT_DEPRECATED_EXPORT VTKIOENSIGHT_EXPORT __declspec(deprecated)
#  define VTKIOENSIGHT_DEPRECATED_NO_EXPORT VTKIOENSIGHT_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOENSIGHT_NO_DEPRECATED
#endif



#endif
