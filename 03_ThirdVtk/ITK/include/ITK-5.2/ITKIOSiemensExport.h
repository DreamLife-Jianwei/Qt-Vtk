
#ifndef ITKIOSiemens_EXPORT_H
#define ITKIOSiemens_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOSiemens_EXPORT
#  define ITKIOSiemens_HIDDEN
#else
#  ifndef ITKIOSiemens_EXPORT
#    ifdef ITKIOSiemens_EXPORTS
        /* We are building this library */
#      define ITKIOSiemens_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOSiemens_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOSiemens_HIDDEN
#    define ITKIOSiemens_HIDDEN 
#  endif
#endif

#ifndef ITKIOSIEMENS_DEPRECATED
#  define ITKIOSIEMENS_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOSIEMENS_DEPRECATED_EXPORT
#  define ITKIOSIEMENS_DEPRECATED_EXPORT ITKIOSiemens_EXPORT ITKIOSIEMENS_DEPRECATED
#endif

#ifndef ITKIOSIEMENS_DEPRECATED_NO_EXPORT
#  define ITKIOSIEMENS_DEPRECATED_NO_EXPORT ITKIOSiemens_HIDDEN ITKIOSIEMENS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOSIEMENS_NO_DEPRECATED
#    define ITKIOSIEMENS_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOSiemens_EXPORT_H */
