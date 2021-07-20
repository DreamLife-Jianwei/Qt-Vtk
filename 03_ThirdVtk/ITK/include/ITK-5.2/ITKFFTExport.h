
#ifndef ITKFFT_EXPORT_H
#define ITKFFT_EXPORT_H

#ifdef ITK_STATIC
#  define ITKFFT_EXPORT
#  define ITKFFT_HIDDEN
#else
#  ifndef ITKFFT_EXPORT
#    ifdef ITKFFT_EXPORTS
        /* We are building this library */
#      define ITKFFT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKFFT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKFFT_HIDDEN
#    define ITKFFT_HIDDEN 
#  endif
#endif

#ifndef ITKFFT_DEPRECATED
#  define ITKFFT_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKFFT_DEPRECATED_EXPORT
#  define ITKFFT_DEPRECATED_EXPORT ITKFFT_EXPORT ITKFFT_DEPRECATED
#endif

#ifndef ITKFFT_DEPRECATED_NO_EXPORT
#  define ITKFFT_DEPRECATED_NO_EXPORT ITKFFT_HIDDEN ITKFFT_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKFFT_NO_DEPRECATED
#    define ITKFFT_NO_DEPRECATED
#  endif
#endif

#endif /* ITKFFT_EXPORT_H */
