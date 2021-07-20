
#ifndef ITKIOMeshGifti_EXPORT_H
#define ITKIOMeshGifti_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMeshGifti_EXPORT
#  define ITKIOMeshGifti_HIDDEN
#else
#  ifndef ITKIOMeshGifti_EXPORT
#    ifdef ITKIOMeshGifti_EXPORTS
        /* We are building this library */
#      define ITKIOMeshGifti_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMeshGifti_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMeshGifti_HIDDEN
#    define ITKIOMeshGifti_HIDDEN 
#  endif
#endif

#ifndef ITKIOMESHGIFTI_DEPRECATED
#  define ITKIOMESHGIFTI_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMESHGIFTI_DEPRECATED_EXPORT
#  define ITKIOMESHGIFTI_DEPRECATED_EXPORT ITKIOMeshGifti_EXPORT ITKIOMESHGIFTI_DEPRECATED
#endif

#ifndef ITKIOMESHGIFTI_DEPRECATED_NO_EXPORT
#  define ITKIOMESHGIFTI_DEPRECATED_NO_EXPORT ITKIOMeshGifti_HIDDEN ITKIOMESHGIFTI_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMESHGIFTI_NO_DEPRECATED
#    define ITKIOMESHGIFTI_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMeshGifti_EXPORT_H */
