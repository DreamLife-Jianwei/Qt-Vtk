
#ifndef ITKOptimizersv4_EXPORT_H
#define ITKOptimizersv4_EXPORT_H

#ifdef ITK_STATIC
#  define ITKOptimizersv4_EXPORT
#  define ITKOptimizersv4_HIDDEN
#else
#  ifndef ITKOptimizersv4_EXPORT
#    ifdef ITKOptimizersv4_EXPORTS
        /* We are building this library */
#      define ITKOptimizersv4_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKOptimizersv4_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKOptimizersv4_HIDDEN
#    define ITKOptimizersv4_HIDDEN 
#  endif
#endif

#ifndef ITKOPTIMIZERSV4_DEPRECATED
#  define ITKOPTIMIZERSV4_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKOPTIMIZERSV4_DEPRECATED_EXPORT
#  define ITKOPTIMIZERSV4_DEPRECATED_EXPORT ITKOptimizersv4_EXPORT ITKOPTIMIZERSV4_DEPRECATED
#endif

#ifndef ITKOPTIMIZERSV4_DEPRECATED_NO_EXPORT
#  define ITKOPTIMIZERSV4_DEPRECATED_NO_EXPORT ITKOptimizersv4_HIDDEN ITKOPTIMIZERSV4_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKOPTIMIZERSV4_NO_DEPRECATED
#    define ITKOPTIMIZERSV4_NO_DEPRECATED
#  endif
#endif

#endif /* ITKOptimizersv4_EXPORT_H */
