
#ifndef ITKIOMeshOFF_EXPORT_H
#define ITKIOMeshOFF_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMeshOFF_EXPORT
#  define ITKIOMeshOFF_HIDDEN
#else
#  ifndef ITKIOMeshOFF_EXPORT
#    ifdef ITKIOMeshOFF_EXPORTS
        /* We are building this library */
#      define ITKIOMeshOFF_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMeshOFF_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMeshOFF_HIDDEN
#    define ITKIOMeshOFF_HIDDEN 
#  endif
#endif

#ifndef ITKIOMESHOFF_DEPRECATED
#  define ITKIOMESHOFF_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMESHOFF_DEPRECATED_EXPORT
#  define ITKIOMESHOFF_DEPRECATED_EXPORT ITKIOMeshOFF_EXPORT ITKIOMESHOFF_DEPRECATED
#endif

#ifndef ITKIOMESHOFF_DEPRECATED_NO_EXPORT
#  define ITKIOMESHOFF_DEPRECATED_NO_EXPORT ITKIOMeshOFF_HIDDEN ITKIOMESHOFF_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMESHOFF_NO_DEPRECATED
#    define ITKIOMESHOFF_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMeshOFF_EXPORT_H */
