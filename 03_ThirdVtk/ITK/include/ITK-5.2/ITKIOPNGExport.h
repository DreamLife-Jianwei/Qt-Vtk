
#ifndef ITKIOPNG_EXPORT_H
#define ITKIOPNG_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOPNG_EXPORT
#  define ITKIOPNG_HIDDEN
#else
#  ifndef ITKIOPNG_EXPORT
#    ifdef ITKIOPNG_EXPORTS
        /* We are building this library */
#      define ITKIOPNG_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOPNG_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOPNG_HIDDEN
#    define ITKIOPNG_HIDDEN 
#  endif
#endif

#ifndef ITKIOPNG_DEPRECATED
#  define ITKIOPNG_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOPNG_DEPRECATED_EXPORT
#  define ITKIOPNG_DEPRECATED_EXPORT ITKIOPNG_EXPORT ITKIOPNG_DEPRECATED
#endif

#ifndef ITKIOPNG_DEPRECATED_NO_EXPORT
#  define ITKIOPNG_DEPRECATED_NO_EXPORT ITKIOPNG_HIDDEN ITKIOPNG_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOPNG_NO_DEPRECATED
#    define ITKIOPNG_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOPNG_EXPORT_H */
