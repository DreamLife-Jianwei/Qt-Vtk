
#ifndef ITKIOVTK_EXPORT_H
#define ITKIOVTK_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOVTK_EXPORT
#  define ITKIOVTK_HIDDEN
#else
#  ifndef ITKIOVTK_EXPORT
#    ifdef ITKIOVTK_EXPORTS
        /* We are building this library */
#      define ITKIOVTK_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOVTK_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOVTK_HIDDEN
#    define ITKIOVTK_HIDDEN 
#  endif
#endif

#ifndef ITKIOVTK_DEPRECATED
#  define ITKIOVTK_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOVTK_DEPRECATED_EXPORT
#  define ITKIOVTK_DEPRECATED_EXPORT ITKIOVTK_EXPORT ITKIOVTK_DEPRECATED
#endif

#ifndef ITKIOVTK_DEPRECATED_NO_EXPORT
#  define ITKIOVTK_DEPRECATED_NO_EXPORT ITKIOVTK_HIDDEN ITKIOVTK_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOVTK_NO_DEPRECATED
#    define ITKIOVTK_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOVTK_EXPORT_H */
