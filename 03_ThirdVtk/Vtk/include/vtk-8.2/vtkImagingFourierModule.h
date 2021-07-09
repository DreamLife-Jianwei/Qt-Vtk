
#ifndef VTKIMAGINGFOURIER_EXPORT_H
#define VTKIMAGINGFOURIER_EXPORT_H

#ifdef VTKIMAGINGFOURIER_STATIC_DEFINE
#  define VTKIMAGINGFOURIER_EXPORT
#  define VTKIMAGINGFOURIER_NO_EXPORT
#else
#  ifndef VTKIMAGINGFOURIER_EXPORT
#    ifdef vtkImagingFourier_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGFOURIER_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGFOURIER_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGFOURIER_NO_EXPORT
#    define VTKIMAGINGFOURIER_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGFOURIER_DEPRECATED
#  define VTKIMAGINGFOURIER_DEPRECATED __declspec(deprecated)
#  define VTKIMAGINGFOURIER_DEPRECATED_EXPORT VTKIMAGINGFOURIER_EXPORT __declspec(deprecated)
#  define VTKIMAGINGFOURIER_DEPRECATED_NO_EXPORT VTKIMAGINGFOURIER_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIMAGINGFOURIER_NO_DEPRECATED
#endif



#endif
