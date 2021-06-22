
#ifndef VTKIOGEOMETRY_EXPORT_H
#define VTKIOGEOMETRY_EXPORT_H

#ifdef VTKIOGEOMETRY_STATIC_DEFINE
#  define VTKIOGEOMETRY_EXPORT
#  define VTKIOGEOMETRY_NO_EXPORT
#else
#  ifndef VTKIOGEOMETRY_EXPORT
#    ifdef vtkIOGeometry_EXPORTS
        /* We are building this library */
#      define VTKIOGEOMETRY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOGEOMETRY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOGEOMETRY_NO_EXPORT
#    define VTKIOGEOMETRY_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOGEOMETRY_DEPRECATED
#  define VTKIOGEOMETRY_DEPRECATED __declspec(deprecated)
#  define VTKIOGEOMETRY_DEPRECATED_EXPORT VTKIOGEOMETRY_EXPORT __declspec(deprecated)
#  define VTKIOGEOMETRY_DEPRECATED_NO_EXPORT VTKIOGEOMETRY_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOGEOMETRY_NO_DEPRECATED
#endif

/* AutoInit implementations.  */
#if defined(vtkIOGeometry_INCLUDE)
# include vtkIOGeometry_INCLUDE
#endif
#if defined(vtkIOGeometry_AUTOINIT)
# include "vtkAutoInit.h"
VTK_AUTOINIT(vtkIOGeometry)
#endif

#endif
