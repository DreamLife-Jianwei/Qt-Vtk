
#ifndef ITKIOTIFF_EXPORT_H
#define ITKIOTIFF_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOTIFF_EXPORT
#  define ITKIOTIFF_HIDDEN
#else
#  ifndef ITKIOTIFF_EXPORT
#    ifdef ITKIOTIFF_EXPORTS
        /* We are building this library */
#      define ITKIOTIFF_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOTIFF_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOTIFF_HIDDEN
#    define ITKIOTIFF_HIDDEN 
#  endif
#endif

#ifndef ITKIOTIFF_DEPRECATED
#  define ITKIOTIFF_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOTIFF_DEPRECATED_EXPORT
#  define ITKIOTIFF_DEPRECATED_EXPORT ITKIOTIFF_EXPORT ITKIOTIFF_DEPRECATED
#endif

#ifndef ITKIOTIFF_DEPRECATED_NO_EXPORT
#  define ITKIOTIFF_DEPRECATED_NO_EXPORT ITKIOTIFF_HIDDEN ITKIOTIFF_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOTIFF_NO_DEPRECATED
#    define ITKIOTIFF_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOTIFF_EXPORT_H */
