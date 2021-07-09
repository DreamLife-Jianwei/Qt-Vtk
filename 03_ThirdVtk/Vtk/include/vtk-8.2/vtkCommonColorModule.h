
#ifndef VTKCOMMONCOLOR_EXPORT_H
#define VTKCOMMONCOLOR_EXPORT_H

#ifdef VTKCOMMONCOLOR_STATIC_DEFINE
#  define VTKCOMMONCOLOR_EXPORT
#  define VTKCOMMONCOLOR_NO_EXPORT
#else
#  ifndef VTKCOMMONCOLOR_EXPORT
#    ifdef vtkCommonColor_EXPORTS
        /* We are building this library */
#      define VTKCOMMONCOLOR_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKCOMMONCOLOR_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKCOMMONCOLOR_NO_EXPORT
#    define VTKCOMMONCOLOR_NO_EXPORT 
#  endif
#endif

#ifndef VTKCOMMONCOLOR_DEPRECATED
#  define VTKCOMMONCOLOR_DEPRECATED __declspec(deprecated)
#  define VTKCOMMONCOLOR_DEPRECATED_EXPORT VTKCOMMONCOLOR_EXPORT __declspec(deprecated)
#  define VTKCOMMONCOLOR_DEPRECATED_NO_EXPORT VTKCOMMONCOLOR_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKCOMMONCOLOR_NO_DEPRECATED
#endif



#endif
