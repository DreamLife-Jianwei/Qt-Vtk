
#ifndef ITKIOMINC_EXPORT_H
#define ITKIOMINC_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMINC_EXPORT
#  define ITKIOMINC_HIDDEN
#else
#  ifndef ITKIOMINC_EXPORT
#    ifdef ITKIOMINC_EXPORTS
        /* We are building this library */
#      define ITKIOMINC_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMINC_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMINC_HIDDEN
#    define ITKIOMINC_HIDDEN 
#  endif
#endif

#ifndef ITKIOMINC_DEPRECATED
#  define ITKIOMINC_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMINC_DEPRECATED_EXPORT
#  define ITKIOMINC_DEPRECATED_EXPORT ITKIOMINC_EXPORT ITKIOMINC_DEPRECATED
#endif

#ifndef ITKIOMINC_DEPRECATED_NO_EXPORT
#  define ITKIOMINC_DEPRECATED_NO_EXPORT ITKIOMINC_HIDDEN ITKIOMINC_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMINC_NO_DEPRECATED
#    define ITKIOMINC_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMINC_EXPORT_H */
