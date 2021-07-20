
#ifndef ITKIOMeshFreeSurfer_EXPORT_H
#define ITKIOMeshFreeSurfer_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOMeshFreeSurfer_EXPORT
#  define ITKIOMeshFreeSurfer_HIDDEN
#else
#  ifndef ITKIOMeshFreeSurfer_EXPORT
#    ifdef ITKIOMeshFreeSurfer_EXPORTS
        /* We are building this library */
#      define ITKIOMeshFreeSurfer_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOMeshFreeSurfer_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOMeshFreeSurfer_HIDDEN
#    define ITKIOMeshFreeSurfer_HIDDEN 
#  endif
#endif

#ifndef ITKIOMESHFREESURFER_DEPRECATED
#  define ITKIOMESHFREESURFER_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOMESHFREESURFER_DEPRECATED_EXPORT
#  define ITKIOMESHFREESURFER_DEPRECATED_EXPORT ITKIOMeshFreeSurfer_EXPORT ITKIOMESHFREESURFER_DEPRECATED
#endif

#ifndef ITKIOMESHFREESURFER_DEPRECATED_NO_EXPORT
#  define ITKIOMESHFREESURFER_DEPRECATED_NO_EXPORT ITKIOMeshFreeSurfer_HIDDEN ITKIOMESHFREESURFER_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOMESHFREESURFER_NO_DEPRECATED
#    define ITKIOMESHFREESURFER_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOMeshFreeSurfer_EXPORT_H */
