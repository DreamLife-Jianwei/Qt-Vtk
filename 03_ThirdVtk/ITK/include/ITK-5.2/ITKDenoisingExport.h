
#ifndef ITKDenoising_EXPORT_H
#define ITKDenoising_EXPORT_H

#ifdef ITK_STATIC
#  define ITKDenoising_EXPORT
#  define ITKDenoising_HIDDEN
#else
#  ifndef ITKDenoising_EXPORT
#    ifdef ITKDenoising_EXPORTS
        /* We are building this library */
#      define ITKDenoising_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKDenoising_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKDenoising_HIDDEN
#    define ITKDenoising_HIDDEN 
#  endif
#endif

#ifndef ITKDENOISING_DEPRECATED
#  define ITKDENOISING_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKDENOISING_DEPRECATED_EXPORT
#  define ITKDENOISING_DEPRECATED_EXPORT ITKDenoising_EXPORT ITKDENOISING_DEPRECATED
#endif

#ifndef ITKDENOISING_DEPRECATED_NO_EXPORT
#  define ITKDENOISING_DEPRECATED_NO_EXPORT ITKDenoising_HIDDEN ITKDENOISING_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKDENOISING_NO_DEPRECATED
#    define ITKDENOISING_NO_DEPRECATED
#  endif
#endif

#endif /* ITKDenoising_EXPORT_H */
