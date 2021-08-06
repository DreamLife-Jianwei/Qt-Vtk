
#ifndef VTKIOLEGACY_EXPORT_H
#define VTKIOLEGACY_EXPORT_H

#ifdef VTKIOLEGACY_STATIC_DEFINE
#  define VTKIOLEGACY_EXPORT
#  define VTKIOLEGACY_NO_EXPORT
#else
#  ifndef VTKIOLEGACY_EXPORT
#    ifdef IOLegacy_EXPORTS
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
#endif

#ifndef VTKIOLEGACY_DEPRECATED_EXPORT
#  define VTKIOLEGACY_DEPRECATED_EXPORT VTKIOLEGACY_EXPORT VTKIOLEGACY_DEPRECATED
#endif

#ifndef VTKIOLEGACY_DEPRECATED_NO_EXPORT
#  define VTKIOLEGACY_DEPRECATED_NO_EXPORT VTKIOLEGACY_NO_EXPORT VTKIOLEGACY_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOLEGACY_NO_DEPRECATED
#    define VTKIOLEGACY_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOLEGACY_EXPORT_H */
