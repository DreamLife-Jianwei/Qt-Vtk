
#ifndef VTKIMAGINGCORE_EXPORT_H
#define VTKIMAGINGCORE_EXPORT_H

#ifdef VTKIMAGINGCORE_STATIC_DEFINE
#  define VTKIMAGINGCORE_EXPORT
#  define VTKIMAGINGCORE_NO_EXPORT
#else
#  ifndef VTKIMAGINGCORE_EXPORT
#    ifdef vtkImagingCore_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGCORE_NO_EXPORT
#    define VTKIMAGINGCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGCORE_DEPRECATED
#  define VTKIMAGINGCORE_DEPRECATED __declspec(deprecated)
#  define VTKIMAGINGCORE_DEPRECATED_EXPORT VTKIMAGINGCORE_EXPORT __declspec(deprecated)
#  define VTKIMAGINGCORE_DEPRECATED_NO_EXPORT VTKIMAGINGCORE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIMAGINGCORE_NO_DEPRECATED
#endif



#endif
