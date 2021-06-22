
#ifndef VTKIOPLY_EXPORT_H
#define VTKIOPLY_EXPORT_H

#ifdef VTKIOPLY_STATIC_DEFINE
#  define VTKIOPLY_EXPORT
#  define VTKIOPLY_NO_EXPORT
#else
#  ifndef VTKIOPLY_EXPORT
#    ifdef vtkIOPLY_EXPORTS
        /* We are building this library */
#      define VTKIOPLY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOPLY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOPLY_NO_EXPORT
#    define VTKIOPLY_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOPLY_DEPRECATED
#  define VTKIOPLY_DEPRECATED __declspec(deprecated)
#  define VTKIOPLY_DEPRECATED_EXPORT VTKIOPLY_EXPORT __declspec(deprecated)
#  define VTKIOPLY_DEPRECATED_NO_EXPORT VTKIOPLY_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOPLY_NO_DEPRECATED
#endif



#endif
