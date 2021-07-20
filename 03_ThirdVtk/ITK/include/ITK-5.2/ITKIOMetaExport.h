
#ifndef ITKIOMeta_EXPORT_H
#define ITKIOMeta_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMeta_EXPORT
#  define ITKIOMeta_HIDDEN
#else
#  ifndef ITKIOMeta_EXPORT
#    ifdef ITKIOMeta_EXPORTS
        /* We are building this library */
#      define ITKIOMeta_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMeta_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMeta_HIDDEN
#    define ITKIOMeta_HIDDEN 
#  endif
#endif

#ifndef ITKIOMETA_DEPRECATED
#  define ITKIOMETA_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMETA_DEPRECATED_EXPORT
#  define ITKIOMETA_DEPRECATED_EXPORT ITKIOMeta_EXPORT ITKIOMETA_DEPRECATED
#endif

#ifndef ITKIOMETA_DEPRECATED_NO_EXPORT
#  define ITKIOMETA_DEPRECATED_NO_EXPORT ITKIOMeta_HIDDEN ITKIOMETA_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMETA_NO_DEPRECATED
#    define ITKIOMETA_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMeta_EXPORT_H */
