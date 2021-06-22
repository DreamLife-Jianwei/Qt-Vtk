
#ifndef VTKIOVIDEO_EXPORT_H
#define VTKIOVIDEO_EXPORT_H

#ifdef VTKIOVIDEO_STATIC_DEFINE
#  define VTKIOVIDEO_EXPORT
#  define VTKIOVIDEO_NO_EXPORT
#else
#  ifndef VTKIOVIDEO_EXPORT
#    ifdef vtkIOVideo_EXPORTS
        /* We are building this library */
#      define VTKIOVIDEO_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOVIDEO_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOVIDEO_NO_EXPORT
#    define VTKIOVIDEO_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOVIDEO_DEPRECATED
#  define VTKIOVIDEO_DEPRECATED __declspec(deprecated)
#  define VTKIOVIDEO_DEPRECATED_EXPORT VTKIOVIDEO_EXPORT __declspec(deprecated)
#  define VTKIOVIDEO_DEPRECATED_NO_EXPORT VTKIOVIDEO_NO_EXPORT __declspec(deprecated)
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define VTKIOVIDEO_NO_DEPRECATED
#endif



#endif
