
#ifndef VTKFILTERSTEXTURE_EXPORT_H
#define VTKFILTERSTEXTURE_EXPORT_H

#ifdef VTKFILTERSTEXTURE_STATIC_DEFINE
#  define VTKFILTERSTEXTURE_EXPORT
#  define VTKFILTERSTEXTURE_NO_EXPORT
#else
#  ifndef VTKFILTERSTEXTURE_EXPORT
#    ifdef vtkFiltersTexture_EXPORTS
        /* We are building this library */
#      define VTKFILTERSTEXTURE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSTEXTURE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSTEXTURE_NO_EXPORT
#    define VTKFILTERSTEXTURE_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSTEXTURE_DEPRECATED
#  define VTKFILTERSTEXTURE_DEPRECATED __declspec(deprecated)
#  define VTKFILTERSTEXTURE_DEPRECATED_EXPORT VTKFILTERSTEXTURE_EXPORT __declspec(deprecated)
#  define VTKFILTERSTEXTURE_DEPRECATED_NO_EXPORT VTKFILTERSTEXTURE_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKFILTERSTEXTURE_NO_DEPRECATED
#endif



#endif
