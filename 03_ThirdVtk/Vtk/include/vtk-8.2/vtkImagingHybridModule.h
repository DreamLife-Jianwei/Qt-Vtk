
#ifndef VTKIMAGINGHYBRID_EXPORT_H
#define VTKIMAGINGHYBRID_EXPORT_H

#ifdef VTKIMAGINGHYBRID_STATIC_DEFINE
#  define VTKIMAGINGHYBRID_EXPORT
#  define VTKIMAGINGHYBRID_NO_EXPORT
#else
#  ifndef VTKIMAGINGHYBRID_EXPORT
#    ifdef vtkImagingHybrid_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGHYBRID_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGHYBRID_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGHYBRID_NO_EXPORT
#    define VTKIMAGINGHYBRID_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGHYBRID_DEPRECATED
#  define VTKIMAGINGHYBRID_DEPRECATED __declspec(deprecated)
#  define VTKIMAGINGHYBRID_DEPRECATED_EXPORT VTKIMAGINGHYBRID_EXPORT __declspec(deprecated)
#  define VTKIMAGINGHYBRID_DEPRECATED_NO_EXPORT VTKIMAGINGHYBRID_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIMAGINGHYBRID_NO_DEPRECATED
#endif



#endif
