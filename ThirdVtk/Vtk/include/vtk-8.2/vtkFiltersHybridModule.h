
#ifndef VTKFILTERSHYBRID_EXPORT_H
#define VTKFILTERSHYBRID_EXPORT_H

#ifdef VTKFILTERSHYBRID_STATIC_DEFINE
#  define VTKFILTERSHYBRID_EXPORT
#  define VTKFILTERSHYBRID_NO_EXPORT
#else
#  ifndef VTKFILTERSHYBRID_EXPORT
#    ifdef vtkFiltersHybrid_EXPORTS
        /* We are building this library */
#      define VTKFILTERSHYBRID_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSHYBRID_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSHYBRID_NO_EXPORT
#    define VTKFILTERSHYBRID_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSHYBRID_DEPRECATED
#  define VTKFILTERSHYBRID_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSHYBRID_DEPRECATED_EXPORT VTKFILTERSHYBRID_EXPORT __declspec(deprecated)
#  define VTKFILTERSHYBRID_DEPRECATED_NO_EXPORT VTKFILTERSHYBRID_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSHYBRID_NO_DEPRECATED
#endif



#endif
