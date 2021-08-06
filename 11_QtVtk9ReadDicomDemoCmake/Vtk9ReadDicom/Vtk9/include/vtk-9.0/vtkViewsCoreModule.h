
#ifndef VTKVIEWSCORE_EXPORT_H
#define VTKVIEWSCORE_EXPORT_H

#ifdef VTKVIEWSCORE_STATIC_DEFINE
#  define VTKVIEWSCORE_EXPORT
#  define VTKVIEWSCORE_NO_EXPORT
#else
#  ifndef VTKVIEWSCORE_EXPORT
#    ifdef ViewsCore_EXPORTS
        /* We are building this library */
#      define VTKVIEWSCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKVIEWSCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKVIEWSCORE_NO_EXPORT
#    define VTKVIEWSCORE_NO_EXPORT 
#  endif
#endif

#ifndef VTKVIEWSCORE_DEPRECATED
#  define VTKVIEWSCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKVIEWSCORE_DEPRECATED_EXPORT
#  define VTKVIEWSCORE_DEPRECATED_EXPORT VTKVIEWSCORE_EXPORT VTKVIEWSCORE_DEPRECATED
#endif

#ifndef VTKVIEWSCORE_DEPRECATED_NO_EXPORT
#  define VTKVIEWSCORE_DEPRECATED_NO_EXPORT VTKVIEWSCORE_NO_EXPORT VTKVIEWSCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKVIEWSCORE_NO_DEPRECATED
#    define VTKVIEWSCORE_NO_DEPRECATED
#  endif
#endif

#endif /* VTKVIEWSCORE_EXPORT_H */
