
#ifndef VTKIOLSDYNA_EXPORT_H
#define VTKIOLSDYNA_EXPORT_H

#ifdef VTKIOLSDYNA_STATIC_DEFINE
#  define VTKIOLSDYNA_EXPORT
#  define VTKIOLSDYNA_NO_EXPORT
#else
#  ifndef VTKIOLSDYNA_EXPORT
#    ifdef vtkIOLSDyna_EXPORTS
        /* We are building this library */
#      define VTKIOLSDYNA_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOLSDYNA_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOLSDYNA_NO_EXPORT
#    define VTKIOLSDYNA_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOLSDYNA_DEPRECATED
#  define VTKIOLSDYNA_DEPRECATED __declspec(deprecated)
#  define VTKIOLSDYNA_DEPRECATED_EXPORT VTKIOLSDYNA_EXPORT __declspec(deprecated)
#  define VTKIOLSDYNA_DEPRECATED_NO_EXPORT VTKIOLSDYNA_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOLSDYNA_NO_DEPRECATED
#endif



#endif
