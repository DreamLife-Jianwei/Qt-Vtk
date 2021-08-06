
#ifndef VTKIOIMPORT_EXPORT_H
#define VTKIOIMPORT_EXPORT_H

#ifdef VTKIOIMPORT_STATIC_DEFINE
#  define VTKIOIMPORT_EXPORT
#  define VTKIOIMPORT_NO_EXPORT
#else
#  ifndef VTKIOIMPORT_EXPORT
#    ifdef IOImport_EXPORTS
        /* We are building this library */
#      define VTKIOIMPORT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOIMPORT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOIMPORT_NO_EXPORT
#    define VTKIOIMPORT_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOIMPORT_DEPRECATED
#  define VTKIOIMPORT_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOIMPORT_DEPRECATED_EXPORT
#  define VTKIOIMPORT_DEPRECATED_EXPORT VTKIOIMPORT_EXPORT VTKIOIMPORT_DEPRECATED
#endif

#ifndef VTKIOIMPORT_DEPRECATED_NO_EXPORT
#  define VTKIOIMPORT_DEPRECATED_NO_EXPORT VTKIOIMPORT_NO_EXPORT VTKIOIMPORT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOIMPORT_NO_DEPRECATED
#    define VTKIOIMPORT_NO_DEPRECATED
#  endif
#endif

#endif /* VTKIOIMPORT_EXPORT_H */
