
#ifndef ITKIOMeshBYU_EXPORT_H
#define ITKIOMeshBYU_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMeshBYU_EXPORT
#  define ITKIOMeshBYU_HIDDEN
#else
#  ifndef ITKIOMeshBYU_EXPORT
#    ifdef ITKIOMeshBYU_EXPORTS
        /* We are building this library */
#      define ITKIOMeshBYU_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMeshBYU_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMeshBYU_HIDDEN
#    define ITKIOMeshBYU_HIDDEN 
#  endif
#endif

#ifndef ITKIOMESHBYU_DEPRECATED
#  define ITKIOMESHBYU_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMESHBYU_DEPRECATED_EXPORT
#  define ITKIOMESHBYU_DEPRECATED_EXPORT ITKIOMeshBYU_EXPORT ITKIOMESHBYU_DEPRECATED
#endif

#ifndef ITKIOMESHBYU_DEPRECATED_NO_EXPORT
#  define ITKIOMESHBYU_DEPRECATED_NO_EXPORT ITKIOMeshBYU_HIDDEN ITKIOMESHBYU_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMESHBYU_NO_DEPRECATED
#    define ITKIOMESHBYU_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMeshBYU_EXPORT_H */
