
#ifndef VTKIOCORE_EXPORT_H
#define VTKIOCORE_EXPORT_H

#ifdef VTKIOCORE_STATIC_DEFINE
#  define VTKIOCORE_EXPORT
#  define VTKIOCORE_NO_EXPORT
#else
#  ifndef VTKIOCORE_EXPORT
#    ifdef vtkIOCore_EXPORTS
        /* We are building this library */
#      define VTKIOCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOCORE_NO_EXPORT
#    define VTKIOCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOCORE_DEPRECATED
#  define VTKIOCORE_DEPRECATED __declspec(deprecated)
#  define VTKIOCORE_DEPRECATED_EXPORT VTKIOCORE_EXPORT __declspec(deprecated)
#  define VTKIOCORE_DEPRECATED_NO_EXPORT VTKIOCORE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOCORE_NO_DEPRECATED
#endif



#endif
