
#ifndef ITKFastMarching_EXPORT_H
#define ITKFastMarching_EXPORT_H

#ifdef ITK_STATIC
#  define ITKFastMarching_EXPORT
#  define ITKFastMarching_HIDDEN
#else
#  ifndef ITKFastMarching_EXPORT
#    ifdef ITKFastMarching_EXPORTS
        /* We are building this library */
#      define ITKFastMarching_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKFastMarching_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKFastMarching_HIDDEN
#    define ITKFastMarching_HIDDEN 
#  endif
#endif

#ifndef ITKFASTMARCHING_DEPRECATED
#  define ITKFASTMARCHING_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKFASTMARCHING_DEPRECATED_EXPORT
#  define ITKFASTMARCHING_DEPRECATED_EXPORT ITKFastMarching_EXPORT ITKFASTMARCHING_DEPRECATED
#endif

#ifndef ITKFASTMARCHING_DEPRECATED_NO_EXPORT
#  define ITKFASTMARCHING_DEPRECATED_NO_EXPORT ITKFastMarching_HIDDEN ITKFASTMARCHING_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKFASTMARCHING_NO_DEPRECATED
#    define ITKFASTMARCHING_NO_DEPRECATED
#  endif
#endif

#endif /* ITKFastMarching_EXPORT_H */
