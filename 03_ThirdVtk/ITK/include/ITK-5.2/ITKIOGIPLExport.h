
#ifndef ITKIOGIPL_EXPORT_H
#define ITKIOGIPL_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOGIPL_EXPORT
#  define ITKIOGIPL_HIDDEN
#else
#  ifndef ITKIOGIPL_EXPORT
#    ifdef ITKIOGIPL_EXPORTS
        /* We are building this library */
#      define ITKIOGIPL_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOGIPL_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOGIPL_HIDDEN
#    define ITKIOGIPL_HIDDEN 
#  endif
#endif

#ifndef ITKIOGIPL_DEPRECATED
#  define ITKIOGIPL_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOGIPL_DEPRECATED_EXPORT
#  define ITKIOGIPL_DEPRECATED_EXPORT ITKIOGIPL_EXPORT ITKIOGIPL_DEPRECATED
#endif

#ifndef ITKIOGIPL_DEPRECATED_NO_EXPORT
#  define ITKIOGIPL_DEPRECATED_NO_EXPORT ITKIOGIPL_HIDDEN ITKIOGIPL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOGIPL_NO_DEPRECATED
#    define ITKIOGIPL_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOGIPL_EXPORT_H */
