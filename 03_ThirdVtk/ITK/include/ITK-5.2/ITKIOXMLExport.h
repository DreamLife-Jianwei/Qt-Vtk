
#ifndef ITKIOXML_EXPORT_H
#define ITKIOXML_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOXML_EXPORT
#  define ITKIOXML_HIDDEN
#else
#  ifndef ITKIOXML_EXPORT
#    ifdef ITKIOXML_EXPORTS
        /* We are building this library */
#      define ITKIOXML_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOXML_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOXML_HIDDEN
#    define ITKIOXML_HIDDEN 
#  endif
#endif

#ifndef ITKIOXML_DEPRECATED
#  define ITKIOXML_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOXML_DEPRECATED_EXPORT
#  define ITKIOXML_DEPRECATED_EXPORT ITKIOXML_EXPORT ITKIOXML_DEPRECATED
#endif

#ifndef ITKIOXML_DEPRECATED_NO_EXPORT
#  define ITKIOXML_DEPRECATED_NO_EXPORT ITKIOXML_HIDDEN ITKIOXML_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOXML_NO_DEPRECATED
#    define ITKIOXML_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOXML_EXPORT_H */
