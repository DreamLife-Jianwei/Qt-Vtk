
#ifndef VTKIOAMR_EXPORT_H
#define VTKIOAMR_EXPORT_H

#ifdef VTKIOAMR_STATIC_DEFINE
#  define VTKIOAMR_EXPORT
#  define VTKIOAMR_NO_EXPORT
#else
#  ifndef VTKIOAMR_EXPORT
#    ifdef IOAMR_EXPORTS
        /* We are building this library */
#      define VTKIOAMR_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOAMR_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOAMR_NO_EXPORT
#    define VTKIOAMR_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOAMR_DEPRECATED
#  define VTKIOAMR_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOAMR_DEPRECATED_EXPORT
#  define VTKIOAMR_DEPRECATED_EXPORT VTKIOAMR_EXPORT VTKIOAMR_DEPRECATED
#endif

#ifndef VTKIOAMR_DEPRECATED_NO_EXPORT
#  define VTKIOAMR_DEPRECATED_NO_EXPORT VTKIOAMR_NO_EXPORT VTKIOAMR_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOAMR_NO_DEPRECATED
#    define VTKIOAMR_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOAMR_EXPORT_H */
