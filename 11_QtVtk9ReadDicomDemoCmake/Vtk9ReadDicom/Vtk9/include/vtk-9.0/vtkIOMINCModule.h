
#ifndef VTKIOMINC_EXPORT_H
#define VTKIOMINC_EXPORT_H

#ifdef VTKIOMINC_STATIC_DEFINE
#  define VTKIOMINC_EXPORT
#  define VTKIOMINC_NO_EXPORT
#else
#  ifndef VTKIOMINC_EXPORT
#    ifdef IOMINC_EXPORTS
        /* We are building this library */
#      define VTKIOMINC_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOMINC_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOMINC_NO_EXPORT
#    define VTKIOMINC_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOMINC_DEPRECATED
#  define VTKIOMINC_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOMINC_DEPRECATED_EXPORT
#  define VTKIOMINC_DEPRECATED_EXPORT VTKIOMINC_EXPORT VTKIOMINC_DEPRECATED
#endif

#ifndef VTKIOMINC_DEPRECATED_NO_EXPORT
#  define VTKIOMINC_DEPRECATED_NO_EXPORT VTKIOMINC_NO_EXPORT VTKIOMINC_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOMINC_NO_DEPRECATED
#    define VTKIOMINC_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOMINC_EXPORT_H */
