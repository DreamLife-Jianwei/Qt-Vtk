
#ifndef VTKIMAGINGSTENCIL_EXPORT_H
#define VTKIMAGINGSTENCIL_EXPORT_H

#ifdef VTKIMAGINGSTENCIL_STATIC_DEFINE
#  define VTKIMAGINGSTENCIL_EXPORT
#  define VTKIMAGINGSTENCIL_NO_EXPORT
#else
#  ifndef VTKIMAGINGSTENCIL_EXPORT
#    ifdef vtkImagingStencil_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGSTENCIL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGSTENCIL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGSTENCIL_NO_EXPORT
#    define VTKIMAGINGSTENCIL_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGSTENCIL_DEPRECATED
#  define VTKIMAGINGSTENCIL_DEPRECATED __declspec(deprecated)
#  define VTKIMAGINGSTENCIL_DEPRECATED_EXPORT VTKIMAGINGSTENCIL_EXPORT __declspec(deprecated)
#  define VTKIMAGINGSTENCIL_DEPRECATED_NO_EXPORT VTKIMAGINGSTENCIL_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIMAGINGSTENCIL_NO_DEPRECATED
#endif



#endif
