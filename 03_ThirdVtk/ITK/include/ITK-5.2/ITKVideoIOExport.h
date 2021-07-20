
#ifndef ITKVideoIO_EXPORT_H
#define ITKVideoIO_EXPORT_H

#ifdef ITK_STATIC
#  define ITKVideoIO_EXPORT
#  define ITKVideoIO_HIDDEN
#else
#  ifndef ITKVideoIO_EXPORT
#    ifdef ITKVideoIO_EXPORTS
        /* We are building this library */
#      define ITKVideoIO_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKVideoIO_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKVideoIO_HIDDEN
#    define ITKVideoIO_HIDDEN 
#  endif
#endif

#ifndef ITKVIDEOIO_DEPRECATED
#  define ITKVIDEOIO_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKVIDEOIO_DEPRECATED_EXPORT
#  define ITKVIDEOIO_DEPRECATED_EXPORT ITKVideoIO_EXPORT ITKVIDEOIO_DEPRECATED
#endif

#ifndef ITKVIDEOIO_DEPRECATED_NO_EXPORT
#  define ITKVIDEOIO_DEPRECATED_NO_EXPORT ITKVideoIO_HIDDEN ITKVIDEOIO_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKVIDEOIO_NO_DEPRECATED
#    define ITKVIDEOIO_NO_DEPRECATED
#  endif
#endif

#endif /* ITKVideoIO_EXPORT_H */
