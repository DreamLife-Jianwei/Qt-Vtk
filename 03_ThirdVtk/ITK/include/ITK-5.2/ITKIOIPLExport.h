
#ifndef ITKIOIPL_EXPORT_H
#define ITKIOIPL_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOIPL_EXPORT
#  define ITKIOIPL_HIDDEN
#else
#  ifndef ITKIOIPL_EXPORT
#    ifdef ITKIOIPL_EXPORTS
        /* We are building this library */
#      define ITKIOIPL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOIPL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOIPL_HIDDEN
#    define ITKIOIPL_HIDDEN 
#  endif
#endif

#ifndef ITKIOIPL_DEPRECATED
#  define ITKIOIPL_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOIPL_DEPRECATED_EXPORT
#  define ITKIOIPL_DEPRECATED_EXPORT ITKIOIPL_EXPORT ITKIOIPL_DEPRECATED
#endif

#ifndef ITKIOIPL_DEPRECATED_NO_EXPORT
#  define ITKIOIPL_DEPRECATED_NO_EXPORT ITKIOIPL_HIDDEN ITKIOIPL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOIPL_NO_DEPRECATED
#    define ITKIOIPL_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOIPL_EXPORT_H */
