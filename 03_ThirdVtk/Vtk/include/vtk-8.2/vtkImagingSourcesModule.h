
#ifndef VTKIMAGINGSOURCES_EXPORT_H
#define VTKIMAGINGSOURCES_EXPORT_H

#ifdef VTKIMAGINGSOURCES_STATIC_DEFINE
#  define VTKIMAGINGSOURCES_EXPORT
#  define VTKIMAGINGSOURCES_NO_EXPORT
#else
#  ifndef VTKIMAGINGSOURCES_EXPORT
#    ifdef vtkImagingSources_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGSOURCES_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGSOURCES_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGSOURCES_NO_EXPORT
#    define VTKIMAGINGSOURCES_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGSOURCES_DEPRECATED
#  define VTKIMAGINGSOURCES_DEPRECATED __declspec(deprecated)
#  define VTKIMAGINGSOURCES_DEPRECATED_EXPORT VTKIMAGINGSOURCES_EXPORT __declspec(deprecated)
#  define VTKIMAGINGSOURCES_DEPRECATED_NO_EXPORT VTKIMAGINGSOURCES_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIMAGINGSOURCES_NO_DEPRECATED
#endif



#endif
