
#ifndef VTKIOLEGACY_EXPORT_H
#define VTKIOLEGACY_EXPORT_H

#ifdef VTKIOLEGACY_STATIC_DEFINE
#  define VTKIOLEGACY_EXPORT
#  define VTKIOLEGACY_NO_EXPORT
#else
#  ifndef VTKIOLEGACY_EXPORT
#    ifdef vtkIOLegacy_EXPORTS
        /* We are building this library */
#      define VTKIOLEGACY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOLEGACY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOLEGACY_NO_EXPORT
#    define VTKIOLEGACY_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOLEGACY_DEPRECATED
#  define VTKIOLEGACY_DEPRECATED __declspec(deprecated)
#  define VTKIOLEGACY_DEPRECATED_EXPORT VTKIOLEGACY_EXPORT __declspec(deprecated)
#  define VTKIOLEGACY_DEPRECATED_NO_EXPORT VTKIOLEGACY_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOLEGACY_NO_DEPRECATED
#endif



#endif
