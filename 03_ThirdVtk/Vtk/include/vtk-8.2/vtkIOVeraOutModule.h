
#ifndef VTKIOVERAOUT_EXPORT_H
#define VTKIOVERAOUT_EXPORT_H

#ifdef VTKIOVERAOUT_STATIC_DEFINE
#  define VTKIOVERAOUT_EXPORT
#  define VTKIOVERAOUT_NO_EXPORT
#else
#  ifndef VTKIOVERAOUT_EXPORT
#    ifdef vtkIOVeraOut_EXPORTS
        /* We are building this library */
#      define VTKIOVERAOUT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOVERAOUT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOVERAOUT_NO_EXPORT
#    define VTKIOVERAOUT_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOVERAOUT_DEPRECATED
#  define VTKIOVERAOUT_DEPRECATED __declspec(deprecated)
#  define VTKIOVERAOUT_DEPRECATED_EXPORT VTKIOVERAOUT_EXPORT __declspec(deprecated)
#  define VTKIOVERAOUT_DEPRECATED_NO_EXPORT VTKIOVERAOUT_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOVERAOUT_NO_DEPRECATED
#endif



#endif
