
#ifndef VTKIMAGINGGENERAL_EXPORT_H
#define VTKIMAGINGGENERAL_EXPORT_H

#ifdef VTKIMAGINGGENERAL_STATIC_DEFINE
#  define VTKIMAGINGGENERAL_EXPORT
#  define VTKIMAGINGGENERAL_NO_EXPORT
#else
#  ifndef VTKIMAGINGGENERAL_EXPORT
#    ifdef vtkImagingGeneral_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGGENERAL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGGENERAL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGGENERAL_NO_EXPORT
#    define VTKIMAGINGGENERAL_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGGENERAL_DEPRECATED
#  define VTKIMAGINGGENERAL_DEPRECATED __declspec(deprecated)
#  define VTKIMAGINGGENERAL_DEPRECATED_EXPORT VTKIMAGINGGENERAL_EXPORT __declspec(deprecated)
#  define VTKIMAGINGGENERAL_DEPRECATED_NO_EXPORT VTKIMAGINGGENERAL_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIMAGINGGENERAL_NO_DEPRECATED
#endif



#endif
