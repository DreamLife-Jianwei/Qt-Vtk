
#ifndef VTKFILTERSGEOMETRY_EXPORT_H
#define VTKFILTERSGEOMETRY_EXPORT_H

#ifdef VTKFILTERSGEOMETRY_STATIC_DEFINE
#  define VTKFILTERSGEOMETRY_EXPORT
#  define VTKFILTERSGEOMETRY_NO_EXPORT
#else
#  ifndef VTKFILTERSGEOMETRY_EXPORT
#    ifdef vtkFiltersGeometry_EXPORTS
        /* We are building this library */
#      define VTKFILTERSGEOMETRY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSGEOMETRY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSGEOMETRY_NO_EXPORT
#    define VTKFILTERSGEOMETRY_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSGEOMETRY_DEPRECATED
#  define VTKFILTERSGEOMETRY_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSGEOMETRY_DEPRECATED_EXPORT VTKFILTERSGEOMETRY_EXPORT __declspec(deprecated)
#  define VTKFILTERSGEOMETRY_DEPRECATED_NO_EXPORT VTKFILTERSGEOMETRY_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSGEOMETRY_NO_DEPRECATED
#endif



#endif
