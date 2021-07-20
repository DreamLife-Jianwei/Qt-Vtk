
#ifndef ITKIOJPEG_EXPORT_H
#define ITKIOJPEG_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOJPEG_EXPORT
#  define ITKIOJPEG_HIDDEN
#else
#  ifndef ITKIOJPEG_EXPORT
#    ifdef ITKIOJPEG_EXPORTS
        /* We are building this library */
#      define ITKIOJPEG_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOJPEG_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOJPEG_HIDDEN
#    define ITKIOJPEG_HIDDEN 
#  endif
#endif

#ifndef ITKIOJPEG_DEPRECATED
#  define ITKIOJPEG_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOJPEG_DEPRECATED_EXPORT
#  define ITKIOJPEG_DEPRECATED_EXPORT ITKIOJPEG_EXPORT ITKIOJPEG_DEPRECATED
#endif

#ifndef ITKIOJPEG_DEPRECATED_NO_EXPORT
#  define ITKIOJPEG_DEPRECATED_NO_EXPORT ITKIOJPEG_HIDDEN ITKIOJPEG_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOJPEG_NO_DEPRECATED
#    define ITKIOJPEG_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOJPEG_EXPORT_H */
