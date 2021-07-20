
#ifndef ITKConvolution_EXPORT_H
#define ITKConvolution_EXPORT_H

#ifdef ITK_STATIC
#  define ITKConvolution_EXPORT
#  define ITKConvolution_HIDDEN
#else
#  ifndef ITKConvolution_EXPORT
#    ifdef ITKConvolution_EXPORTS
        /* We are building this library */
#      define ITKConvolution_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKConvolution_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKConvolution_HIDDEN
#    define ITKConvolution_HIDDEN 
#  endif
#endif

#ifndef ITKCONVOLUTION_DEPRECATED
#  define ITKCONVOLUTION_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKCONVOLUTION_DEPRECATED_EXPORT
#  define ITKCONVOLUTION_DEPRECATED_EXPORT ITKConvolution_EXPORT ITKCONVOLUTION_DEPRECATED
#endif

#ifndef ITKCONVOLUTION_DEPRECATED_NO_EXPORT
#  define ITKCONVOLUTION_DEPRECATED_NO_EXPORT ITKConvolution_HIDDEN ITKCONVOLUTION_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKCONVOLUTION_NO_DEPRECATED
#    define ITKCONVOLUTION_NO_DEPRECATED
#  endif
#endif

#endif /* ITKConvolution_EXPORT_H */
