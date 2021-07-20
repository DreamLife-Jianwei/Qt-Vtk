
#ifndef ITKOptimizers_EXPORT_H
#define ITKOptimizers_EXPORT_H

#ifdef ITK_STATIC
#  define ITKOptimizers_EXPORT
#  define ITKOptimizers_HIDDEN
#else
#  ifndef ITKOptimizers_EXPORT
#    ifdef ITKOptimizers_EXPORTS
        /* We are building this library */
#      define ITKOptimizers_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKOptimizers_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKOptimizers_HIDDEN
#    define ITKOptimizers_HIDDEN 
#  endif
#endif

#ifndef ITKOPTIMIZERS_DEPRECATED
#  define ITKOPTIMIZERS_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKOPTIMIZERS_DEPRECATED_EXPORT
#  define ITKOPTIMIZERS_DEPRECATED_EXPORT ITKOptimizers_EXPORT ITKOPTIMIZERS_DEPRECATED
#endif

#ifndef ITKOPTIMIZERS_DEPRECATED_NO_EXPORT
#  define ITKOPTIMIZERS_DEPRECATED_NO_EXPORT ITKOptimizers_HIDDEN ITKOPTIMIZERS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKOPTIMIZERS_NO_DEPRECATED
#    define ITKOPTIMIZERS_NO_DEPRECATED
#  endif
#endif

#endif /* ITKOptimizers_EXPORT_H */
