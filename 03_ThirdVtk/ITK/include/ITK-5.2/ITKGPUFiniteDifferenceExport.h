
#ifndef ITKGPUFiniteDifference_EXPORT_H
#define ITKGPUFiniteDifference_EXPORT_H

#ifdef ITK_STATIC
#  define ITKGPUFiniteDifference_EXPORT
#  define ITKGPUFiniteDifference_HIDDEN
#else
#  ifndef ITKGPUFiniteDifference_EXPORT
#    ifdef ITKGPUFiniteDifference_EXPORTS
        /* We are building this library */
#      define ITKGPUFiniteDifference_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKGPUFiniteDifference_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKGPUFiniteDifference_HIDDEN
#    define ITKGPUFiniteDifference_HIDDEN 
#  endif
#endif

#ifndef ITKGPUFINITEDIFFERENCE_DEPRECATED
#  define ITKGPUFINITEDIFFERENCE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKGPUFINITEDIFFERENCE_DEPRECATED_EXPORT
#  define ITKGPUFINITEDIFFERENCE_DEPRECATED_EXPORT ITKGPUFiniteDifference_EXPORT ITKGPUFINITEDIFFERENCE_DEPRECATED
#endif

#ifndef ITKGPUFINITEDIFFERENCE_DEPRECATED_NO_EXPORT
#  define ITKGPUFINITEDIFFERENCE_DEPRECATED_NO_EXPORT ITKGPUFiniteDifference_HIDDEN ITKGPUFINITEDIFFERENCE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKGPUFINITEDIFFERENCE_NO_DEPRECATED
#    define ITKGPUFINITEDIFFERENCE_NO_DEPRECATED
#  endif
#endif

#endif /* ITKGPUFiniteDifference_EXPORT_H */
