
#ifndef ITKVideoCore_EXPORT_H
#define ITKVideoCore_EXPORT_H

#ifdef ITK_STATIC
#  define ITKVideoCore_EXPORT
#  define ITKVideoCore_HIDDEN
#else
#  ifndef ITKVideoCore_EXPORT
#    ifdef ITKVideoCore_EXPORTS
        /* We are building this library */
#      define ITKVideoCore_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKVideoCore_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKVideoCore_HIDDEN
#    define ITKVideoCore_HIDDEN 
#  endif
#endif

#ifndef ITKVIDEOCORE_DEPRECATED
#  define ITKVIDEOCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKVIDEOCORE_DEPRECATED_EXPORT
#  define ITKVIDEOCORE_DEPRECATED_EXPORT ITKVideoCore_EXPORT ITKVIDEOCORE_DEPRECATED
#endif

#ifndef ITKVIDEOCORE_DEPRECATED_NO_EXPORT
#  define ITKVIDEOCORE_DEPRECATED_NO_EXPORT ITKVideoCore_HIDDEN ITKVIDEOCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKVIDEOCORE_NO_DEPRECATED
#    define ITKVIDEOCORE_NO_DEPRECATED
#  endif
#endif

#endif /* ITKVideoCore_EXPORT_H */
